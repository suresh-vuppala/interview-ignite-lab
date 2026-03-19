## Why API Design Comes First

The API design determines:
- **Performance characteristics** - Protocol overhead affects latency
- **Client complexity** - Simple APIs are easier to adopt
- **Feature capabilities** - What operations are possible
- **Consistency guarantees** - What promises we make to clients

## Protocol Selection

### Option 1: HTTP/REST

**Pros:**
- Universal support across all languages
- Easy debugging with standard tools
- Built-in caching headers and status codes
- Familiar to all developers

**Cons:**
- High overhead (~500 bytes per request in headers)
- Connection setup cost for each request
- Text-based parsing overhead
- Difficult to achieve sub-millisecond latency

**Verdict:** ❌ Rejected for high-performance cache

### Option 2: gRPC

**Pros:**
- Binary protocol with lower overhead than HTTP
- Strong typing with Protocol Buffers
- Streaming support for pub/sub
- Good tooling and code generation

**Cons:**
- Still has HTTP/2 framing overhead
- Protobuf serialization/deserialization cost
- More complex than simple binary protocols
- Overkill for simple key-value operations

**Verdict:** ⚠️ Consider for management APIs, not data path

### Option 3: Custom Binary Protocol (Redis RESP)

**Pros:**
- Minimal overhead (8-20 bytes per request)
- Persistent connections reduce setup cost
- Pipelining support for batching
- Simple to implement and debug

**Cons:**
- Custom protocol requires client libraries
- No built-in versioning or compatibility
- Limited tooling compared to HTTP

**Verdict:** ✅ Chosen for data operations

## Wire Protocol Design

### RESP (Redis Serialization Protocol) Inspired

We'll use a text-based protocol similar to Redis RESP for simplicity:

```
Request Format:
*<number-of-arguments>\r\n
$<length-of-argument-1>\r\n
<argument-1>\r\n
$<length-of-argument-2>\r\n
<argument-2>\r\n
...

Response Format:
+<simple-string>\r\n          // Success
-<error-message>\r\n          // Error  
:<integer>\r\n                // Integer
$<length>\r\n<data>\r\n       // Bulk string
*<count>\r\n...               // Array
```

### Example Protocol Exchange

```
Client Request (SET key value):
*3\r\n
$3\r\n
SET\r\n
$7\r\n
mykey\r\n
$8\r\n
myvalue\r\n

Server Response:
+OK\r\n

Client Request (GET key):
*2\r\n
$3\r\n
GET\r\n
$5\r\n
mykey\r\n

Server Response:
$8\r\n
myvalue\r\n
```

## Core API Commands

### String Operations

```
GET key
- Returns: value or nil
- Time Complexity: O(1)
- Use Case: Retrieve cached data

SET key value [EX seconds] [PX milliseconds] [NX|XX]
- EX: Set expiry in seconds
- PX: Set expiry in milliseconds  
- NX: Only set if key doesn't exist
- XX: Only set if key exists
- Returns: OK or nil
- Time Complexity: O(1)
- Use Case: Store data with optional TTL

DEL key [key ...]
- Returns: Number of keys deleted
- Time Complexity: O(N) where N is number of keys
- Use Case: Remove cached data

EXISTS key [key ...]
- Returns: Number of keys that exist
- Time Complexity: O(N) where N is number of keys
- Use Case: Check if data is cached

TTL key
- Returns: Time to live in seconds, -1 if no expiry, -2 if key doesn't exist
- Time Complexity: O(1)
- Use Case: Check expiration time
```

### Atomic Operations

```
INCR key
- Increment integer value by 1
- Returns: New value after increment
- Time Complexity: O(1)
- Use Case: Counters, rate limiting

INCRBY key increment
- Increment by specified amount
- Returns: New value after increment
- Time Complexity: O(1)
- Use Case: Flexible counters

DECR key / DECRBY key decrement
- Decrement operations
- Returns: New value after decrement
- Time Complexity: O(1)
- Use Case: Inventory tracking
```

### List Operations

```
LPUSH key element [element ...]
- Push elements to left (head) of list
- Returns: Length of list after push
- Time Complexity: O(1) for each element
- Use Case: Recent items, queues

RPUSH key element [element ...]
- Push elements to right (tail) of list
- Returns: Length of list after push
- Time Complexity: O(1) for each element
- Use Case: Append to list

LPOP key / RPOP key
- Pop element from left/right
- Returns: Popped element or nil
- Time Complexity: O(1)
- Use Case: Queue/stack operations

LRANGE key start stop
- Get range of elements
- Returns: Array of elements
- Time Complexity: O(S+N) where S is start offset, N is range size
- Use Case: Pagination, recent items
```

