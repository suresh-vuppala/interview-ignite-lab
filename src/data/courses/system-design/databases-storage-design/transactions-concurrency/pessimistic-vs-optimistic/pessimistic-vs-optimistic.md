When multiple transactions access the same data concurrently, conflicts can arise. Concurrency control mechanisms ensure data consistency while maximizing throughput. Two fundamental approaches exist: pessimistic and optimistic locking.

## Pessimistic Concurrency Control

Pessimistic locking assumes conflicts are likely and prevents them by acquiring locks before accessing data.

### How It Works

```
Transaction T1:
1. BEGIN TRANSACTION
2. SELECT * FROM accounts WHERE id = 123 FOR UPDATE  -- Acquires lock
3. UPDATE accounts SET balance = balance - 100 WHERE id = 123
4. COMMIT  -- Releases lock

Transaction T2 (concurrent):
1. BEGIN TRANSACTION
2. SELECT * FROM accounts WHERE id = 123 FOR UPDATE  -- Blocks until T1 commits
3. ... waits ...
```

The second transaction blocks until the first releases the lock.

### Lock Types

**Shared Lock (Read Lock)**
- Multiple transactions can hold shared locks simultaneously
- Allows concurrent reads
- Blocks write operations

```sql
SELECT * FROM orders WHERE id = 456 LOCK IN SHARE MODE;
```

**Exclusive Lock (Write Lock)**
- Only one transaction can hold an exclusive lock
- Blocks both reads and writes from other transactions
- Acquired during UPDATE, DELETE, INSERT

```sql
SELECT * FROM inventory WHERE product_id = 789 FOR UPDATE;
```

**Intent Locks**
- Indicate intention to acquire locks at finer granularity
- Prevent conflicts between table-level and row-level locks
- Types: Intent Shared (IS), Intent Exclusive (IX)

### Lock Granularity

**Row-Level Locks**
- Lock individual rows
- High concurrency, more overhead
- Default in PostgreSQL, MySQL InnoDB

**Page-Level Locks**
- Lock database pages (typically 8KB)
- Balance between concurrency and overhead

**Table-Level Locks**
- Lock entire table
- Low concurrency, minimal overhead
- Used for DDL operations (ALTER TABLE, DROP TABLE)

### Deadlock Example

```
Time    Transaction T1                  Transaction T2
----    --------------                  --------------
t1      BEGIN                           BEGIN
t2      UPDATE accounts SET             
        balance = 1000 WHERE id = 1     
        (locks row 1)
t3                                      UPDATE accounts SET
                                        balance = 2000 WHERE id = 2
                                        (locks row 2)
t4      UPDATE accounts SET             
        balance = 1500 WHERE id = 2     
        (waits for row 2)
t5                                      UPDATE accounts SET
                                        balance = 2500 WHERE id = 1
                                        (waits for row 1)
        
        ⚠️ DEADLOCK DETECTED
```

Both transactions wait for each other indefinitely. Database detects this and aborts one transaction.

### Deadlock Prevention Strategies

**1. Lock Ordering**
```python
# Always acquire locks in consistent order
def transfer(from_id, to_id, amount):
    # Sort IDs to ensure consistent lock order
    first_id, second_id = sorted([from_id, to_id])
    
    lock_account(first_id)
    lock_account(second_id)
    # perform transfer
    release_locks()
```

**2. Lock Timeout**
```sql
SET innodb_lock_wait_timeout = 5;  -- Wait max 5 seconds for lock
```

**3. Deadlock Detection**
- Database maintains wait-for graph
- Detects cycles indicating deadlock
- Aborts one transaction (victim selection based on age, priority)

## Optimistic Concurrency Control

Optimistic locking assumes conflicts are rare and detects them at commit time rather than preventing them upfront.

### Version Number Approach

```sql
-- Read phase: Record version
SELECT id, balance, version FROM accounts WHERE id = 123;
-- Returns: id=123, balance=1000, version=5

-- Compute new balance
new_balance = 1000 - 100  -- 900

-- Write phase: Check version hasn't changed
UPDATE accounts 
SET balance = 900, version = 6
WHERE id = 123 AND version = 5;

-- If affected rows = 0, version changed → conflict detected
```

**Application-Level Handling**
```python
def withdraw(account_id, amount):
    max_retries = 3
    for attempt in range(max_retries):
        # Read with version
        account = db.query(
            "SELECT balance, version FROM accounts WHERE id = ?",
            account_id
        )
        
        new_balance = account.balance - amount
        
        # Attempt update with version check
        rows_affected = db.execute(
            "UPDATE accounts SET balance = ?, version = version + 1 "
            "WHERE id = ? AND version = ?",
            new_balance, account_id, account.version
        )
        
        if rows_affected == 1:
            return True  # Success
        
        # Conflict detected, retry
        time.sleep(0.1 * (2 ** attempt))  # Exponential backoff
    
    raise ConflictError("Failed after retries")
```

