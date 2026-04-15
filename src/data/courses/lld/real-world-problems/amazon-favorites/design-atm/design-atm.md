# Design an ATM

Design an ATM (Automated Teller Machine) system that supports cash withdrawal, deposit, balance inquiry, and PIN management.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Card authentication** — insert card, enter and verify PIN
2. **Balance inquiry** — check current account balance
3. **Cash withdrawal** — select amount, dispense money, update balance
4. **Cash deposit** — accept cash envelope, update balance
5. **PIN change** — change PIN after successful authentication
6. **Cash dispenser** — dispense optimal denomination mix ($100, $50, $20, $10)
7. **Transaction receipt** — print or email transaction details

### Extended Requirements (If Time Permits)

1. Mini statement (last 5 transactions)
2. Fund transfer between accounts
3. Daily withdrawal limit ($5,000)
4. Multiple account types (Savings, Checking)
5. Low cash alert for ATM admin
6. Card retention after 3 failed PIN attempts

<br>

---

## Constraints

- Maximum withdrawal per transaction: $2,000
- Daily withdrawal limit: $5,000
- PIN: exactly 4 digits
- Max failed PIN attempts: 3 (then card is retained)
- ATM holds denominations: $100, $50, $20, $10 bills
- Maximum 500 bills of each denomination
- Session timeout: 60 seconds of inactivity
- One user at a time (single-threaded from ATM perspective)

<br>

---

## Identify Primary Actors

1. **Customer** — uses ATM to perform banking transactions
   - Actions: insert card, enter PIN, withdraw, deposit, check balance, change PIN

2. **Bank System** — backend that validates and processes transactions
   - Actions: authenticate card, verify PIN, authorize transactions, update balances

3. **ATM Admin** — maintains and refills the ATM
   - Actions: refill cash, view reports, resolve jams, configure settings

4. **ATM Hardware** — physical components
   - Components: card reader, keypad, screen, cash dispenser, deposit slot, receipt printer

<br>

---

## Core Entities

### 1. ATM
- **Attributes**: atmId, location, state: ATMState, cashDispenser, currentCard, currentAccount
- **Responsibilities**: Manage state transitions, coordinate components

### 2. ATMState (Interface — State Pattern)
- **Methods**: insertCard(), enterPin(), withdraw(), deposit(), checkBalance(), ejectCard()
- **Implementations**: IdleState, CardInsertedState, AuthenticatedState, TransactionState

### 3. Account
- **Attributes**: accountId, balance, pin (hashed), dailyWithdrawn, accountType
- **Responsibilities**: Verify PIN, process withdrawals/deposits, enforce limits

### 4. Card
- **Attributes**: cardNumber, accountId, expiryDate, isBlocked
- **Responsibilities**: Link to account, track blocked status

### 5. CashDispenser (Chain of Responsibility)
- **Attributes**: denomination, count, nextHandler
- **Responsibilities**: Dispense bills of its denomination, delegate remainder to next handler

### 6. Transaction
- **Attributes**: transactionId, type, amount, timestamp, status
- **Responsibilities**: Record transaction details for receipt/history

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| ATM | has | ATMState | Composition (◆) |
| ATM | has | CashDispenser | Composition (◆) |
| ATM | uses | Account | Association |
| ATM | reads | Card | Association |
| Card | links to | Account | Association |
| CashDispenser | chains to | CashDispenser | Association (linked list) |
| Account | records | Transaction[] | Composition (◆) |
| IdleState | implements | ATMState | Implementation |
| CardInsertedState | implements | ATMState | Implementation |
| AuthenticatedState | implements | ATMState | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  ATM
  -state: ATMState ◆
  -cashDispenser ◆
  -currentCard
  -currentAccount
       │
       ▼
  <<interface>> ATMState
  +insertCard(), +enterPin(), +withdraw()
  +deposit(), +checkBalance(), +ejectCard()
       △
  ┌────┼──────────┬──────────────┐
Idle  CardInserted  Authenticated  Transaction


  CashDispenser (Chain of Responsibility)
  $100 Handler → $50 Handler → $20 Handler → $10 Handler
  -denomination, -count, -next
  +dispense(amount): Map<denomination, count>


  Card ──links──→ Account
                   -balance, -pin
                   -dailyWithdrawn
                   +withdraw(), +deposit()
                   +verifyPin()
```

<br>

---

## Design Patterns Used

### 1. **State Pattern**
- **Where**: ATM states (Idle → CardInserted → Authenticated → TransactionState)
- **Why**: ATM behavior changes completely based on current state — same button does different things
- **Benefit**: Clean state transitions, eliminates complex if-else on state variable

### 2. **Chain of Responsibility**
- **Where**: Cash dispenser chain ($100 → $50 → $20 → $10)
- **Why**: Each handler dispenses its denomination, passes remainder to next handler
- **Benefit**: New denominations can be added by inserting into the chain

### 3. **Strategy Pattern**
- **Where**: Transaction types (Withdrawal, Deposit, BalanceInquiry, Transfer)
- **Why**: Each transaction type has different processing logic
- **Benefit**: New transaction types added without modifying ATM core

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Single user at a time**: ATM is inherently single-threaded (one card reader, one session)
- **Account balance**: Bank backend uses `synchronized` or DB transactions for atomic balance updates
- **Cash dispenser**: `synchronized` on dispense operation — prevents dispensing more than available
- **Daily limit tracking**: `AtomicDouble` for thread-safe daily withdrawal counter

### Race Conditions Handled
- **Two ATMs accessing same account**: Bank backend handles with DB-level locks
- **Cash dispenser out of bills during dispense**: Check-then-dispense under same lock
- **Session timeout during transaction**: Timer thread cancels session, reverts any partial state

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **Insufficient funds** — reject withdrawal, show balance
2. **Daily limit exceeded** — show remaining daily allowance
3. **ATM out of cash** — display "Out of Service" for withdrawals, allow deposits/balance
4. **Cannot dispense exact amount** — $30 when only $50 bills available → reject, suggest nearest amount
5. **3 wrong PIN attempts** — retain card, display "Contact Bank" message
6. **Power failure during dispense** — transaction log for recovery, reconciliation
7. **Deposited amount disputed** — mark deposit as "pending verification"
8. **Card expired** — reject at card insertion, display expiry message
9. **Network failure** — queue transaction, process when connection restored

### Error Handling Strategy
- **InvalidPINException**: Increment attempt counter, lock after 3 failures
- **InsufficientFundsException**: Show current balance, suggest lower amount
- **CashDispenserException**: Mark ATM for maintenance, notify admin
- **NetworkException**: Show "Temporarily Unavailable", retry with exponential backoff

<br>

---

## Implementation

```code```