### Hash Operations

```
HSET key field value [field value ...]
- Set hash field values
- Returns: Number of fields added
- Time Complexity: O(1) for each field
- Use Case: Object storage

HGET key field
- Get hash field value
- Returns: Field value or nil
- Time Complexity: O(1)
- Use Case: Retrieve object property

HMGET key field [field ...]
- Get multiple hash field values
- Returns: Array of values
- Time Complexity: O(N) where N is number of fields
- Use Case: Retrieve multiple properties

HDEL key field [field ...]
- Delete hash fields
- Returns: Number of fields deleted
- Time Complexity: O(N) where N is number of fields
- Use Case: Remove object properties
```

### Set Operations

```
SADD key member [member ...]
- Add members to set
- Returns: Number of members added
- Time Complexity: O(1) for each member
- Use Case: Unique collections

SREM key member [member ...]
- Remove members from set
- Returns: Number of members removed
- Time Complexity: O(1) for each member
- Use Case: Remove from collection

SISMEMBER key member
- Check if member exists in set
- Returns: 1 if exists, 0 if not
- Time Complexity: O(1)
- Use Case: Membership testing

SMEMBERS key
- Get all set members
- Returns: Array of members
- Time Complexity: O(N) where N is set size
- Use Case: Get all items (use carefully)
```

### Sorted Set Operations

```
ZADD key score member [score member ...]
- Add members with scores
- Returns: Number of members added
- Time Complexity: O(log(N)) for each member
- Use Case: Leaderboards, rankings

ZRANGE key start stop [WITHSCORES]
- Get members by rank range
- Returns: Array of members (and scores if WITHSCORES)
- Time Complexity: O(log(N)+M) where M is result size
- Use Case: Top N items

ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT offset count]
- Get members by score range
- Returns: Array of members (and scores if WITHSCORES)
- Time Complexity: O(log(N)+M) where M is result size
- Use Case: Items within score range

ZRANK key member
- Get rank of member
- Returns: Rank (0-based) or nil
- Time Complexity: O(log(N))
- Use Case: Find position in ranking
```

## Advanced Features

### Transactions

```
MULTI
- Start transaction
- Returns: OK
- Use Case: Atomic operations

EXEC
- Execute transaction
- Returns: Array of results or nil if discarded
- Use Case: Commit atomic operations

DISCARD
- Discard transaction
- Returns: OK
- Use Case: Cancel transaction

WATCH key [key ...]
- Watch keys for changes
- Returns: OK
- Use Case: Optimistic locking
```

### Pub/Sub

```
SUBSCRIBE channel [channel ...]
- Subscribe to channels
- Returns: Subscription confirmation messages
- Use Case: Real-time notifications

PUBLISH channel message
- Publish message to channel
- Returns: Number of subscribers that received message
- Time Complexity: O(N+M) where N is subscribers, M is pattern subscribers
- Use Case: Event broadcasting

UNSUBSCRIBE [channel [channel ...]]
- Unsubscribe from channels
- Returns: Unsubscription confirmation messages
- Use Case: Stop receiving notifications
```

### Iteration

```
SCAN cursor [MATCH pattern] [COUNT count]
- Iterate over keys
- Returns: [next_cursor, array_of_keys]
- Time Complexity: O(1) for each call, O(N) for complete iteration
- Use Case: Safe key enumeration

HSCAN key cursor [MATCH pattern] [COUNT count]
- Iterate over hash fields
- Returns: [next_cursor, array_of_field_value_pairs]
- Use Case: Iterate large hashes

SSCAN key cursor [MATCH pattern] [COUNT count]
- Iterate over set members
- Returns: [next_cursor, array_of_members]
- Use Case: Iterate large sets

ZSCAN key cursor [MATCH pattern] [COUNT count]
- Iterate over sorted set members
- Returns: [next_cursor, array_of_member_score_pairs]
- Use Case: Iterate large sorted sets
```

## Client Library Design

### Connection Management

