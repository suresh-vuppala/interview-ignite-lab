# Writing Testable Code

> **If it's hard to test, it's probably badly designed.**

<br>

---

## What Makes Code Hard to Test

| Anti-Pattern | Why It's Hard | Fix |
|-------------|--------------|-----|
| **`new` inside methods** | Can't swap with mock | Inject via constructor |
| **Static methods** | Can't override | Wrap in interface |
| **Singleton** | Global state between tests | Inject as dependency |
| **Tight coupling** | Need entire system to test one class | Depend on interfaces |

<br>

---

## The Fix: Dependency Injection

```java
// ❌ Hard to test — creates real EmailService inside
class OrderService {
    private EmailService email = new EmailService(); // Can't mock!
    public void placeOrder(Order order) {
        // ... business logic ...
        email.send("Order placed"); // Sends real email in tests!
    }
}

// ✅ Easy to test — inject dependency
class OrderService {
    private final NotificationService notifier; // Interface!
    public OrderService(NotificationService notifier) { this.notifier = notifier; }
    public void placeOrder(Order order) {
        // ... business logic ...
        notifier.send("Order placed");
    }
}

// Test with mock
@Test
void testPlaceOrder() {
    NotificationService mockNotifier = mock(NotificationService.class);
    OrderService service = new OrderService(mockNotifier);
    service.placeOrder(new Order());
    verify(mockNotifier).send("Order placed"); // Verify interaction
}
```

<br>

---

## Rules for Testable Code

1. **Depend on interfaces** — not concrete classes
2. **Inject dependencies** via constructor — not created internally
3. **Pure functions** where possible — same input → same output
4. **Avoid static state** — breaks test isolation
5. **Small, focused methods** — easy to test in isolation

<br>

---

## Key Takeaways

1. **DI is the #1 technique** for testable code
2. **In interviews:** always design classes with constructor injection
3. **If you can't test a class in isolation, refactor it**
