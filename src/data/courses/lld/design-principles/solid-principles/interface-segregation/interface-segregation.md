# Interface Segregation Principle (ISP)

> **"No client should be forced to depend on methods it does not use."** — Robert C. Martin

Instead of one fat interface with many methods, create **multiple small, focused interfaces**.

<br>

---

## Why It Matters in LLD Interviews

ISP prevents **"fat interface" bloat** — a common design smell. Interviewers watch for:
- Are your interfaces **focused on one capability**?
- Do implementors need to leave methods **empty or throw exceptions**? (Red flag!)

<br>

---

## The Problem: Fat Interface

### ❌ Violates ISP

```java
interface Worker {
    void work();
    void eat();
    void sleep();
    void attendMeeting();
    void writeReport();
}

class Robot implements Worker {
    public void work() { /* OK */ }
    public void eat() { /* Robots don't eat! */ }           // Forced to implement
    public void sleep() { throw new UnsupportedOperationException(); } // ISP violation!
    public void attendMeeting() { /* Robots don't meet! */ }
    public void writeReport() { /* Maybe? */ }
}
```

### ✅ Follows ISP — segregated interfaces

```java
interface Workable { void work(); }
interface Feedable { void eat(); }
interface Reportable { void writeReport(); }
interface Meetable { void attendMeeting(); }

class Human implements Workable, Feedable, Reportable, Meetable {
    public void work() { ... }
    public void eat() { ... }
    public void writeReport() { ... }
    public void attendMeeting() { ... }
}

class Robot implements Workable, Reportable {
    public void work() { ... }
    public void writeReport() { ... }
    // No eat(), sleep(), or attendMeeting() — not forced!
}
```

<br>

---

## Real-World LLD Example: Printer System

```java
// ❌ Fat interface
interface Machine {
    void print(Document d);
    void scan(Document d);
    void fax(Document d);
    void staple(Document d);
}
// Simple printer can't scan, fax, or staple!

// ✅ Segregated
interface Printer { void print(Document d); }
interface Scanner { void scan(Document d); }
interface Fax { void fax(Document d); }

class SimplePrinter implements Printer {
    public void print(Document d) { ... }
}

class MultiFunctionPrinter implements Printer, Scanner, Fax {
    public void print(Document d) { ... }
    public void scan(Document d) { ... }
    public void fax(Document d) { ... }
}
```

<br>

---

## Common Interview Questions

1. **"What is ISP?"** → Clients shouldn't depend on methods they don't use
2. **"How to detect violations?"** → Empty method implementations or `throw UnsupportedOperationException()`
3. **"Isn't many small interfaces messy?"** → Better than forcing classes to implement irrelevant methods
4. **"ISP vs SRP?"** → SRP = one reason to change (class level); ISP = focused interfaces (interface level)

<br>

---

## Key Takeaways

1. **Many small interfaces > one large interface**
2. **If implementor leaves methods empty → split the interface**
3. **Each interface = one capability/role**
4. **Classes compose multiple interfaces** as needed
5. **ISP enables flexible, testable designs** — mock only what you use