### Timestamp Approach

Each transaction gets a timestamp. System tracks read and write timestamps for each data item.

```
Transaction T1 (timestamp = 100):
- Read X (X.read_ts = 100)
- Write X (X.write_ts = 100)

Transaction T2 (timestamp = 105):
- Read X (allowed if T2.ts > X.write_ts)
- Write X (allowed if T2.ts > X.read_ts and T2.ts > X.write_ts)
```

### Compare-and-Swap (CAS)

Atomic operation that updates value only if it matches expected value.

```python
# Redis example
def increment_counter(key):
    while True:
        # WATCH monitors key for changes
        redis.watch(key)
        current_value = int(redis.get(key) or 0)
        new_value = current_value + 1
        
        # MULTI starts transaction
        pipe = redis.pipeline()
        pipe.multi()
        pipe.set(key, new_value)
        
        try:
            pipe.execute()  # Succeeds only if key unchanged
            break
        except redis.WatchError:
            # Key was modified, retry
            continue
```

### ETags in HTTP APIs

```http
GET /api/users/123
Response:
{
  "id": 123,
  "name": "Alice",
  "email": "alice@example.com"
}
ETag: "v1-abc123"

PUT /api/users/123
If-Match: "v1-abc123"
{
  "name": "Alice Smith",
  "email": "alice@example.com"
}

Response (if ETag matches):
200 OK

Response (if ETag doesn't match):
412 Precondition Failed
{
  "error": "Resource was modified by another request"
}
```

## Comparison

| Aspect | Pessimistic | Optimistic |
|--------|-------------|------------|
| **Assumption** | Conflicts are common | Conflicts are rare |
| **Lock Timing** | Before access | No locks (version check at commit) |
| **Blocking** | Transactions wait for locks | No waiting, retry on conflict |
| **Deadlocks** | Possible | Not possible |
| **Throughput** | Lower (due to blocking) | Higher (no blocking) |
| **Latency** | Predictable | Variable (retries on conflict) |
| **Best For** | High contention workloads | Low contention workloads |
| **Overhead** | Lock management | Version tracking, retries |
| **Failure Mode** | Deadlock, timeout | Starvation (repeated conflicts) |

## When to Use Each

### Use Pessimistic Locking When:

**1. High Contention**
```python
# Inventory system with limited stock
def purchase_item(item_id, quantity):
    # Many users trying to buy same item
    db.execute("SELECT * FROM inventory WHERE id = ? FOR UPDATE", item_id)
    # Prevents overselling
```

**2. Long Transactions**
```python
# Complex multi-step operation
def process_order(order_id):
    # Lock early to prevent conflicts during long operation
    order = db.query("SELECT * FROM orders WHERE id = ? FOR UPDATE", order_id)
    validate_payment()
    update_inventory()
    send_notification()
    db.commit()
```

**3. Critical Consistency Requirements**
```python
# Banking transfer - cannot tolerate conflicts
def transfer(from_account, to_account, amount):
    # Lock both accounts to ensure atomicity
    db.execute("SELECT * FROM accounts WHERE id IN (?, ?) FOR UPDATE",
               from_account, to_account)
```

### Use Optimistic Locking When:

**1. Low Contention**
```python
# User profile updates (rarely concurrent)
def update_profile(user_id, new_data):
    user = db.query("SELECT *, version FROM users WHERE id = ?", user_id)
    db.execute(
        "UPDATE users SET name = ?, version = version + 1 "
        "WHERE id = ? AND version = ?",
        new_data.name, user_id, user.version
    )
```

**2. Read-Heavy Workloads**
```python
# Analytics dashboard (mostly reads, occasional writes)
def update_dashboard_config(config_id, settings):
    # Don't block readers with locks
    config = db.query("SELECT *, version FROM configs WHERE id = ?", config_id)
    db.execute(
        "UPDATE configs SET settings = ?, version = version + 1 "
        "WHERE id = ? AND version = ?",
        settings, config_id, config.version
    )
```

**3. Distributed Systems**
```python
# Microservices with eventual consistency
def update_user_across_services(user_id, data):
    # Each service checks version independently
    # No distributed locks needed
    user_service.update(user_id, data, version)
    profile_service.update(user_id, data, version)
```

**4. API Design**
```python
# RESTful APIs with ETags
@app.put('/api/documents/{id}')
def update_document(id, if_match_header):
    doc = get_document(id)
    if doc.etag != if_match_header:
        return 412  # Precondition Failed
    # Update document
```

## Hybrid Approaches

### Optimistic with Fallback to Pessimistic

