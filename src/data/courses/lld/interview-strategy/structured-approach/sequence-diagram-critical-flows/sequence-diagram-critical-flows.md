# Step 5: Sequence Diagram for Critical Flows

> **"Walk me through what happens when a user [does X]"** — this is the most common follow-up after your class diagram.

<br>

---

## When to Draw a Sequence Diagram

- Interviewer asks: "Walk me through the flow of..."
- **Complex interaction** involving 3+ objects
- **Concurrent operations** where order matters
- **State transitions** (order placed → paid → shipped)

<br>

---

## Speed Drawing Technique (3-5 minutes)

### Step 1: List Participants (30 sec)
Write object names across the top:
```
Customer    ParkingService    SpotFinder    PaymentService    Ticket
```

### Step 2: Draw the Happy Path (2 min)
```
Customer → ParkingService: parkVehicle(vehicle)
ParkingService → SpotFinder: findAvailableSpot(vehicleType)
SpotFinder → ParkingService: spot
ParkingService → Ticket: create(vehicle, spot)
ParkingService → Customer: ticket
```

### Step 3: Add Error Path (1-2 min)
```
SpotFinder → ParkingService: null (no spot available)
ParkingService → Customer: ParkingFullException
```

<br>

---

## Example: Order Checkout Flow

```
Customer      OrderService     Inventory      PaymentGateway     EmailService
   │               │               │               │                  │
   │──placeOrder()─→│               │               │                  │
   │               │──checkStock()─→│               │                  │
   │               │←──available────│               │                  │
   │               │──charge()──────────────────────→│                  │
   │               │               │               │──process()        │
   │               │←──paymentOK───────────────────│                  │
   │               │──reduceStock()→│               │                  │
   │               │──sendConfirm()────────────────────────────────────→│
   │←──orderConfirm│               │               │                  │
```

<br>

---

## What Interviewers Look For

| Signal | What It Shows |
|--------|--------------|
| **Clear participants** | You know which objects are involved |
| **Method names on arrows** | You've defined interfaces well |
| **Error handling path** | You think about failure cases |
| **Consistent with class diagram** | Your design is coherent |
| **Verbal explanation** | You can communicate your design clearly |

<br>

---

## Tips for Interview Success

1. **Pick THE most critical flow** — not a trivial one
2. **4-6 participants max** — more is unreadable
3. **Name the methods** on each arrow — shows your API is real
4. **Show at least one error path** — "What if payment fails?"
5. **Talk through it:** "First, the customer calls placeOrder, which asks Inventory to check stock..."

<br>

---

## Key Takeaways

1. **Sequence diagram validates your class diagram** — do the methods exist?
2. **Happy path first, error path second**
3. **Each arrow = a method call** — keep names consistent with your interfaces
4. **3-5 minutes is enough** — don't over-detail
5. **Practice drawing quickly** — you have limited interview time
