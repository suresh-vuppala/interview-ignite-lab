# Design a Vending Machine

Design a vending machine that accepts multiple payment methods, manages inventory, and dispenses products.

<br>

---

## Requirements

### Main Requirements
1. **Display products** with prices and availability
2. **Accept payment** — coins, bills, card
3. **Product selection** — select by code (A1, B2, etc.)
4. **Dispense product** and return change
5. **Inventory management** — track stock, refill
6. **Cancel transaction** — return inserted money

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **State** | VendingMachine states (Idle, CoinInserted, ProductSelected, Dispensing) | Clear state transitions |
| **Strategy** | Payment methods (coin, card, digital) | Swappable payment handling |

<br>

---

## Core Entities

```
VendingMachine
├─ state: VendingState
├─ inventory: Map<String, ProductSlot>
├─ currentBalance: double

VendingState (interface)
├── IdleState → CoinInsertedState → ProductSelectedState → DispensingState

Product: name, price, code
ProductSlot: product, quantity

PaymentMethod (interface)
├── CoinPayment, CardPayment
```

<br>

---

## Interview Tips
- State pattern is the clear winner here
- Discuss change-making algorithm (greedy with denominations)
- Handle: exact change required, out of stock, insufficient payment
