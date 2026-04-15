# Open-Closed Principle (OCP)

> **"Software entities should be open for extension, but closed for modification."** — Bertrand Meyer

You should be able to **add new behavior without changing existing code**. This is achieved through **abstraction and polymorphism**.

<br>

---

## Why It Matters in LLD Interviews

OCP is the most **design-pattern-relevant** SOLID principle. Interviewers check:
- Can you add a new type/variant **without modifying existing classes**?
- Do you use **interfaces/abstract classes** as extension points?
- Can you eliminate growing `if-else` / `switch` chains?

<br>

---

## The Problem: Modification-Heavy Code

### ❌ Violates OCP — must modify existing code for every new shape

```java
class AreaCalculator {
    public double calculateArea(Object shape) {
        if (shape instanceof Circle) {
            Circle c = (Circle) shape;
            return Math.PI * c.radius * c.radius;
        } else if (shape instanceof Rectangle) {
            Rectangle r = (Rectangle) shape;
            return r.width * r.height;
        } else if (shape instanceof Triangle) {   // ADDED — modified existing class!
            Triangle t = (Triangle) shape;
            return 0.5 * t.base * t.height;
        }
        // Every new shape = modify THIS method
        throw new IllegalArgumentException("Unknown shape");
    }
}
```

### ✅ Follows OCP — extend without modifying

```java
interface Shape {
    double area();  // Contract — each shape knows how to calculate its own area
}

class Circle implements Shape {
    private double radius;
    public Circle(double r) { this.radius = r; }
    public double area() { return Math.PI * radius * radius; }
}

class Rectangle implements Shape {
    private double width, height;
    public Rectangle(double w, double h) { this.width = w; this.height = h; }
    public double area() { return width * height; }
}

// NEW: Adding Triangle — NO modification to existing classes!
class Triangle implements Shape {
    private double base, height;
    public Triangle(double b, double h) { this.base = b; this.height = h; }
    public double area() { return 0.5 * base * height; }
}

class AreaCalculator {
    public double totalArea(List<Shape> shapes) {
        return shapes.stream().mapToDouble(Shape::area).sum();
        // This method NEVER changes — closed for modification
    }
}
```

<br>

---

## Techniques to Achieve OCP

### 1. Strategy Pattern
```java
interface DiscountStrategy { double apply(double price); }
class NoDiscount implements DiscountStrategy { ... }
class PercentageDiscount implements DiscountStrategy { ... }
class FlatDiscount implements DiscountStrategy { ... }
// Add new discount type = add new class, nothing else changes
```

### 2. Factory Pattern
```java
interface NotificationSender { void send(String msg); }
class NotificationFactory {
    static NotificationSender create(String type) {
        return switch(type) {
            case "email" -> new EmailSender();
            case "sms" -> new SMSSender();
            case "push" -> new PushSender();  // New type = add case + new class
            default -> throw new IllegalArgumentException();
        };
    }
}
```

### 3. Decorator Pattern
```java
interface DataSource { String read(); void write(String data); }
class FileDataSource implements DataSource { ... }
class EncryptionDecorator implements DataSource {
    private DataSource wrapped;
    // Adds encryption WITHOUT modifying FileDataSource
}
class CompressionDecorator implements DataSource {
    private DataSource wrapped;
    // Adds compression WITHOUT modifying any existing class
}
```

<br>

---

## Real-World LLD Example: Payment Processing

```java
interface PaymentProcessor {
    PaymentResult process(PaymentRequest request);
    boolean supports(PaymentMethod method);
}

class CreditCardProcessor implements PaymentProcessor {
    public boolean supports(PaymentMethod m) { return m == PaymentMethod.CREDIT_CARD; }
    public PaymentResult process(PaymentRequest req) { /* Stripe API */ }
}

class UPIProcessor implements PaymentProcessor {
    public boolean supports(PaymentMethod m) { return m == PaymentMethod.UPI; }
    public PaymentResult process(PaymentRequest req) { /* UPI API */ }
}

// Adding crypto payment — ZERO changes to existing processors!
class CryptoProcessor implements PaymentProcessor {
    public boolean supports(PaymentMethod m) { return m == PaymentMethod.CRYPTO; }
    public PaymentResult process(PaymentRequest req) { /* Blockchain API */ }
}

// Orchestrator — also doesn't change
class PaymentService {
    private List<PaymentProcessor> processors;
    
    public PaymentResult pay(PaymentRequest request) {
        return processors.stream()
            .filter(p -> p.supports(request.getMethod()))
            .findFirst()
            .orElseThrow(() -> new UnsupportedPaymentException())
            .process(request);
    }
}
```

<br>

---

## Common Interview Questions

1. **"What is OCP?"** → Open for extension (new behavior via new classes), closed for modification (don't change existing code)
2. **"How do you achieve it?"** → Interfaces, abstract classes, Strategy/Factory/Decorator patterns
3. **"Is it always possible?"** → Not 100% — some changes require modification. Goal is to minimize it.
4. **"How does OCP relate to polymorphism?"** → Polymorphism IS the mechanism that enables OCP

<br>

---

## Key Takeaways

1. **New behavior = new class**, not modifying existing ones
2. **Interfaces are the extension points** — program to interfaces
3. **Eliminates if-else chains** that grow with every new type
4. **Strategy, Factory, Decorator** are the primary OCP patterns
5. **Not an absolute rule** — some modifications are unavoidable, minimize them
