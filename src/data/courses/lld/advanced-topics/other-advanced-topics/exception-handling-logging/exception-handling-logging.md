# Exception Handling & Logging

<br>

---

## Exception Hierarchy Design

```java
// Base exception for your system
class AppException extends RuntimeException {
    private final ErrorCode code;
    public AppException(ErrorCode code, String message) { super(message); this.code = code; }
}

// Specific exceptions
class NotFoundException extends AppException {
    public NotFoundException(String entity, String id) {
        super(ErrorCode.NOT_FOUND, entity + " not found: " + id);
    }
}
class InsufficientFundsException extends AppException { ... }
class DuplicateEntityException extends AppException { ... }
class UnauthorizedException extends AppException { ... }

enum ErrorCode { NOT_FOUND, DUPLICATE, INSUFFICIENT_FUNDS, UNAUTHORIZED, INTERNAL_ERROR }
```

<br>

---

## Best Practices

1. **Catch specific, throw specific** — not `catch (Exception e)`
2. **Don't swallow exceptions** — `catch (Exception e) {}` hides bugs
3. **Use custom exceptions** — domain-specific, not generic
4. **Log at the right level:** DEBUG for details, ERROR for failures, INFO for events
5. **Fail fast** — validate inputs early, throw immediately

```java
// ❌ Bad
try { processOrder(order); }
catch (Exception e) { e.printStackTrace(); } // Swallowed!

// ✅ Good
try { processOrder(order); }
catch (PaymentFailedException e) { logger.error("Payment failed for order {}", order.getId(), e); throw e; }
catch (InventoryException e) { logger.warn("Out of stock: {}", e.getMessage()); notifyUser(order); }
```

<br>

---

## Key Takeaways

1. **Custom exception hierarchy** per domain
2. **Log + rethrow or handle** — never swallow silently
3. **In interviews:** show thoughtful error handling in your code
