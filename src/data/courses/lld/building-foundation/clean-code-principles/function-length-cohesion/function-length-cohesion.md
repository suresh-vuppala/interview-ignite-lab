# Function Length & Cohesion

> "A function should do one thing, do it well, and do it only."

<br>

---

## Signs a Function is Too Long

1. **Can't describe it without "and"** — "validates AND saves AND sends email"
2. **Multiple levels of abstraction** — HTTP parsing next to business logic
3. **Needs scrolling** — can't see entire function on screen
4. **Multiple comments** breaking it into sections

<br>

---

## Extract Till You Drop

### ❌ Before: 50-line monolith
```java
void processOrder(Order order) {
    // Validate
    if (order.getItems().isEmpty()) throw ...
    if (order.getTotal() < 0) throw ...
    // Calculate discount
    double discount = 0;
    if (order.getCustomer().isPremium()) discount = 0.1;
    // Process payment
    PaymentResult result = gateway.charge(order.getTotal() * (1 - discount));
    if (!result.isSuccess()) throw ...
    // Update inventory
    for (Item item : order.getItems()) inventory.reduce(item);
    // Send confirmation
    emailService.send(order.getCustomer().getEmail(), "Order confirmed");
}
```

### ✅ After: Small, focused methods
```java
void processOrder(Order order) {
    validateOrder(order);
    double total = applyDiscount(order);
    processPayment(order, total);
    updateInventory(order);
    sendConfirmation(order);
}

private void validateOrder(Order order) { ... }
private double applyDiscount(Order order) { ... }
private void processPayment(Order order, double total) { ... }
```

<br>

---

## Key Takeaways

1. **One function = one level of abstraction**
2. **Extract methods aggressively** — small is beautiful
3. **Good function names eliminate need for comments**
4. **Aim for 5-15 lines per method** (guideline, not rigid rule)
