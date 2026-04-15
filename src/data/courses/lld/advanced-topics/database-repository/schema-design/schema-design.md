# Schema Design for LLD Problems

When interviewers ask "How would you store this in a database?", translate your class diagram to tables.

<br>

---

## Entity → Table Mapping

```java
// OOP Class
class User {
    String id;
    String name;
    String email;
    List<Order> orders; // One-to-many
}

class Order {
    String orderId;
    User user;          // Many-to-one
    List<OrderItem> items; // One-to-many
    double total;
}
```

```sql
-- SQL Tables
CREATE TABLE users (
    id VARCHAR(36) PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL
);

CREATE TABLE orders (
    order_id VARCHAR(36) PRIMARY KEY,
    user_id VARCHAR(36) REFERENCES users(id),  -- FK
    total DECIMAL(10,2),
    created_at TIMESTAMP DEFAULT NOW()
);

CREATE TABLE order_items (
    id SERIAL PRIMARY KEY,
    order_id VARCHAR(36) REFERENCES orders(order_id),
    product_name VARCHAR(100),
    quantity INT,
    unit_price DECIMAL(10,2)
);
```

<br>

---

## Relationship Mapping

| OOP Relationship | DB Representation |
|-----------------|-------------------|
| **One-to-One** | FK in either table (or same table) |
| **One-to-Many** | FK in the "many" side table |
| **Many-to-Many** | Junction/join table |
| **Inheritance** | Single table (discriminator) OR table-per-class |

<br>

---

## Key Takeaways

1. **Each entity → one table** (usually)
2. **Relationships → foreign keys**
3. **Many-to-many → junction table**
4. **In interviews:** mention indexing for frequently queried columns
5. **Don't over-normalize** — sometimes denormalization improves read performance
