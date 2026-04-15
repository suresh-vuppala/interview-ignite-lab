# Anti-Patterns

> **An anti-pattern is a common response to a recurring problem that is usually ineffective and risks being highly counterproductive.**

<br>

---

## Top Anti-Patterns for LLD

### 1. God Object / God Class
**Problem:** One class that knows/does everything.
```java
class ApplicationManager {
    void handleLogin() { ... }
    void processOrder() { ... }
    void sendEmail() { ... }
    void generateReport() { ... }
    void backupDatabase() { ... }
    // 2000+ lines, 50+ methods
}
```
**Fix:** Split by responsibility (SRP). Extract OrderService, EmailService, etc.

### 2. Poltergeist
**Problem:** Class that only exists to invoke methods on other classes. No real purpose.
```java
class OrderHelper {
    void processOrder(Order o) {
        validator.validate(o);      // Just delegating
        processor.process(o);       // Just delegating
        notifier.notify(o);         // Just delegating
    }
}
// Why not call validator/processor/notifier directly?
```
**Fix:** Remove the middleman, or give it real logic.

### 3. Singleton Abuse
**Problem:** Using Singleton for everything → global state, hard to test.
**Fix:** Use Dependency Injection instead.

### 4. Golden Hammer
**Problem:** Using the same pattern/technology for everything.
"When you have a hammer, everything looks like a nail."
**Fix:** Choose patterns based on the specific problem.

### 5. Lava Flow
**Problem:** Dead code that nobody dares to remove because "it might be needed."
**Fix:** Delete it. It's in version control if you ever need it.

### 6. Copy-Paste Programming
**Problem:** Duplicating code instead of abstracting.
**Fix:** Extract common logic into shared methods/classes.

### 7. Magic Numbers / Strings
**Problem:** Hardcoded values with no explanation.
```java
if (retryCount > 3) { ... }  // Why 3?
```
**Fix:** Named constants: `private static final int MAX_RETRIES = 3;`

### 8. Premature Optimization
**Problem:** Optimizing before measuring, adding complexity for negligible gains.
**Fix:** Make it work, make it right, THEN make it fast (only if needed).

<br>

---

## Key Takeaways

1. **God Object** is the #1 anti-pattern — always split by responsibility
2. **In interviews:** recognizing anti-patterns shows design maturity
3. **Every anti-pattern has a SOLID principle it violates**
4. **"Make it work, make it right, make it fast"** — in that order
