# Serialization & Versioning

<br>

---

## Serialization Formats

| Format | Speed | Size | Human-readable | Schema |
|--------|-------|------|---------------|--------|
| **JSON** | Medium | Large | ✅ Yes | Optional |
| **XML** | Slow | Largest | ✅ Yes | XSD |
| **Protobuf** | Fast | Small | ❌ No | Required (.proto) |
| **Java Serializable** | Medium | Medium | ❌ No | Implicit |

<br>

---

## Versioning Strategies

### 1. Backward Compatible Changes (Safe)
- Add new optional fields (with defaults)
- Add new endpoints/methods

### 2. Breaking Changes (Dangerous)
- Remove/rename fields
- Change field types
- Change method signatures

### 3. Version in API
```java
// URL versioning
GET /api/v1/users
GET /api/v2/users

// Header versioning
Accept: application/vnd.myapp.v2+json
```

### 4. Serialization Versioning
```java
class UserV1 { String name; String email; }
class UserV2 { String firstName; String lastName; String email; } // Split name

// Adapter: V1 → V2
class UserAdapter {
    static UserV2 fromV1(UserV1 v1) {
        String[] parts = v1.name.split(" ");
        return new UserV2(parts[0], parts.length > 1 ? parts[1] : "", v1.email);
    }
}
```

<br>

---

## Key Takeaways

1. **JSON** for REST APIs (human-readable, widely supported)
2. **Protobuf** for internal services (fast, compact)
3. **Always add fields with defaults** — backward compatible
4. **Version your APIs** when breaking changes are unavoidable
5. **In interviews:** mention serialization when discussing data transfer between systems