```python
class CacheClient:
    def __init__(self, hosts, connection_pool_size=10):
        self.connection_pool = ConnectionPool(hosts, pool_size)
        self.consistent_hash = ConsistentHash(hosts)
    
    def get(self, key):
        node = self.consistent_hash.get_node(key)
        connection = self.connection_pool.get_connection(node)
        return connection.execute("GET", key)
    
    def set(self, key, value, ttl=None):
        node = self.consistent_hash.get_node(key)
        connection = self.connection_pool.get_connection(node)
        if ttl:
            return connection.execute("SET", key, value, "EX", ttl)
        return connection.execute("SET", key, value)
```

### Pipelining Support

```python
class Pipeline:
    def __init__(self, connection):
        self.connection = connection
        self.commands = []
    
    def get(self, key):
        self.commands.append(("GET", key))
        return self
    
    def set(self, key, value):
        self.commands.append(("SET", key, value))
        return self
    
    def execute(self):
        # Send all commands in single network round trip
        return self.connection.execute_pipeline(self.commands)

# Usage
with client.pipeline() as pipe:
    pipe.get("key1").get("key2").set("key3", "value3")
    results = pipe.execute()
```

## Error Handling

### Error Response Format

```
-ERR <error-type> <error-message>\r\n

Examples:
-ERR WRONGTYPE Operation against a key holding the wrong kind of value\r\n
-ERR NOAUTH Authentication required\r\n
-ERR MOVED 3999 127.0.0.1:6381\r\n  // Key moved to different node
-ERR ASK 3999 127.0.0.1:6381\r\n     // Temporary redirect during migration
```

### Client Error Handling

```python
class CacheException(Exception):
    pass

class WrongTypeException(CacheException):
    pass

class MovedException(CacheException):
    def __init__(self, slot, host, port):
        self.slot = slot
        self.host = host
        self.port = port

def parse_error(error_response):
    if error_response.startswith("-ERR WRONGTYPE"):
        raise WrongTypeException(error_response)
    elif error_response.startswith("-ERR MOVED"):
        # Parse slot and new location
        parts = error_response.split()
        slot = int(parts[2])
        host, port = parts[3].split(':')
        raise MovedException(slot, host, int(port))
```

## Performance Optimizations

### Request Batching

```
Instead of:
GET key1
GET key2  
GET key3

Use MGET:
MGET key1 key2 key3

Benefit: 3 network round trips → 1 network round trip
```

### Connection Pooling

```python
class ConnectionPool:
    def __init__(self, host, port, pool_size=10):
        self.pool = Queue(maxsize=pool_size)
        for _ in range(pool_size):
            conn = Connection(host, port)
            self.pool.put(conn)
    
    def get_connection(self):
        return self.pool.get(timeout=1.0)
    
    def return_connection(self, conn):
        self.pool.put(conn)
```

### Consistent Hashing Integration

```python
class ConsistentHashClient:
    def __init__(self, nodes):
        self.hash_ring = ConsistentHash(nodes)
        self.connections = {node: ConnectionPool(node) for node in nodes}
    
    def execute(self, command, key, *args):
        node = self.hash_ring.get_node(key)
        conn = self.connections[node].get_connection()
        try:
            return conn.execute(command, key, *args)
        except MovedException as e:
            # Update hash ring and retry
            self.hash_ring.update_node_mapping(e.slot, e.host, e.port)
            return self.execute(command, key, *args)
        finally:
            self.connections[node].return_connection(conn)
```

## API Versioning Strategy

### Backward Compatibility

1. **Additive Changes**: New commands and parameters are safe
2. **Response Format**: Never change existing response formats
3. **Error Codes**: Maintain existing error code meanings
4. **Deprecation**: Mark old features as deprecated before removal

### Version Negotiation

```
Client connects and sends:
HELLO 3 AUTH username password

Server responds:
*7
$6
server
$5
redis
$7
version
$5
6.2.0
$5
proto
:3
```

## Summary

Our API design provides:

1. **High Performance**: Binary protocol with minimal overhead
2. **Rich Data Types**: Strings, lists, sets, hashes, sorted sets
3. **Atomic Operations**: Transactions and atomic counters
4. **Scalability**: Consistent hashing integration
5. **Reliability**: Comprehensive error handling
6. **Usability**: Simple, Redis-compatible interface

The API strikes a balance between performance (binary protocol), functionality (rich data types), and usability (familiar Redis-like commands). This foundation supports the high-performance distributed cache we're building.

Next, we'll design the partitioning and sharding strategies that distribute this API across multiple nodes.