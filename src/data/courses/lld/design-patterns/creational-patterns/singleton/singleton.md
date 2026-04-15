# Singleton Pattern

> **Intent:** Ensure a class has only one instance and provide a global point of access to it.

<br>

---

## When to Use

- **Database connection pool** — one pool shared across the app
- **Configuration manager** — single source of truth for settings
- **Logger** — one logging instance
- **Cache** — one shared cache
- **Thread pool** — one pool managing workers

<br>

---

## Implementation Approaches

### 1. Eager Initialization (Simplest)
```java
public class Singleton {
    private static final Singleton INSTANCE = new Singleton(); // Created at class load
    private Singleton() {} // Private constructor
    public static Singleton getInstance() { return INSTANCE; }
}
```
✅ Thread-safe (JVM guarantees static init is thread-safe)
❌ Instance created even if never used

### 2. Lazy Initialization (Not Thread-Safe!)
```java
public class Singleton {
    private static Singleton instance;
    private Singleton() {}
    public static Singleton getInstance() {
        if (instance == null) instance = new Singleton(); // Race condition!
        return instance;
    }
}
```
❌ **Two threads can both see `null` and create two instances**

### 3. Double-Checked Locking (Interview Favorite)
```java
public class Singleton {
    private static volatile Singleton instance; // volatile is CRITICAL
    private Singleton() {}
    
    public static Singleton getInstance() {
        if (instance == null) {                    // First check (no lock)
            synchronized (Singleton.class) {       // Lock
                if (instance == null) {             // Second check (with lock)
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}
```
✅ Lazy + Thread-safe + Minimal synchronization overhead
⚠️ Requires `volatile` to prevent instruction reordering

### 4. Bill Pugh / Static Inner Class (Recommended)
```java
public class Singleton {
    private Singleton() {}
    
    private static class Holder {
        private static final Singleton INSTANCE = new Singleton();
    }
    
    public static Singleton getInstance() { return Holder.INSTANCE; }
}
```
✅ Lazy (inner class loaded only when `getInstance()` called)
✅ Thread-safe (JVM class loading is thread-safe)
✅ No synchronization overhead — **BEST approach**

### 5. Enum Singleton (Effective Java)
```java
public enum Singleton {
    INSTANCE;
    
    public void doSomething() { ... }
}
```
✅ Serialization-safe, reflection-safe, thread-safe
✅ Joshua Bloch's recommended approach

<br>

---

## Breaking Singleton (Interview Question!)

| Attack | Defense |
|--------|---------|
| **Reflection** — `constructor.setAccessible(true)` | Throw exception in private constructor if instance exists |
| **Serialization** — `readResolve()` creates new object | Implement `readResolve()` returning `INSTANCE` |
| **Cloning** — `clone()` creates copy | Override `clone()` to throw exception |
| **Use Enum** | Immune to all three attacks |

<br>

---

## Real-World LLD Example: Configuration Manager

```java
public class ConfigManager {
    private static volatile ConfigManager instance;
    private final Map<String, String> properties;
    
    private ConfigManager() {
        properties = new HashMap<>();
        loadFromFile("config.properties");
    }
    
    public static ConfigManager getInstance() {
        if (instance == null) {
            synchronized (ConfigManager.class) {
                if (instance == null) instance = new ConfigManager();
            }
        }
        return instance;
    }
    
    public String get(String key) { return properties.get(key); }
    public String get(String key, String defaultVal) { return properties.getOrDefault(key, defaultVal); }
}
```

<br>

---

## Common Interview Questions

1. **"What is Singleton?"** → One instance, global access
2. **"Why is volatile needed in double-checked locking?"** → Prevents JVM instruction reordering
3. **"How to break Singleton?"** → Reflection, Serialization, Cloning
4. **"Best implementation?"** → Enum (simplest + safest) or Bill Pugh (most flexible)
5. **"Is Singleton an anti-pattern?"** → Can be — makes testing hard (global state), prefer DI

<br>

---

## Key Takeaways

1. **Bill Pugh (inner class)** = best general-purpose implementation
2. **Enum** = simplest + most attack-resistant
3. **Double-checked locking** = most asked in interviews
4. **`volatile` is required** — don't forget!
5. **Prefer Dependency Injection over Singleton** for testability
