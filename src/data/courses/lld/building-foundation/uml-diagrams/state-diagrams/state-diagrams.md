# State Diagrams

State diagrams show the **different states an object can be in** and the **events/transitions** that move it between states. Essential for objects with complex lifecycle behavior.

<br>

---

## Why It Matters in LLD Interviews

Many LLD problems involve objects with states:
- **Order:** Created → Confirmed → Shipped → Delivered → Cancelled
- **Parking Spot:** Available → Occupied → Reserved → Maintenance
- **Ticket:** Open → In Progress → Resolved → Closed

<br>

---

## Core Elements

| Element | Purpose |
|---------|---------|
| **State** (rounded rectangle) | A condition the object is in |
| **Transition** (arrow) | Event that causes state change |
| **Guard** ([condition]) | Condition for transition |
| **Initial State** (●) | Starting state |
| **Final State** (⊙) | Terminal state |

<br>

---

## Example: Order Lifecycle

```
● ──→ [CREATED] ──pay()──→ [CONFIRMED] ──ship()──→ [SHIPPED]
            │                     │                      │
            │ cancel()            │ cancel()             │ deliver()
            ▼                     ▼                      ▼
        [CANCELLED]          [CANCELLED]           [DELIVERED]
                                                       │
                                                       │ return()
                                                       ▼
                                                  [RETURNED] → ⊙
```

<br>

---

## State Pattern Connection

State diagrams naturally map to the **State Design Pattern**:

```java
interface OrderState {
    void pay(Order order);
    void ship(Order order);
    void cancel(Order order);
}

class CreatedState implements OrderState {
    public void pay(Order order) { order.setState(new ConfirmedState()); }
    public void ship(Order order) { throw new IllegalStateException("Can't ship unpaid order"); }
    public void cancel(Order order) { order.setState(new CancelledState()); }
}
```

<br>

---

## Key Takeaways

1. **Essential for objects with lifecycle** (orders, tickets, accounts)
2. **Maps directly to State Pattern** in implementation
3. **Guard conditions** control when transitions are allowed
4. **Invalid transitions should throw exceptions** — enforce state machine rules
5. **Draw during interviews** when the problem has clear state transitions
