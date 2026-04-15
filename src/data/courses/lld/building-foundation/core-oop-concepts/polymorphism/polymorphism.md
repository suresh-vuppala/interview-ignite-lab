# Polymorphism

Polymorphism means "many forms" — the ability of an object to take different forms and behave differently based on context.

<br>

---

## Why It Matters in LLD Interviews

Polymorphism is the **foundation of extensible design**. Every Strategy, Factory, and Observer pattern relies on it. Interviewers check if you can:
- Write code that depends on abstractions, not concrete classes
- Distinguish compile-time vs runtime polymorphism
- Use it to eliminate `if-else` / `switch` chains

<br>

---

## Two Types of Polymorphism

### 1. Compile-Time (Static) — Method Overloading

Same method name, different parameter lists. Resolved at **compile time**.

```java
class Calculator {
    public int add(int a, int b) { return a + b; }
    public double add(double a, double b) { return a + b; }
    public int add(int a, int b, int c) { return a + b + c; }
    // Compiler picks the right method based on arguments
}
```

**Rules:**
- Different number of parameters, OR
- Different parameter types, OR
- Different parameter order
- Return type alone does NOT count

### 2. Runtime (Dynamic) — Method Overriding

Subclass provides specific implementation. Resolved at **runtime** via virtual dispatch.

```java
abstract class Shape {
    abstract double area();
}

class Circle extends Shape {
    private double radius;
    public Circle(double r) { this.radius = r; }
    
    @Override
    double area() { return Math.PI * radius * radius; }
}

class Rectangle extends Shape {
    private double width, height;
    public Rectangle(double w, double h) { this.width = w; this.height = h; }
    
    @Override
    double area() { return width * height; }
}

// Runtime polymorphism in action:
Shape s = new Circle(5);       // Declared as Shape
System.out.println(s.area());  // Calls Circle.area() — decided at RUNTIME
```

<br>

---

## Eliminating if-else with Polymorphism

### ❌ Before: Switch/if-else chain
```java
double calculateDiscount(String customerType, double amount) {
    if (customerType.equals("REGULAR")) return amount * 0.05;
    else if (customerType.equals("PREMIUM")) return amount * 0.15;
    else if (customerType.equals("VIP")) return amount * 0.25;
    else return 0;
    // Adding new type = modify this method (violates Open-Closed)
}
```

### ✅ After: Polymorphism
```java
interface DiscountStrategy {
    double calculate(double amount);
}

class RegularDiscount implements DiscountStrategy {
    public double calculate(double amount) { return amount * 0.05; }
}
class PremiumDiscount implements DiscountStrategy {
    public double calculate(double amount) { return amount * 0.15; }
}
class VIPDiscount implements DiscountStrategy {
    public double calculate(double amount) { return amount * 0.25; }
}

// Usage — no if-else needed!
DiscountStrategy strategy = getStrategyForCustomer(customer);
double discount = strategy.calculate(amount);
// Adding new type = add new class (Open-Closed satisfied)
```

<br>

---

## Common Interview Questions

1. **"Overloading vs Overriding?"** → Overloading = same name different params (compile-time); Overriding = subclass redefines parent method (runtime)
2. **"Can you override a static method?"** → No. Static methods belong to the class, not instances. This is method hiding.
3. **"What is dynamic dispatch?"** → JVM determines at runtime which overridden method to call based on actual object type
4. **"How does polymorphism help extensibility?"** → New types added without modifying existing code (Open-Closed Principle)

<br>

---

## Key Takeaways

1. **Compile-time polymorphism** = overloading (convenience)
2. **Runtime polymorphism** = overriding (extensibility, the powerful one)
3. **Program to interfaces** — declare variables as abstract types
4. **Polymorphism eliminates if-else chains** — central to Strategy, Factory patterns
5. **@Override annotation** always — catches errors early
