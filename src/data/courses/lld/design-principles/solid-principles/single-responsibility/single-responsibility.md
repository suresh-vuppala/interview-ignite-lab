# Single Responsibility Principle (SRP)

> **"A class should have only one reason to change."** — Robert C. Martin

A class should do **one thing and do it well**. If a class has multiple responsibilities, changes to one responsibility risk breaking the other.

<br>

---

## Why It Matters in LLD Interviews

SRP is the **#1 principle interviewers check**. When you design classes, they look for:
- Does each class have a **clear, focused purpose**?
- Are you mixing **business logic with I/O, formatting, or persistence**?
- Can you **articulate the single responsibility** of each class?

<br>

---

## Identifying SRP Violations

### The "And" Test
If you describe a class using "AND", it likely violates SRP:
- ❌ "This class validates orders AND calculates discounts AND sends emails"
- ✅ "This class validates orders" (one thing)

### The "Reason to Change" Test
Count how many reasons a class might change:
- Business rules change → modify logic
- Email template changes → modify formatting
- Database schema changes → modify persistence

If multiple → SRP violation.

<br>

---

## Example: Before and After

### ❌ Violates SRP — Employee class does everything

```java
class Employee {
    private String name;
    private double salary;
    
    // Responsibility 1: Business logic
    public double calculatePay() {
        return salary + calculateBonus();
    }
    
    // Responsibility 2: Persistence
    public void saveToDatabase() {
        // SQL insert/update logic
        Connection conn = DriverManager.getConnection("jdbc:...");
        PreparedStatement ps = conn.prepareStatement("INSERT INTO employees...");
        ps.executeUpdate();
    }
    
    // Responsibility 3: Reporting
    public String generatePaySlip() {
        return "Pay Slip\n" + name + "\nTotal: $" + calculatePay();
    }
    
    // Responsibility 4: Notification
    public void sendPaySlipEmail() {
        // SMTP email sending logic
    }
}
// 4 reasons to change! Database, email, pay rules, report format
```

### ✅ Follows SRP — each class has one job

```java
// Responsibility 1: Employee data + business rules
class Employee {
    private String name;
    private double salary;
    
    public double calculatePay() { return salary + calculateBonus(); }
    public String getName() { return name; }
}

// Responsibility 2: Persistence
class EmployeeRepository {
    public void save(Employee employee) { /* Database logic */ }
    public Employee findById(int id) { /* Query logic */ }
}

// Responsibility 3: Report generation
class PaySlipGenerator {
    public String generate(Employee employee) {
        return "Pay Slip\n" + employee.getName() + "\nTotal: $" + employee.calculatePay();
    }
}

// Responsibility 4: Notification
class PaySlipNotifier {
    private EmailService emailService;
    
    public void notify(Employee employee, String paySlip) {
        emailService.send(employee.getEmail(), "Your Pay Slip", paySlip);
    }
}
```

Now each class has **exactly one reason to change**.

<br>

---

## Real-World LLD Application: Invoice System

```java
// ❌ God class
class Invoice {
    void calculateTotal() { ... }
    void applyDiscount() { ... }
    void saveToDB() { ... }
    void printInvoice() { ... }
    void emailInvoice() { ... }
}

// ✅ SRP applied
class Invoice { /* Data + total calculation */ }
class InvoiceRepository { /* Save/load */ }
class InvoicePrinter { /* Format for printing */ }
class InvoiceEmailer { /* Send via email */ }
class DiscountCalculator { /* Apply discount rules */ }
```

<br>

---

## How to Apply in Interviews

1. **Identify the nouns** in requirements → each becomes a class
2. **Group related behaviors** with their data
3. **Separate cross-cutting concerns**: persistence, logging, notification, formatting
4. **Ask yourself**: "If X changes, which classes need to change?"
5. **If the answer is more than one class for unrelated reasons → refactor**

<br>

---

## Common Pitfalls

| Pitfall | Why It's Wrong |
|---------|---------------|
| **God Object** | One class does everything — 500+ lines |
| **Mixing I/O with Logic** | Business rules + database queries in one class |
| **Report + Calculate** | Formatting + computation in same method |
| **Over-splitting** | One method per class goes too far — use judgment |

<br>

---

## Common Interview Questions

1. **"What is SRP?"** → A class should have only one reason to change
2. **"How do you identify violations?"** → The "AND" test or counting reasons to change
3. **"Isn't splitting into many classes over-engineering?"** → Balance is key — split by responsibility, not by method count
4. **"How does SRP relate to other SOLID principles?"** → SRP is the foundation; others build on it

<br>

---

## Key Takeaways

1. **One class = one responsibility = one reason to change**
2. **The "AND" test** quickly identifies violations
3. **Separate: business logic, persistence, presentation, notification**
4. **SRP makes code easier to test** — each class can be tested independently
5. **Don't over-apply** — grouping related methods is fine
