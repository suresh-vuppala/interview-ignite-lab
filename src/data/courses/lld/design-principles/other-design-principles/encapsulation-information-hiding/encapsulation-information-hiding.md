# Encapsulation & Information Hiding (Deep Dive)

This goes beyond basic getters/setters into **advanced techniques** that interviewers expect for senior-level LLD.

<br>

---

## 1. Defensive Copies

### ❌ Leaking mutable internal state
```java
class Schedule {
    private List<Event> events;
    
    public List<Event> getEvents() { return events; }  // Caller can modify!
}

// Attacker:
schedule.getEvents().clear();  // Destroyed all events!
```

### ✅ Return defensive copy
```java
class Schedule {
    private List<Event> events;
    
    public List<Event> getEvents() {
        return Collections.unmodifiableList(events);  // Read-only view
    }
    // OR: return new ArrayList<>(events);  // Deep copy
}
```

<br>

---

## 2. Immutable Objects

```java
// Fully immutable — the gold standard
public final class Money {
    private final double amount;
    private final String currency;
    
    public Money(double amount, String currency) {
        this.amount = amount;
        this.currency = currency;
    }
    
    public double getAmount() { return amount; }
    public String getCurrency() { return currency; }
    
    // Operations return NEW objects — never mutate
    public Money add(Money other) {
        if (!currency.equals(other.currency))
            throw new IllegalArgumentException("Currency mismatch");
        return new Money(amount + other.amount, currency);
    }
    
    public Money multiply(double factor) {
        return new Money(amount * factor, currency);
    }
}
```

### Immutability Rules:
1. Class is `final` — can't subclass
2. All fields are `private final`
3. No setters
4. Return new instances from operations
5. Defensive copy mutable parameters in constructor

<br>

---

## 3. Tell, Don't Ask

```java
// ❌ ASK for data, make decision outside
if (account.getBalance() >= amount) {
    account.setBalance(account.getBalance() - amount);
}

// ✅ TELL the object what to do
account.withdraw(amount);  // Object handles validation + state change internally
```

<br>

---

## Key Takeaways

1. **Defensive copies** for mutable collections in getters
2. **Immutable objects** are thread-safe, predictable, and bug-resistant
3. **Tell, don't ask** — objects should manage their own state
4. **`final` class + `final` fields + no setters = strongest encapsulation**
5. **In interviews: using these shows senior-level thinking**
