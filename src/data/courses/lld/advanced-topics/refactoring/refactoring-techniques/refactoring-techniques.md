# Refactoring Techniques

> **Refactoring:** Restructuring existing code without changing its external behavior.

<br>

---

## Top Refactoring Techniques

### 1. Extract Method
```java
// Before — 30-line method
void processOrder(Order order) {
    // validate (10 lines)
    // calculate discount (10 lines)
    // process payment (10 lines)
}

// After — clear, named steps
void processOrder(Order order) {
    validate(order);
    double total = calculateDiscount(order);
    processPayment(order, total);
}
```

### 2. Replace Conditional with Polymorphism
Move each branch into a separate class with a common interface.

### 3. Extract Class
Split a God Class into focused classes by responsibility.

### 4. Introduce Parameter Object
```java
// Before
List<Order> search(Date from, Date to, String status, double minAmount) { ... }

// After
List<Order> search(OrderSearchCriteria criteria) { ... }
```

### 5. Replace Magic Numbers with Constants
```java
// Before
if (age >= 18) { ... }

// After
private static final int MINIMUM_AGE = 18;
if (age >= MINIMUM_AGE) { ... }
```

### 6. Move Method / Move Field
Move code to the class that uses it most (fix Feature Envy).

<br>

---

## Refactoring Safety

1. **Write tests BEFORE refactoring** — ensure behavior is preserved
2. **Small steps** — one refactoring at a time, run tests after each
3. **Commit frequently** — easy to roll back if something breaks
4. **IDE support** — IntelliJ/Eclipse automate most refactorings safely

<br>

---

## Key Takeaways

1. **Extract Method** is the most common refactoring — use it aggressively
2. **Always have tests** before refactoring
3. **Small, incremental changes** — never refactor and add features simultaneously
4. **In interviews:** mention refactoring when you see a smell in your own design
