# Liskov Substitution Principle (LSP)

> **"Objects of a superclass should be replaceable with objects of its subclasses without altering the correctness of the program."** — Barbara Liskov

If `Dog extends Animal`, then anywhere you use `Animal`, you should be able to use `Dog` without breaking anything.

<br>

---

## Why It Matters in LLD Interviews

LSP violations are **subtle bugs** that interviewers love to test. They check if your inheritance hierarchies are **truly IS-A relationships** or if subclasses break the contract.

<br>

---

## Classic Violation: Rectangle-Square Problem

### ❌ Violates LSP

```java
class Rectangle {
    protected int width, height;
    
    public void setWidth(int w) { this.width = w; }
    public void setHeight(int h) { this.height = h; }
    public int area() { return width * height; }
}

class Square extends Rectangle {
    @Override
    public void setWidth(int w) { this.width = w; this.height = w; } // Breaks contract!
    @Override
    public void setHeight(int h) { this.width = h; this.height = h; } // Breaks contract!
}

// Client code that breaks with Square:
void resize(Rectangle r) {
    r.setWidth(5);
    r.setHeight(10);
    assert r.area() == 50; // FAILS for Square! area() returns 100
}
```

The issue: `Square` changes the behavior of `setWidth`/`setHeight` — they are no longer independent, violating what clients expect from `Rectangle`.

### ✅ Fix: Separate abstractions

```java
interface Shape {
    double area();
}

class Rectangle implements Shape {
    private final int width, height;
    public Rectangle(int w, int h) { this.width = w; this.height = h; }
    public double area() { return width * height; }
}

class Square implements Shape {
    private final int side;
    public Square(int s) { this.side = s; }
    public double area() { return side * side; }
}
// No inheritance between Rectangle and Square — no LSP violation
```

<br>

---

## LSP Rules

1. **Preconditions cannot be strengthened** — subclass can't require MORE from callers
2. **Postconditions cannot be weakened** — subclass can't promise LESS
3. **Invariants must be preserved** — if parent guarantees X, subclass must too
4. **No unexpected exceptions** — subclass shouldn't throw exceptions parent doesn't

### Example: Breaking postcondition
```java
class Bird {
    public void fly() { /* moves through air */ }
}

class Penguin extends Bird {
    @Override
    public void fly() { throw new UnsupportedOperationException(); } // ❌ Breaks LSP!
}

// Fix: Don't make Penguin extend Bird if it can't fly
interface Bird { void eat(); }
interface FlyingBird extends Bird { void fly(); }

class Sparrow implements FlyingBird { /* can fly */ }
class Penguin implements Bird { /* can't fly — and doesn't claim to */ }
```

<br>

---

## Common Interview Questions

1. **"What is LSP?"** → Subtype must be substitutable for parent without breaking behavior
2. **"Rectangle-Square example?"** → Square changes setWidth/setHeight contract — violates LSP
3. **"How to detect violations?"** → Look for: `instanceof` checks, overridden methods that throw exceptions, changed semantics
4. **"How to fix?"** → Rethink the hierarchy — maybe they shouldn't be parent-child

<br>

---

## Key Takeaways

1. **"IS-A" must be behavioral, not just structural** — Penguin IS-A Bird structurally but NOT behaviorally (can't fly)
2. **Subclass should strengthen or maintain contract**, never weaken it
3. **If you need `instanceof`** checks after substitution, LSP is violated
4. **Fix by rethinking hierarchy** — use interfaces or separate abstractions
5. **Design by contract** — define what callers can expect
