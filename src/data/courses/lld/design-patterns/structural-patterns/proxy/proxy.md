# Proxy Pattern

> **Intent:** Provide a surrogate or placeholder for another object to control access to it.

<br>

---

## Types of Proxy

| Type | Purpose | Example |
|------|---------|---------|
| **Virtual Proxy** | Lazy initialization — delay heavy object creation | Load image only when displayed |
| **Protection Proxy** | Access control — check permissions | Admin-only operations |
| **Caching Proxy** | Cache results — avoid repeated expensive calls | Cache DB query results |
| **Logging Proxy** | Audit/logging — track method calls | Log all API requests |
| **Remote Proxy** | Represent remote object locally | RPC/REST client stub |

<br>

---

## Example: Protection Proxy

```java
interface DatabaseService {
    String query(String sql);
    void execute(String sql);
}

class RealDatabaseService implements DatabaseService {
    public String query(String sql) { return "Result of: " + sql; }
    public void execute(String sql) { System.out.println("Executed: " + sql); }
}

// Proxy — adds access control
class DatabaseProxy implements DatabaseService {
    private RealDatabaseService realService;
    private String userRole;
    
    public DatabaseProxy(String userRole) {
        this.userRole = userRole;
        this.realService = new RealDatabaseService();
    }
    
    public String query(String sql) {
        log("QUERY", sql);
        return realService.query(sql); // Everyone can query
    }
    
    public void execute(String sql) {
        if (!"ADMIN".equals(userRole)) {
            throw new SecurityException("Only admins can execute statements!");
        }
        log("EXECUTE", sql);
        realService.execute(sql); // Only admins can execute
    }
    
    private void log(String op, String sql) {
        System.out.println("[" + userRole + "] " + op + ": " + sql);
    }
}
```

<br>

---

## Caching Proxy Example

```java
class CachingWeatherProxy implements WeatherService {
    private WeatherService realService;
    private Map<String, WeatherData> cache = new HashMap<>();
    private Map<String, Long> cacheTimestamp = new HashMap<>();
    private long ttlMs = 300_000; // 5 minutes
    
    public WeatherData getWeather(String city) {
        if (cache.containsKey(city) && !isExpired(city)) {
            return cache.get(city); // Cache hit — fast!
        }
        WeatherData data = realService.getWeather(city); // Expensive call
        cache.put(city, data);
        cacheTimestamp.put(city, System.currentTimeMillis());
        return data;
    }
}
```

<br>

---

## Key Takeaways

1. **Same interface as real object** — client doesn't know it's a proxy
2. **Controls access** — permissions, caching, lazy loading, logging
3. **Proxy vs Decorator:** Proxy controls access; Decorator adds behavior
4. **Common in:** Spring AOP, Hibernate lazy loading, API gateways, RPC
