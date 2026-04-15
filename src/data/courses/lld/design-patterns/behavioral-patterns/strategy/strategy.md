# Strategy Pattern

> **Intent:** Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.

<br>

---

## When to Use

- **Multiple algorithms** for the same task (sorting, pricing, validation, routing)
- **Eliminate if-else/switch** chains that select behavior by type
- **Change behavior at runtime** — swap algorithm without changing client
- **Open-Closed Principle** — add new algorithms without modifying existing code

<br>

---

## Structure

```
Client → Strategy (interface)
              ├─ ConcreteStrategyA
              ├─ ConcreteStrategyB
              └─ ConcreteStrategyC
```

Client holds a reference to Strategy interface, calls it. Concrete strategies are swappable.

<br>

---

## Example: Payment Processing

```java
interface PaymentStrategy {
    boolean pay(double amount);
    String getName();
}

class CreditCardPayment implements PaymentStrategy {
    private String cardNumber;
    public CreditCardPayment(String card) { this.cardNumber = card; }
    public boolean pay(double amount) {
        System.out.println("Paid $" + amount + " via Credit Card " + cardNumber.substring(12));
        return true;
    }
    public String getName() { return "Credit Card"; }
}

class UPIPayment implements PaymentStrategy {
    private String upiId;
    public UPIPayment(String upi) { this.upiId = upi; }
    public boolean pay(double amount) {
        System.out.println("Paid ₹" + amount + " via UPI " + upiId);
        return true;
    }
    public String getName() { return "UPI"; }
}

class WalletPayment implements PaymentStrategy {
    private double balance;
    public WalletPayment(double balance) { this.balance = balance; }
    public boolean pay(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        System.out.println("Paid $" + amount + " from wallet. Balance: $" + balance);
        return true;
    }
    public String getName() { return "Wallet"; }
}

// Context — uses strategy, doesn't know which one
class ShoppingCart {
    private PaymentStrategy paymentStrategy;
    
    public void setPaymentStrategy(PaymentStrategy strategy) {
        this.paymentStrategy = strategy;
    }
    
    public boolean checkout(double total) {
        if (paymentStrategy == null) throw new IllegalStateException("No payment method set");
        return paymentStrategy.pay(total);
    }
}
```

<br>

---

## Strategy vs State

| Strategy | State |
|----------|-------|
| **Client chooses** the algorithm | **Object transitions** between states internally |
| Algorithms are **interchangeable alternatives** | States have **specific transitions** |
| Client is aware of strategies | Client may not know about state changes |
| `cart.setPaymentStrategy(new UPI())` | `order.ship()` → state changes internally |

<br>

---

## Common Interview Questions

1. **"What is Strategy pattern?"** → Encapsulate algorithms behind an interface, swap at runtime
2. **"How does it eliminate if-else?"** → Each branch becomes a separate strategy class
3. **"Strategy vs Template Method?"** → Strategy uses composition (HAS-A); Template uses inheritance (IS-A)
4. **"Real Java examples?"** → `Comparator`, `java.util.function.*`, `Collections.sort(list, comparator)`

<br>

---

## Key Takeaways

1. **Encapsulate algorithms** behind a common interface
2. **Swap at runtime** — change behavior without changing client code
3. **Eliminates conditional logic** — no more if-else chains for type checking
4. **Most commonly used** behavioral pattern in LLD interviews
5. **Java lambdas** are essentially inline strategy implementations
