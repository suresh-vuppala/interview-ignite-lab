# Meaningful Naming & Readability

> "Code is read 10x more often than it is written."

<br>

---

## Naming Rules

### Classes: Nouns
```java
// ❌                    // ✅
class Manager { }        class OrderProcessor { }
class Data { }           class UserProfile { }
class Info { }           class PaymentResult { }
```

### Methods: Verbs
```java
// ❌                    // ✅
class Order {            class Order {
    void order() {}          void place() {}
    int total() {}           int calculateTotal() {}
    boolean check() {}       boolean isEligibleForDiscount() {}
}
```

### Booleans: is/has/can/should
```java
// ❌                    // ✅
boolean flag;            boolean isActive;
boolean status;          boolean hasPermission;
boolean open;            boolean canEdit;
```

### Constants: SCREAMING_SNAKE
```java
static final int MAX_RETRY_COUNT = 3;
static final String DEFAULT_CURRENCY = "USD";
```

<br>

---

## Avoid These

| Bad | Better | Why |
|-----|--------|-----|
| `d` | `elapsedTimeInDays` | Single letters are cryptic |
| `list1` | `activeUsers` | Meaningless names |
| `temp` | `swapBuffer` | Explain purpose |
| `processData()` | `validateAndSaveOrder()` | Be specific |
| `doStuff()` | `sendNotification()` | Describe action |

<br>

---

## Key Takeaways

1. **Names should reveal intent** — no comments needed to explain
2. **Classes = nouns, Methods = verbs, Booleans = predicates**
3. **Searchable names** — `MAX_RETRY_COUNT` not `3`
4. **Consistent naming conventions** across the codebase
5. **If you need a comment to explain a variable name, rename it**
