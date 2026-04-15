# Dependency Inversion Principle (DIP)

> **"High-level modules should not depend on low-level modules. Both should depend on abstractions."**
> **"Abstractions should not depend on details. Details should depend on abstractions."** — Robert C. Martin

<br>

---

## Why It Matters in LLD Interviews

DIP is the principle behind **Dependency Injection** — the most practically important pattern. Interviewers check:
- Do your high-level classes **depend on interfaces, not concrete classes**?
- Can you **swap implementations** without changing business logic?
- Do you understand **constructor injection vs setter injection**?

<br>

---

## The Problem: Tight Coupling

### ❌ Violates DIP — high-level depends on low-level

```java
class OrderService {
    private MySQLDatabase database = new MySQLDatabase();  // Concrete!
    private SMTPEmailSender emailSender = new SMTPEmailSender(); // Concrete!
    
    public void placeOrder(Order order) {
        database.save(order);              // Tied to MySQL
        emailSender.send("Order placed");  // Tied to SMTP
    }
}
// Can't test without real MySQL + SMTP server!
// Can't switch to PostgreSQL or SendGrid without modifying OrderService
```

### ✅ Follows DIP — depends on abstractions

```java
interface OrderRepository { void save(Order order); }
interface NotificationService { void send(String message); }

class OrderService {
    private final OrderRepository repository;       // Abstraction!
    private final NotificationService notifier;     // Abstraction!
    
    // Constructor injection — dependencies provided from outside
    public OrderService(OrderRepository repo, NotificationService notifier) {
        this.repository = repo;
        this.notifier = notifier;
    }
    
    public void placeOrder(Order order) {
        repository.save(order);          // Works with ANY repository
        notifier.send("Order placed");   // Works with ANY notifier
    }
}

// Concrete implementations (low-level details)
class MySQLOrderRepository implements OrderRepository { ... }
class PostgresOrderRepository implements OrderRepository { ... }
class EmailNotifier implements NotificationService { ... }
class SlackNotifier implements NotificationService { ... }

// Wiring (composition root)
OrderService service = new OrderService(
    new MySQLOrderRepository(),  // Can swap to Postgres anytime
    new EmailNotifier()          // Can swap to Slack anytime
);
```

<br>

---

## Dependency Injection Types

### 1. Constructor Injection (Preferred)
```java
class OrderService {
    private final OrderRepository repo;
    public OrderService(OrderRepository repo) { this.repo = repo; }
}
```
- ✅ Dependencies clear at construction time
- ✅ Object is always in valid state
- ✅ Immutable — can be `final`

### 2. Setter Injection
```java
class OrderService {
    private OrderRepository repo;
    public void setRepository(OrderRepository repo) { this.repo = repo; }
}
```
- ⚠️ Object may be used before dependency is set
- Use when dependency is optional

### 3. Interface Injection
```java
interface RepositoryAware {
    void setRepository(OrderRepository repo);
}
```
- Rarely used in practice

<br>

---

## The Dependency Flow

```
WITHOUT DIP:
  OrderService → MySQLDatabase        (high depends on low)

WITH DIP:
  OrderService → OrderRepository ← MySQLDatabase
  (high)          (abstraction)     (low)
  
Both depend on the ABSTRACTION, not on each other.
```

<br>

---

## Testing Benefit

```java
// Easy to test with DIP — inject mock
class OrderServiceTest {
    @Test
    void testPlaceOrder() {
        // Mock dependencies
        OrderRepository mockRepo = mock(OrderRepository.class);
        NotificationService mockNotifier = mock(NotificationService.class);
        
        OrderService service = new OrderService(mockRepo, mockNotifier);
        service.placeOrder(new Order());
        
        verify(mockRepo).save(any(Order.class));
        verify(mockNotifier).send("Order placed");
    }
}
```

Without DIP, you'd need a real database and email server to test!

<br>

---

## Common Interview Questions

1. **"What is DIP?"** → High-level shouldn't depend on low-level; both depend on abstractions
2. **"DIP vs Dependency Injection?"** → DIP is the principle; DI is the technique to achieve it
3. **"Why constructor injection over setter?"** → Ensures object is always valid, makes dependencies explicit
4. **"How does DIP help testing?"** → Inject mocks instead of real implementations

<br>

---

## Key Takeaways

1. **Depend on abstractions (interfaces), not concretions (classes)**
2. **Constructor injection is preferred** — makes dependencies explicit and immutable
3. **Enables testability** — inject mocks
4. **Enables swappability** — change DB, email provider without touching business logic
5. **DIP is the most practically impactful SOLID principle**
