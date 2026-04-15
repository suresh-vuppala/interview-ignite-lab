# DAO vs Repository

Both provide an abstraction layer over data persistence, but they differ in focus and design philosophy.

<br>

---

## DAO (Data Access Object)

**Focus:** Encapsulate all access to a specific data source (database table).

```java
interface UserDAO {
    void insert(User user);
    void update(User user);
    void delete(int id);
    User findById(int id);
    List<User> findAll();
    List<User> findBySQL(String sql); // Aware of persistence details
}
```
- **Table-centric** — one DAO per table
- **Persistence-aware** — may expose SQL, connection details
- **CRUD focused** — basic create/read/update/delete

<br>

---

## Repository

**Focus:** Provide a collection-like interface for domain objects.

```java
interface UserRepository {
    void save(User user);            // Create or update
    Optional<User> findById(UserId id);
    List<User> findByName(String name);
    List<User> findActive();
    void remove(User user);
    // No SQL, no connection details — pure domain language
}
```
- **Domain-centric** — speaks the language of the business
- **Persistence-ignorant** — client doesn't know if it's SQL, NoSQL, or in-memory
- **Collection-like** — acts like a collection of domain objects

<br>

---

## Comparison

| Aspect | DAO | Repository |
|--------|-----|-----------|
| **Focus** | Data access | Domain model |
| **Abstraction** | Table/query level | Collection level |
| **Language** | Technical (SQL) | Business (findActiveUsers) |
| **Pattern** | Enterprise pattern | DDD pattern |
| **Use in LLD** | Acceptable | Preferred |

<br>

---

## Key Takeaways

1. **In LLD interviews: use Repository** — it's cleaner and more domain-focused
2. **Repository hides persistence details** — swap in-memory for SQL without changing clients
3. **DAO is fine for simple CRUD** — don't over-engineer if requirements are simple
