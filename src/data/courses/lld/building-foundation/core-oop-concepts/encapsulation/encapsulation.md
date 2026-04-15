# Encapsulation

Encapsulation is the bundling of data (fields) and the methods that operate on that data into a single unit (class), while restricting direct access to some of the object's components.

<br>

---

## Why It Matters in LLD Interviews

Encapsulation is the **most practical OOP pillar** — every class you design in an interview uses it. Interviewers evaluate whether you:
- Make fields private and expose only necessary behavior
- Protect invariants (e.g., balance can't go negative)
- Use getters/setters only when truly needed (not blindly)

<br>

---

## The Two Aspects of Encapsulation

### 1. Data Bundling
Group related data and behavior into a single class.

```java
// ❌ Procedural style — data scattered
String accountName;
double accountBalance;

void deposit(String name, double balance, double amount) { ... }
```

```java
// ✅ Encapsulated — data + behavior together
class BankAccount {
    private String name;
    private double balance;
    
    public void deposit(double amount) {
        if (amount > 0) this.balance += amount;
    }
}
```

### 2. Information Hiding
Control access to internal state using **access modifiers**.

| Modifier | Class | Package | Subclass | World |
|----------|:-----:|:-------:|:--------:|:-----:|
| `private` | ✅ | ❌ | ❌ | ❌ |
| `default` | ✅ | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ | ✅ |

<br>

---

## Protecting Invariants

The key purpose: **ensure object state is always valid**.

```java
class Temperature {
    private double kelvin;  // Kelvin is always >= 0
    
    public Temperature(double kelvin) {
        if (kelvin < 0) throw new IllegalArgumentException("Kelvin can't be negative");
        this.kelvin = kelvin;
    }
    
    public double getCelsius() { return kelvin - 273.15; }
    public double getFahrenheit() { return kelvin * 9.0/5.0 - 459.67; }
    
    // No setKelvin() — immutable after construction (even better!)
}
```

Without encapsulation, anyone could set `kelvin = -500`, breaking physics.

<br>

---

## Getters/Setters: Use Wisely

### ❌ Anti-pattern: Blind getters/setters for every field

```java
class User {
    private String name;
    private String password;
    
    public String getPassword() { return password; }    // WHY expose this?!
    public void setPassword(String p) { this.password = p; } // No validation!
}
```

### ✅ Better: Expose behavior, not data

```java
class User {
    private String name;
    private String passwordHash;
    
    public boolean authenticate(String password) {
        return hash(password).equals(passwordHash);  // Expose behavior
    }
    
    public void changePassword(String oldPass, String newPass) {
        if (!authenticate(oldPass)) throw new SecurityException("Wrong password");
        if (newPass.length() < 8) throw new IllegalArgumentException("Too short");
        this.passwordHash = hash(newPass);  // Validate then change
    }
}
```

<br>

---

## Real-World LLD Example: Wallet System

```java
class Wallet {
    private double balance;
    private List<Transaction> history;
    
    public Wallet(double initialBalance) {
        this.balance = Math.max(0, initialBalance);
        this.history = new ArrayList<>();
    }
    
    public double getBalance() { return balance; }  // Read-only access
    
    public void credit(double amount, String reason) {
        if (amount <= 0) throw new IllegalArgumentException("Amount must be positive");
        balance += amount;
        history.add(new Transaction(TransactionType.CREDIT, amount, reason));
    }
    
    public void debit(double amount, String reason) {
        if (amount <= 0) throw new IllegalArgumentException("Amount must be positive");
        if (amount > balance) throw new InsufficientFundsException();
        balance -= amount;
        history.add(new Transaction(TransactionType.DEBIT, amount, reason));
    }
    
    public List<Transaction> getHistory() {
        return Collections.unmodifiableList(history);  // Defensive copy!
    }
}
```

**Key encapsulation decisions:**
- `balance` is private — only changed via `credit()`/`debit()`
- `history` returned as unmodifiable — prevents external mutation
- Invariants enforced: balance can't go negative, amounts must be positive

<br>

---

## Common Interview Questions

1. **"What is encapsulation?"** → Bundling data + methods, restricting access to protect invariants
2. **"Difference between encapsulation and abstraction?"** → Encapsulation = hiding *how*, Abstraction = hiding *what*
3. **"Why not just make everything public?"** → Breaks invariants, couples code to internals, makes refactoring impossible
4. **"When should you NOT use getters?"** → When exposing mutable internal state (return defensive copies)

<br>

---

## Key Takeaways

1. **Fields should be private by default** — expose behavior, not data
2. **Protect invariants** — validation in methods, not relying on callers
3. **Defensive copies** for mutable collections returned from getters
4. **Not every field needs a getter/setter** — ask "does the outside world need this?"
5. **Immutability is the strongest form of encapsulation**
