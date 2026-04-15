# Future/Promise Pattern

> **Intent:** Represent a placeholder for a result that is not yet available but will be computed asynchronously.

<br>

---

## Java Future vs CompletableFuture

### Basic Future — blocking
```java
ExecutorService pool = Executors.newFixedThreadPool(4);

Future<Double> future = pool.submit(() -> {
    Thread.sleep(2000); // Simulate slow computation
    return 42.0;
});

// Do other work...

double result = future.get(); // BLOCKS until result is ready
```

### CompletableFuture — non-blocking chains
```java
CompletableFuture<String> future = CompletableFuture
    .supplyAsync(() -> fetchUserData(userId))       // Step 1: async
    .thenApply(user -> enrichProfile(user))          // Step 2: transform
    .thenApply(profile -> formatForDisplay(profile)) // Step 3: format
    .exceptionally(ex -> "Error: " + ex.getMessage()); // Error handling

// Combine multiple futures
CompletableFuture<Double> priceFuture = CompletableFuture.supplyAsync(() -> getPrice());
CompletableFuture<Double> taxFuture = CompletableFuture.supplyAsync(() -> getTaxRate());

CompletableFuture<Double> total = priceFuture.thenCombine(taxFuture, 
    (price, tax) -> price * (1 + tax));
```

<br>

---

## Real-World: Parallel API Calls

```java
CompletableFuture<UserProfile> profile = CompletableFuture.supplyAsync(() -> userService.getProfile(id));
CompletableFuture<List<Order>> orders = CompletableFuture.supplyAsync(() -> orderService.getOrders(id));
CompletableFuture<Double> balance = CompletableFuture.supplyAsync(() -> walletService.getBalance(id));

// Wait for ALL three to complete
CompletableFuture.allOf(profile, orders, balance).thenRun(() -> {
    renderDashboard(profile.join(), orders.join(), balance.join());
});
```

<br>

---

## Key Takeaways

1. **Future** = blocking `.get()` — simple but can waste thread time
2. **CompletableFuture** = non-blocking chains with `.thenApply()`, `.thenCombine()`
3. **`allOf()`** — wait for multiple async operations
4. **Error handling** — `.exceptionally()` or `.handle()`
5. **Used in:** API aggregation, parallel processing, reactive systems
