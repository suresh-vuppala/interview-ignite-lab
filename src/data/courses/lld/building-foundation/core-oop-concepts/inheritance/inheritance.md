# Inheritance

Inheritance allows a class (child/subclass) to inherit fields and methods from another class (parent/superclass), establishing an **IS-A relationship**.

<br>

---

## Why It Matters in LLD Interviews

Inheritance is essential for:
- Modeling **real-world hierarchies** (Vehicle → Car, Truck)
- **Code reuse** without duplication
- Enabling **polymorphism** (treating subtypes uniformly)

But overuse is a red flag — interviewers watch for **composition over inheritance** awareness.

<br>

---

## Types of Inheritance

### 1. Single Inheritance
```java
class Animal {
    protected String name;
    public void eat() { System.out.println(name + " is eating"); }
}

class Dog extends Animal {
    public void bark() { System.out.println(name + " barks!"); }
}
```

### 2. Multilevel Inheritance
```java
class Animal { ... }
class Dog extends Animal { ... }
class GoldenRetriever extends Dog { ... }  // Animal → Dog → GoldenRetriever
```

### 3. Hierarchical Inheritance
```java
class Shape { ... }
class Circle extends Shape { ... }
class Rectangle extends Shape { ... }
// Both Circle and Rectangle extend Shape
```

### 4. Multiple Inheritance (via Interfaces in Java)
```java
interface Flyable { void fly(); }
interface Swimmable { void swim(); }

class Duck implements Flyable, Swimmable {
    public void fly() { ... }
    public void swim() { ... }
}
```

> **Java doesn't support multiple class inheritance** (Diamond Problem). Use interfaces instead.

<br>

---

## The `super` Keyword

```java
class Employee {
    protected String name;
    protected double baseSalary;
    
    public Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }
    
    public double calculatePay() { return baseSalary; }
}

class Manager extends Employee {
    private double bonus;
    
    public Manager(String name, double baseSalary, double bonus) {
        super(name, baseSalary);  // Call parent constructor
        this.bonus = bonus;
    }
    
    @Override
    public double calculatePay() {
        return super.calculatePay() + bonus;  // Extend parent behavior
    }
}
```

<br>

---

## Method Overriding Rules

1. **Same method signature** (name, parameters, return type)
2. **Access modifier can be equal or less restrictive** (protected → public ✅, public → private ❌)
3. **Cannot override `final`, `static`, or `private` methods**
4. **Use `@Override` annotation** — catches typos at compile time

<br>

---

## When to Use Inheritance vs Composition

| Use Inheritance When | Use Composition When |
|---------------------|---------------------|
| True IS-A relationship | HAS-A relationship |
| Subclass IS a specialized parent | Object USES another object |
| `Dog IS-A Animal` | `Car HAS-A Engine` |
| Shared behavior + state | Shared behavior only |
| Stable hierarchy (won't change) | Flexible, changeable |

### ❌ Bad Inheritance
```java
class Stack extends ArrayList { ... }  // Stack IS-A ArrayList? No!
// Exposes add(index), get(index) — violates stack contract
```

### ✅ Better: Composition
```java
class Stack {
    private ArrayList data = new ArrayList();  // Stack HAS-A list
    public void push(Object item) { data.add(item); }
    public Object pop() { return data.remove(data.size() - 1); }
}
```

<br>

---

## Real-World LLD Example: Notification System

```java
abstract class Notification {
    protected String recipient;
    protected String message;
    protected LocalDateTime timestamp;
    
    public Notification(String recipient, String message) {
        this.recipient = recipient;
        this.message = message;
        this.timestamp = LocalDateTime.now();
    }
    
    public abstract void send();  // Each type sends differently
    
    public String formatMessage() { return "[" + timestamp + "] " + message; }
}

class EmailNotification extends Notification {
    private String subject;
    
    public EmailNotification(String recipient, String subject, String message) {
        super(recipient, message);
        this.subject = subject;
    }
    
    @Override
    public void send() {
        // Send email via SMTP
        System.out.println("Email to " + recipient + ": " + subject);
    }
}

class SMSNotification extends Notification {
    public SMSNotification(String phoneNumber, String message) {
        super(phoneNumber, message);
    }
    
    @Override
    public void send() {
        System.out.println("SMS to " + recipient + ": " + formatMessage());
    }
}
```

<br>

---

## Common Interview Questions

1. **"What is inheritance?"** → Child class inherits parent's fields/methods, IS-A relationship
2. **"Diamond problem?"** → Ambiguity when two parents have same method; Java solves with interfaces
3. **"When would you NOT use inheritance?"** → When relationship is HAS-A, or hierarchy is unstable
4. **"Can you override a private method?"** → No. Private methods aren't inherited.
5. **"Abstract class vs Interface?"** → Abstract = partial implementation + state; Interface = contract only (pre-Java 8)

<br>

---

## Key Takeaways

1. **Use inheritance for genuine IS-A relationships only**
2. **Prefer composition over inheritance** for flexibility
3. **Keep hierarchies shallow** — deep hierarchies are hard to understand
4. **Abstract classes** are great for shared state + partial implementation
5. **Always use `@Override`** to catch errors at compile time
