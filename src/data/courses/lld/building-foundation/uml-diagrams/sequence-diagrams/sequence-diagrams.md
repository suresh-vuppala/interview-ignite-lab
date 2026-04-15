# Sequence Diagrams

Sequence diagrams show **how objects interact over time** by depicting the order of messages exchanged between objects for a specific use case.

<br>

---

## Why It Matters in LLD Interviews

After drawing a class diagram, interviewers often ask: **"Walk me through the flow of [use case]."** Sequence diagrams help you:
- Show the **exact order of method calls**
- Identify **which object is responsible** for what
- Spot **missing classes or methods** in your design
- Demonstrate **concurrent or async behavior**

<br>

---

## Core Elements

### 1. Lifelines
Vertical dashed lines representing object instances.
```
  Customer        OrderService        PaymentGateway       Inventory
     |                 |                    |                   |
     |                 |                    |                   |
```

### 2. Messages
- **Synchronous** (solid arrow →): caller waits for response
- **Asynchronous** (open arrow →): caller doesn't wait
- **Return** (dashed arrow ← - -): response back

### 3. Activation Bars
Thin rectangles on lifelines showing when an object is processing.

<br>

---

## Example: Order Checkout Flow

```
Customer          OrderService      PaymentGateway     Inventory      EmailService
   |                   |                  |                |               |
   |---placeOrder()--->|                  |                |               |
   |                   |--charge()------->|                |               |
   |                   |                  |---process()--->|               |
   |                   |                  |<--result-------|               |
   |                   |<--paymentOK------|                |               |
   |                   |--reserveItems()--+--------------->|               |
   |                   |                  |                |--checkStock()  |
   |                   |<--reserved-------+----------------|               |
   |                   |--sendConfirmation()---+---------->|-------------->|
   |<--orderConfirmed--|                       |           |               |
   |                   |                       |           |               |
```

<br>

---

## Interview Tips

1. **Pick one critical flow** (e.g., "user places order")
2. **List participating objects** as lifelines
3. **Walk through step-by-step** — each message = a method call
4. **Show error paths** if time permits (payment failed, out of stock)
5. **Keep it readable** — 4-6 lifelines max

<br>

---

## Key Takeaways

1. **Shows temporal ordering** of interactions
2. **Each arrow = a method call** on the receiving object
3. **Helps validate your class diagram** — do the methods exist?
4. **Focus on one use case at a time**
5. **Practice drawing quickly** — you have limited interview time
