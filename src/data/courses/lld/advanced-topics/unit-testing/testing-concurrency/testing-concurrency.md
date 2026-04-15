# Testing Concurrency

> **Concurrent bugs are non-deterministic** — they may not appear in every test run. Special strategies are needed.

<br>

---

## Challenges

- **Non-deterministic:** Same test may pass 99 times, fail once
- **Timing-dependent:** Bug only appears under specific thread scheduling
- **Hard to reproduce:** Works on your machine, fails in CI

<br>

---

## Strategies

### 1. Stress Testing — run many threads, many iterations
```java
@Test
void testConcurrentDeposit() throws InterruptedException {
    Account account = new Account(0);
    int threads = 100;
    int depositsPerThread = 1000;
    ExecutorService pool = Executors.newFixedThreadPool(threads);
    CountDownLatch latch = new CountDownLatch(threads);
    
    for (int i = 0; i < threads; i++) {
        pool.submit(() -> {
            for (int j = 0; j < depositsPerThread; j++) account.deposit(1);
            latch.countDown();
        });
    }
    latch.await();
    assertEquals(threads * depositsPerThread, account.getBalance());
    // Without synchronization, this WILL fail with a value less than expected
}
```

### 2. CountDownLatch — synchronize thread start
```java
CountDownLatch startSignal = new CountDownLatch(1);
// All threads wait for start signal → maximizes contention
for (int i = 0; i < N; i++) {
    new Thread(() -> {
        startSignal.await(); // All threads start simultaneously
        sharedResource.doSomething();
    }).start();
}
startSignal.countDown(); // Release all threads at once!
```

### 3. CyclicBarrier — synchronize at specific points
### 4. Thread.sleep() — introduce delays (fragile, use sparingly)
### 5. Repeat tests many times — `@RepeatedTest(1000)` in JUnit 5

<br>

---

## Key Takeaways

1. **Run concurrent tests MANY times** — one pass doesn't prove correctness
2. **CountDownLatch** to maximize thread contention
3. **Assert on final state** — not intermediate values
4. **Tools:** Java PathFinder, ThreadSanitizer, jcstress for formal verification
5. **In interviews:** mention stress testing when discussing thread-safe designs
