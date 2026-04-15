# Dependency

Dependency is the **weakest relationship** between classes — one class **temporarily uses** another, typically as a method parameter, local variable, or return type. No long-term reference is maintained.

<br>

---

## The Key Rule

> **"Uses" but doesn't "have"** — the relationship exists only during a method call.

<br>

---

## Example

```java
class OrderService {
    // Dependency: uses EmailSender temporarily — doesn't store it
    public void processOrder(Order order, EmailSender emailSender) {
        // ... process order ...
        emailSender.send(order.getCustomerEmail(), "Order confirmed!");
        // EmailSender goes out of scope after method ends
    }
}
```

**Compare with Association:**
```java
class OrderService {
    private EmailSender emailSender;  // ASSOCIATION — long-term reference
    
    public void processOrder(Order order) {
        emailSender.send(...);  // Uses stored reference
    }
}
```

<br>

---

## UML Notation

**Dashed arrow (- - -►) from dependent to dependency**

```
OrderService - - - -► EmailSender
(depends on)         (used temporarily)
```

<br>

---

## Types of Dependency

1. **Method parameter**: `void process(Parser parser)`
2. **Local variable**: `Parser p = new Parser(); p.parse();`
3. **Return type**: `Parser createParser()`
4. **Static method call**: `Math.random()`

<br>

---

## Relationship Strength Summary

```
Dependency  <  Association  <  Aggregation  <  Composition
(weakest)                                     (strongest)

Uses         Knows about     Has (shared)     Owns (exclusive)
Temporary    Long-term       Part survives    Part dies with whole
- - -►       ────           ◇────            ◆────
```

<br>

---

## Key Takeaways

1. **Weakest relationship** — temporary, during method call only
2. **No stored reference** to the dependency
3. **Dashed arrow in UML** (- - -►)
4. **Changes in dependency may require changes in dependent class**
5. **Minimize dependencies** — reduces coupling
