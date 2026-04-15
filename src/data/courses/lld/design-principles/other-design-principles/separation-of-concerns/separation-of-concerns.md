# Separation of Concerns (SoC)

> **"Each module should address a single concern."**

SoC means organizing code so that each part handles **one aspect** of the functionality, and different concerns don't mix.

<br>

---

## Examples of Concerns

| Concern | Responsibility |
|---------|---------------|
| **Business Logic** | Rules, calculations, decisions |
| **Data Access** | Reading/writing to database |
| **Presentation** | Formatting for display |
| **Validation** | Input checking |
| **Authentication** | Identity verification |
| **Logging** | Recording events |

<br>

---

## Layered Architecture (SoC Applied)

```
┌─────────────────────────┐
│   Presentation Layer     │  ← UI / API controllers
├─────────────────────────┤
│   Business Logic Layer   │  ← Domain rules, services
├─────────────────────────┤
│   Data Access Layer      │  ← Repositories, DAOs
├─────────────────────────┤
│   Database / Storage     │  ← Persistence
└─────────────────────────┘
```

Each layer only talks to the layer **directly below** it.

```java
// Controller (Presentation)
class OrderController {
    private OrderService service;
    public OrderResponse createOrder(OrderRequest request) {
        Order order = service.placeOrder(request.toOrder());
        return OrderResponse.from(order);  // Formatting concern
    }
}

// Service (Business Logic)
class OrderService {
    private OrderRepository repo;
    public Order placeOrder(Order order) {
        validateOrder(order);    // Business rule
        calculateTotal(order);   // Business logic
        repo.save(order);        // Delegates persistence
        return order;
    }
}

// Repository (Data Access)
class OrderRepository {
    public void save(Order order) { /* SQL / ORM */ }
}
```

<br>

---

## SoC vs SRP

| SoC | SRP |
|-----|-----|
| Architectural level | Class level |
| Separate layers/modules | Single responsibility per class |
| "Don't mix concerns" | "One reason to change" |
| Broader concept | Specific application of SoC |

<br>

---

## Key Takeaways

1. **Don't mix business logic with I/O, formatting, or persistence**
2. **Layered architecture** is SoC applied at the system level
3. **Each layer has a clear, distinct responsibility**
4. **Changes in one concern shouldn't ripple to others**
