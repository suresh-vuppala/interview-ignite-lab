# In-memory Storage vs Real DB

In LLD interviews, you almost always **start with in-memory storage** and discuss database integration as an extension.

<br>

---

## Interview Approach

### Phase 1: In-Memory (Always start here)
```java
class UserRepository {
    private Map<String, User> users = new ConcurrentHashMap<>();
    
    public void save(User user) { users.put(user.getId(), user); }
    public Optional<User> findById(String id) { return Optional.ofNullable(users.get(id)); }
    public List<User> findByName(String name) {
        return users.values().stream()
            .filter(u -> u.getName().equals(name))
            .toList();
    }
}
```

### Phase 2: Mention Database (If time permits)
"In production, I'd replace this HashMap with a database. The Repository interface stays the same — just swap the implementation."

```java
interface UserRepository {
    void save(User user);
    Optional<User> findById(String id);
}

class InMemoryUserRepo implements UserRepository { /* HashMap */ }
class JdbcUserRepo implements UserRepository { /* SQL queries */ }
class MongoUserRepo implements UserRepository { /* MongoDB driver */ }
```

<br>

---

## When to Use What

| Scenario | Storage | Why |
|----------|---------|-----|
| **LLD Interview** | In-memory (HashMap) | Focus on design, not SQL |
| **Speed-critical cache** | ConcurrentHashMap | O(1) lookup |
| **Persistent data** | SQL/NoSQL | Survives restarts |
| **Testing** | In-memory | Fast, isolated tests |

<br>

---

## Key Takeaways

1. **Start with HashMap/ConcurrentHashMap** in interviews — it's expected
2. **Use Repository interface** — easily swappable later
3. **Mention scalability:** "In production, this would be backed by [MySQL/Redis/MongoDB]"
4. **ConcurrentHashMap** for thread-safe in-memory storage
