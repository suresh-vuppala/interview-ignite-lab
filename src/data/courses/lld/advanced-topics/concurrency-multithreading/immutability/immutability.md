# Immutability

> **An immutable object's state cannot be changed after construction.** Immutable objects are inherently thread-safe — no synchronization needed.

<br>

---

## Rules for Immutability

1. **`final` class** — prevent subclassing
2. **All fields `private final`** — no reassignment
3. **No setters** — no mutation methods
4. **Defensive copies** in constructor for mutable parameters
5. **Defensive copies** in getters for mutable fields
6. **Compute-and-return-new** — operations return new instances

<br>

---

## Complete Example

```java
public final class ImmutableOrder {
    private final String orderId;
    private final List<String> items;
    private final double total;
    private final LocalDateTime createdAt;
    
    public ImmutableOrder(String orderId, List<String> items, double total) {
        this.orderId = orderId;
        this.items = List.copyOf(items);  // Defensive copy — unmodifiable
        this.total = total;
        this.createdAt = LocalDateTime.now();
    }
    
    public String getOrderId() { return orderId; }
    public List<String> getItems() { return items; }  // Already unmodifiable
    public double getTotal() { return total; }
    
    // Returns NEW object — doesn't modify this one
    public ImmutableOrder withItem(String item) {
        List<String> newItems = new ArrayList<>(items);
        newItems.add(item);
        return new ImmutableOrder(orderId, newItems, total + getPrice(item));
    }
}
```

<br>

---

## Java Immutable Classes

- `String`, `Integer`, `Long`, `Double` (all wrappers)
- `LocalDate`, `LocalDateTime`, `Instant`
- `Optional`
- `List.of()`, `Map.of()`, `Set.of()` (Java 9+)

<br>

---

## Key Takeaways

1. **Immutable = thread-safe for free** — no synchronization overhead
2. **Java Records** (Java 16+) make immutability easy: `record Point(int x, int y) {}`
3. **"with" methods** return new instances: `order.withItem("pizza")`
4. **Trade-off:** more object creation (GC pressure) vs thread safety
5. **Default to immutable** — make mutable only when necessary
