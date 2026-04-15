# Design an ATM

Design an ATM (Automated Teller Machine) system that supports cash withdrawal, deposit, balance inquiry, and PIN management.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Card authentication** — insert card, verify PIN
2. **Balance inquiry** — check account balance
3. **Cash withdrawal** — dispense money, update balance
4. **Cash deposit** — accept cash, update balance
5. **PIN change** — change ATM PIN after authentication
6. **Cash dispenser** — dispense optimal denomination (100, 50, 20, 10)
7. **Transaction receipt** — print transaction details

### Extended Requirements

1. Mini statement (last 5 transactions)
2. Fund transfer between accounts
3. Daily withdrawal limit
4. Low cash alert for ATM admin

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **State** | ATM states (Idle, CardInserted, Authenticated, Dispensing) | Different behavior per state |
| **Chain of Responsibility** | Cash dispenser ($100→$50→$20→$10) | Denomination chain |
| **Strategy** | Transaction types (Withdraw, Deposit, BalanceInquiry) | Swappable operations |

<br>

---

## Core Entities

```
ATM
├─ state: ATMState
├─ cashDispenser: CashDispenser
├─ currentCard: Card
├─ currentAccount: Account

<<interface>> ATMState
├── IdleState
├── CardInsertedState
├── AuthenticatedState
├── TransactionState

CashDispenser (Chain of Responsibility)
├── HundredDollarHandler → FiftyDollarHandler → TwentyDollarHandler → TenDollarHandler

Account
├─ accountId, balance, pin
├─ withdraw(), deposit(), getBalance()
```

<br>

---

## Interview Tips

- State pattern is the star — ATM has very clear states
- Cash dispenser uses Chain of Responsibility for denominations
- Discuss thread safety if multiple users share ATM (they don't, but good to mention)
- Validate: insufficient funds, invalid PIN (max 3 attempts), daily limit