```python
def update_with_retry(record_id, update_fn, max_retries=3):
    # Try optimistic first
    for attempt in range(max_retries):
        record = db.query("SELECT *, version FROM records WHERE id = ?", record_id)
        new_data = update_fn(record)
        
        rows = db.execute(
            "UPDATE records SET data = ?, version = version + 1 "
            "WHERE id = ? AND version = ?",
            new_data, record_id, record.version
        )
        
        if rows == 1:
            return True
    
    # Fall back to pessimistic after retries
    record = db.query("SELECT * FROM records WHERE id = ? FOR UPDATE", record_id)
    new_data = update_fn(record)
    db.execute("UPDATE records SET data = ? WHERE id = ?", new_data, record_id)
    return True
```

### Selective Locking

```python
def process_transaction(txn_id):
    # Read-only operations: no lock
    txn = db.query("SELECT * FROM transactions WHERE id = ?", txn_id)
    
    if txn.requires_inventory_update:
        # High contention: pessimistic lock
        inventory = db.query(
            "SELECT * FROM inventory WHERE id = ? FOR UPDATE",
            txn.inventory_id
        )
    else:
        # Low contention: optimistic
        inventory = db.query(
            "SELECT *, version FROM inventory WHERE id = ?",
            txn.inventory_id
        )
```

## Real-World Examples

### E-commerce Checkout

```python
# Pessimistic for inventory (high contention)
def reserve_inventory(product_id, quantity):
    product = db.query(
        "SELECT * FROM products WHERE id = ? FOR UPDATE",
        product_id
    )
    if product.stock >= quantity:
        db.execute(
            "UPDATE products SET stock = stock - ? WHERE id = ?",
            quantity, product_id
        )
        return True
    return False

# Optimistic for cart updates (low contention)
def update_cart(cart_id, items):
    cart = db.query("SELECT *, version FROM carts WHERE id = ?", cart_id)
    rows = db.execute(
        "UPDATE carts SET items = ?, version = version + 1 "
        "WHERE id = ? AND version = ?",
        items, cart_id, cart.version
    )
    return rows == 1
```

### Collaborative Document Editing

```python
# Optimistic with operational transformation
def apply_edit(doc_id, edit, client_version):
    doc = get_document(doc_id)
    
    if doc.version != client_version:
        # Transform edit based on concurrent changes
        transformed_edit = transform(edit, doc.changes_since(client_version))
        edit = transformed_edit
    
    # Apply with version check
    success = db.execute(
        "UPDATE documents SET content = ?, version = version + 1 "
        "WHERE id = ? AND version = ?",
        apply(doc.content, edit), doc_id, doc.version
    )
    
    if not success:
        # Retry with latest version
        return apply_edit(doc_id, edit, get_document(doc_id).version)
```

### Distributed Cache (Redis)

```python
# Optimistic with WATCH/MULTI/EXEC
def increment_with_limit(key, max_value):
    while True:
        redis.watch(key)
        current = int(redis.get(key) or 0)
        
        if current >= max_value:
            redis.unwatch()
            return False
        
        pipe = redis.pipeline()
        pipe.multi()
        pipe.set(key, current + 1)
        
        try:
            pipe.execute()
            return True
        except redis.WatchError:
            continue  # Retry
```

## Performance Considerations

### Pessimistic Lock Overhead

```
Lock acquisition time: 0.1-1ms
Lock hold time: Transaction duration
Deadlock detection: 1-10ms
Context switches: High (blocking threads)

Throughput impact:
- 10 concurrent transactions with 100ms each
- Pessimistic: ~100 TPS (serialized)
- Optimistic: ~1000 TPS (parallel, 10% conflict rate)
```

### Optimistic Retry Cost

```
Conflict rate: 5%
Retry overhead: 1-5ms per retry
Max retries: 3

Expected latency:
- No conflict: 10ms
- 1 retry: 15ms
- 2 retries: 25ms
- 3 retries: 40ms

Average latency = 10ms * 0.95 + 15ms * 0.04 + 25ms * 0.008 + 40ms * 0.002
                ≈ 10.5ms
```

## Key Takeaways

1. **Pessimistic locking** prevents conflicts by acquiring locks early, suitable for high-contention scenarios
2. **Optimistic locking** detects conflicts at commit time using versions/timestamps, better for low-contention workloads
3. **Deadlocks** only occur with pessimistic locking; prevent with lock ordering and timeouts
4. **Version numbers** are the most common optimistic locking mechanism in applications
5. **Hybrid approaches** combine both strategies based on contention patterns
6. **Choose based on workload**: High contention → pessimistic, Low contention → optimistic
7. **Distributed systems** favor optimistic locking to avoid distributed lock coordination
8. **APIs** commonly use ETags for optimistic concurrency control
