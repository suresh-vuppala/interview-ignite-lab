# Law of Demeter (LoD)

> **"Only talk to your immediate friends. Don't talk to strangers."**

A method should only call methods on:
1. Its own object (`this`)
2. Its parameters
3. Objects it creates
4. Its direct fields

<br>

---

## The Problem: Train Wreck

### ❌ Violates LoD — reaching through objects
```java
// "Train wreck" — chaining through multiple objects
double price = order.getCustomer().getAddress().getCity().getTaxRate();
// order knows about Customer, Address, City, TaxRate — too many dependencies!
```

### ✅ Follows LoD — ask, don't dig
```java
// Order delegates to its own customer
double price = order.getTaxRate();
// Inside Order:
public double getTaxRate() { return customer.getTaxRate(); }
// Inside Customer:
public double getTaxRate() { return address.getTaxRate(); }
// Each object only talks to its direct neighbor
```

<br>

---

## Practical Rule

**One dot is fine. Two dots is suspicious. Three dots is a violation.**
```java
obj.method()                    // ✅ Fine
obj.getX().method()             // ⚠️ Maybe OK
obj.getX().getY().method()      // ❌ Train wreck
obj.getX().getY().getZ().foo()  // ❌❌ Definitely wrong
```

**Exception:** Fluent APIs and builder patterns are OK:
```java
new QueryBuilder().select("*").from("users").where("age > 18").build(); // ✅ OK
```

<br>

---

## Key Takeaways

1. **Don't chain through objects** — each class should only know its direct neighbors
2. **"Tell, don't ask"** — ask the object to do something, don't dig into its internals
3. **Reduces coupling** — changes in deeply nested classes don't ripple outward
4. **Exception:** Fluent APIs / builders are fine (same object returned)
