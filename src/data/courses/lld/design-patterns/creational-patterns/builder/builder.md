# Builder Pattern

> **Intent:** Separate the construction of a complex object from its representation, allowing the same construction process to create different representations.

<br>

---

## When to Use

- Object has **many optional parameters** (telescoping constructor problem)
- **Step-by-step construction** is needed
- Object should be **immutable** after construction
- **Readable construction** — `builder.setX().setY().build()`

<br>

---

## The Problem: Telescoping Constructors

```java
// ❌ How many constructors do we need?!
class Pizza {
    Pizza(String size) { ... }
    Pizza(String size, boolean cheese) { ... }
    Pizza(String size, boolean cheese, boolean pepperoni) { ... }
    Pizza(String size, boolean cheese, boolean pepperoni, boolean mushrooms) { ... }
    // This gets unmanageable!
}

new Pizza("Large", true, false, true, false, true); // What is each boolean?!
```

<br>

---

## Solution: Builder

```java
class Pizza {
    private final String size;       // Required
    private final boolean cheese;    // Optional
    private final boolean pepperoni;
    private final boolean mushrooms;
    private final boolean olives;
    
    private Pizza(Builder builder) {
        this.size = builder.size;
        this.cheese = builder.cheese;
        this.pepperoni = builder.pepperoni;
        this.mushrooms = builder.mushrooms;
        this.olives = builder.olives;
    }
    
    public static class Builder {
        private final String size;  // Required — in constructor
        private boolean cheese, pepperoni, mushrooms, olives; // Optional — defaults
        
        public Builder(String size) { this.size = size; }
        
        public Builder cheese() { this.cheese = true; return this; }
        public Builder pepperoni() { this.pepperoni = true; return this; }
        public Builder mushrooms() { this.mushrooms = true; return this; }
        public Builder olives() { this.olives = true; return this; }
        
        public Pizza build() {
            // Validation before creating
            if (size == null) throw new IllegalStateException("Size is required");
            return new Pizza(this);
        }
    }
}

// Usage — readable, no confusion about parameters!
Pizza pizza = new Pizza.Builder("Large")
    .cheese()
    .pepperoni()
    .mushrooms()
    .build();
```

<br>

---

## Real-World: HTTP Request Builder

```java
class HttpRequest {
    private final String method;
    private final String url;
    private final Map<String, String> headers;
    private final String body;
    private final int timeout;
    
    // Fluent builder for complex HTTP requests
    static class Builder {
        private String method = "GET";
        private String url;
        private Map<String, String> headers = new HashMap<>();
        private String body;
        private int timeout = 30000;
        
        public Builder(String url) { this.url = url; }
        public Builder method(String m) { this.method = m; return this; }
        public Builder header(String k, String v) { headers.put(k, v); return this; }
        public Builder body(String b) { this.body = b; return this; }
        public Builder timeout(int ms) { this.timeout = ms; return this; }
        public HttpRequest build() { return new HttpRequest(this); }
    }
}

// Clean, readable construction
HttpRequest req = new HttpRequest.Builder("https://api.example.com/users")
    .method("POST")
    .header("Content-Type", "application/json")
    .header("Authorization", "Bearer token123")
    .body("{"name": "John"}")
    .timeout(5000)
    .build();
```

<br>

---

## Key Takeaways

1. **Solves telescoping constructor** problem — many optional params
2. **Fluent interface** — readable chained method calls
3. **Immutable objects** — set all fields, then `build()` (no setters after)
4. **Validation in `build()`** — ensure object is valid before creation
5. **Java standard:** `StringBuilder`, `Stream.Builder`, `Lombok @Builder`
