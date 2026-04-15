# Design a Vending Machine

Design a vending machine that accepts payments, manages inventory, and dispenses products with change.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Display products** — show name, price, availability, product code (A1, B2)
2. **Accept payment** — coins ($0.25, $0.50, $1.00), bills ($1, $5)
3. **Product selection** — select by code, validate payment covers price
4. **Dispense product** — eject product from slot
5. **Return change** — calculate and return exact change
6. **Cancel transaction** — return all inserted money at any point
7. **Inventory management** — track stock per product slot

### Extended Requirements (If Time Permits)

1. Card payment (credit/debit)
2. Digital wallet / QR code payment
3. Admin panel — refill products, collect money, view sales report
4. Product expiry tracking
5. Maintenance mode — disable machine for servicing
6. Remote monitoring — alert admin when product/cash is low

<br>

---

## Constraints

- Maximum 10 product slots (A1-A5, B1-B5)
- Each slot holds max 20 items
- Product price range: $0.50 to $10.00
- Accepted coins: $0.25, $0.50, $1.00
- Accepted bills: $1, $5
- Change returned in coins only
- Maximum $20 total per transaction
- Session timeout: 30 seconds after last interaction

<br>

---

## Identify Primary Actors

1. **Customer** — purchases products
   - Actions: view display, insert money, select product, collect product + change, cancel

2. **Admin/Operator** — maintains machine
   - Actions: refill products, collect cash, set prices, view sales report, set maintenance mode

3. **Vending Machine** — automated processing
   - Actions: validate payment, dispense product, calculate change, update inventory

<br>

---

## Core Entities

### 1. VendingMachine
- **Attributes**: state: VendingState, inventory: Map<String, ProductSlot>, balance, selectedProduct
- **Responsibilities**: Manage state transitions, coordinate payment and dispensing

### 2. VendingState (Interface — State Pattern)
- **Methods**: insertMoney(), selectProduct(), dispense(), cancel()
- **Implementations**: IdleState, HasMoneyState, DispensingState, MaintenanceState

### 3. Product
- **Attributes**: code, name, price
- **Responsibilities**: Store product information

### 4. ProductSlot
- **Attributes**: product, quantity
- **Responsibilities**: Track inventory for a specific slot

### 5. CoinInventory
- **Attributes**: coins: Map<Denomination, Integer>
- **Responsibilities**: Track available coins for change, calculate optimal change

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| VendingMachine | has | VendingState | Composition (◆) |
| VendingMachine | has | ProductSlot[] | Composition (◆) |
| VendingMachine | has | CoinInventory | Composition (◆) |
| ProductSlot | contains | Product | Association |
| IdleState | implements | VendingState | Implementation |
| HasMoneyState | implements | VendingState | Implementation |
| DispensingState | implements | VendingState | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  VendingMachine
  -state: VendingState ◆
  -inventory: Map<code, ProductSlot> ◆
  -coinInventory: CoinInventory ◆
  -balance: double
       │
       ▼
  <<interface>> VendingState
  +insertMoney(), +selectProduct()
  +dispense(), +cancel()
       △
  ┌────┼──────────┬──────────────┐
Idle  HasMoney  Dispensing  Maintenance


  ProductSlot ──→ Product
  -quantity        -code, -name, -price


  CoinInventory
  -coins: Map<Denomination, count>
  +calculateChange(amount): Map<Denomination, count>
  +hasExactChange(amount): boolean
```

<br>

---

## Design Patterns Used

### 1. **State Pattern**
- **Where**: VendingMachine states (Idle → HasMoney → Dispensing → Idle)
- **Why**: Behavior changes completely per state — same action (selectProduct) does different things in Idle vs HasMoney
- **Benefit**: Clean state transitions, no complex if-else on state variable

### 2. **Strategy Pattern** (optional)
- **Where**: Payment methods (Coin, Bill, Card, Digital)
- **Why**: Different payment methods have different processing logic
- **Benefit**: Add new payment types without modifying machine core

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Single user interaction**: Physical vending machine is single-threaded (one customer at a time)
- **Admin operations**: Lock machine during refill/maintenance — set MaintenanceState
- **Inventory update**: Atomic decrement on dispense to prevent double-dispense

### Race Conditions Handled
- **Timeout during payment**: Timer thread resets machine to Idle, returns inserted money
- **Power failure during dispense**: Transaction log for reconciliation

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Exact change required** — machine can't make change for large bill → display "Exact Change Only"
2. **Product out of stock** — reject selection, show "Sold Out" for that slot
3. **Insufficient payment** — show "Insert $X.XX more"
4. **Overpayment** — dispense product + return change
5. **All products out of stock** — display "Machine Empty — Out of Service"
6. **Cancel after partial payment** — return all inserted money
7. **Bill jam** — set error state, refund via separate mechanism
8. **Multiple rapid coin insertions** — queue and process sequentially
9. **Negative change calculation** — should never happen, but guard with assertion

### Error Handling Strategy
- **OutOfStockException**: Show "Sold Out" on display, suggest alternatives
- **InsufficientPaymentException**: Show remaining amount needed
- **ChangeUnavailableException**: "Exact Change Only" mode
- **HardwareException**: Set MaintenanceState, alert admin

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including State pattern for machine flow, Product/ProductSlot inventory management, and change calculation logic.
