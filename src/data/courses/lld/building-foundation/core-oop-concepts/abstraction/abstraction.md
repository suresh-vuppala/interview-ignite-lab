# Abstraction

Abstraction means exposing only the **essential features** of an object while hiding the implementation details. Users interact with a simplified interface without knowing internal complexity.

<br>

---

## Why It Matters in LLD Interviews

Every well-designed system uses abstraction layers. Interviewers evaluate:
- Can you define **clear contracts** (interfaces) between components?
- Do you know **when to use abstract class vs interface**?
- Can you design systems where components are **swappable**?

<br>

---

## Abstract Class vs Interface

| Feature | Abstract Class | Interface |
|---------|---------------|-----------|
| **Methods** | Abstract + concrete | All abstract (pre-Java 8), default methods (Java 8+) |
| **Fields** | Instance variables | Only `public static final` constants |
| **Constructors** | Yes | No |
| **Inheritance** | Single (`extends`) | Multiple (`implements`) |
| **Access modifiers** | Any | `public` only (methods) |
| **Use when** | Shared state + partial implementation | Pure contract / capability |

### When to Use Abstract Class
```java
abstract class DatabaseConnector {
    protected String connectionString;  // Shared state
    
    public DatabaseConnector(String connStr) {
        this.connectionString = connStr;  // Constructor
    }
    
    public void connect() {
        validateConnection();    // Shared logic
        openConnection();        // Abstract — subclass specific
    }
    
    protected void validateConnection() {
        if (connectionString == null) throw new IllegalStateException("No connection string");
    }
    
    protected abstract void openConnection();  // Subclass implements
}
```

### When to Use Interface
```java
interface Cacheable {
    void cache();
    void evict();
    boolean isCached();
}

interface Serializable {
    byte[] serialize();
    void deserialize(byte[] data);
}

// A class can implement MULTIPLE interfaces
class UserProfile implements Cacheable, Serializable { ... }
```

<br>

---

## Java 8+ Interface Features

```java
interface Logger {
    void log(String message);  // Abstract
    
    // Default method — provides implementation in interface
    default void logError(String message) {
        log("ERROR: " + message);
    }
    
    // Static method
    static Logger consoleLogger() {
        return message -> System.out.println(message);
    }
}
```

<br>

---

## Real-World LLD Example: Payment Gateway Abstraction

```java
// Interface — defines the contract
interface PaymentGateway {
    PaymentResult charge(String customerId, double amount);
    PaymentResult refund(String transactionId);
    PaymentStatus checkStatus(String transactionId);
}

// Concrete implementations hidden behind the interface
class StripeGateway implements PaymentGateway {
    public PaymentResult charge(String customerId, double amount) {
        // Stripe-specific API calls, authentication, etc.
        return new PaymentResult(true, "stripe_txn_123");
    }
    // ...
}

class PayPalGateway implements PaymentGateway {
    public PaymentResult charge(String customerId, double amount) {
        // PayPal-specific API calls
        return new PaymentResult(true, "paypal_txn_456");
    }
    // ...
}

// Client code — doesn't know or care which gateway is used
class OrderService {
    private PaymentGateway gateway;  // Abstraction!
    
    public OrderService(PaymentGateway gateway) {
        this.gateway = gateway;  // Injected — can swap freely
    }
    
    public void checkout(Order order) {
        PaymentResult result = gateway.charge(order.getCustomerId(), order.getTotal());
        // Works with Stripe, PayPal, or any future gateway
    }
}
```

<br>

---

## Common Interview Questions

1. **"What is abstraction?"** → Hiding complexity, exposing only what's needed
2. **"Abstract class vs Interface?"** → Abstract = partial impl + state; Interface = pure contract, multiple inheritance
3. **"Can an abstract class have a constructor?"** → Yes, called by subclass via `super()`
4. **"When to use abstract class?"** → Shared state/code among related classes
5. **"When to use interface?"** → Defining a capability that unrelated classes can implement

<br>

---

## Key Takeaways

1. **Interface = "can do"** (Flyable, Serializable, Cacheable)
2. **Abstract class = "is a" with shared code** (Animal, Shape, Payment)
3. **Program to interfaces** — depend on abstractions, not concretions
4. **Abstraction enables swappability** — change implementations without changing clients
5. **Java 8 blurred the line** — interfaces can have default methods, but still no state
