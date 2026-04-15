# DRY vs DIE vs Abstraction

Sometimes **duplication is cheaper than the wrong abstraction**. This lesson covers the nuance that interviews love to test.

<br>

---

## DRY (Don't Repeat Yourself)
Remove duplication by extracting common logic.

## DIE (Duplication Is Evil)
Extreme DRY — remove ALL duplication at any cost.

## WET (Write Everything Twice)
Allow duplication until the third occurrence, then abstract.

<br>

---

## When DRY Goes Wrong

### ❌ Premature abstraction

```java
// Two similar-looking but DIFFERENT business rules
void processRefund(Order order) {
    double amount = order.getTotal() * 0.95;  // 5% restocking fee
    // ... refund logic
}

void processLoyaltyReward(Order order) {
    double amount = order.getTotal() * 0.95;  // 5% loyalty points
    // ... reward logic
}

// Developer: "Both multiply by 0.95! Let me DRY this up!"
// ❌ WRONG — they have DIFFERENT reasons to change
double applyFivePercentReduction(double total) { return total * 0.95; }
// What if refund fee changes to 10% but loyalty stays at 5%? This "shared" method breaks.
```

### ✅ Rule of Three
> **Duplicate code is OK until the THIRD time.** Then abstract.

On the third occurrence, you have enough examples to find the **right** abstraction.

<br>

---

## The Right Question

Before abstracting, ask:
1. **Do these duplicates change for the SAME reason?** → DRY it up
2. **Do they change for DIFFERENT reasons?** → Keep them separate
3. **Am I certain about the abstraction?** → If unsure, wait

<br>

---

## Key Takeaways

1. **Duplication is better than the wrong abstraction**
2. **Rule of Three** — wait for the third occurrence before abstracting
3. **Same reason to change → share code. Different reasons → keep separate.**
4. **In interviews: mention this nuance** — shows maturity
