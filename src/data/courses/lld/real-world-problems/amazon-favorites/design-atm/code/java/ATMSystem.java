// ===========================================================================
// DESIGN: ATM System — Low Level Design
// ===========================================================================
// Single-file Java | Patterns: State, Chain of Responsibility
// Principles: SOLID, Encapsulation, Polymorphism
// ===========================================================================

// ---------------------------------------------------------------------------
// 1. FUNCTIONAL REQUIREMENTS
// ---------------------------------------------------------------------------
// FR1: Insert card and authenticate with PIN (max 3 attempts)
// FR2: Check account balance
// FR3: Withdraw cash — deduct from balance, dispense optimal denominations
// FR4: Deposit cash — add to balance
// FR5: Eject card and return to idle state
// FR6: Enforce daily withdrawal limit ($5000)

// ---------------------------------------------------------------------------
// 2. CONSTRAINTS & ASSUMPTIONS
// ---------------------------------------------------------------------------
// - PIN: 4 digits, max 3 failed attempts -> card retained
// - Daily withdrawal limit: $5000
// - Denominations: $100, $50, $20, $10
// - One user at a time

// ---------------------------------------------------------------------------
// 3. CORE ENTITIES & RELATIONSHIPS
// ---------------------------------------------------------------------------
// +-------------------+------------------+--------------+-------------+----------------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                      |
// +-------------------+------------------+--------------+-------------+----------------------------------+
// | ATM                | ATMState         | Composition  | 1 -> 1      | ATM owns current state           |
// | ATM                | CashHandler      | Composition  | 1 -> 1      | ATM owns dispenser chain         |
// | ATM                | Account          | Association  | 1 -> 0..1   | ATM uses current account         |
// | CashHandler        | CashHandler      | Association  | 1 -> 0..1   | Chain link to next handler       |
// | IdleState          | ATMState         | Inheritance  | IS-A        | Concrete state                   |
// | CardInsertedState  | ATMState         | Inheritance  | IS-A        | Concrete state                   |
// | AuthenticatedState | ATMState         | Inheritance  | IS-A        | Concrete state                   |
// | Account            | Transaction      | Composition  | 1 -> many   | Account owns history             |
// +-------------------+------------------+--------------+-------------+----------------------------------+

// ---------------------------------------------------------------------------
// 4. PLANTUML
// ---------------------------------------------------------------------------
// @startuml ATM
// class ATM { -state:ATMState \n -dispenser:CashHandler \n -account:Account }
// interface ATMState { +insertCard() \n +enterPin() \n +withdraw() \n +deposit() \n +checkBalance() \n +ejectCard() }
// class IdleState
// class CardInsertedState { -attempts:int }
// class AuthenticatedState
// class Account { -balance:double \n -pin:String \n -dailyWithdrawn:double }
// class CashHandler { -denomination:int \n -count:int \n -next:CashHandler }
// class Transaction { -type \n -amount \n -description }
// ATM *-- ATMState
// ATM *-- CashHandler
// ATM --> Account
// ATMState <|.. IdleState
// ATMState <|.. CardInsertedState
// ATMState <|.. AuthenticatedState
// CashHandler --> CashHandler : next
// Account *-- "0..*" Transaction
// @enduml

import java.util.*;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================
enum TransactionType {
    WITHDRAWAL,
    DEPOSIT,
    BALANCE_INQUIRY
}

// ===========================================================================
// CLASS: Transaction [Value Object]
// Responsibility: Records a single transaction
// ===========================================================================
class Transaction {
    private TransactionType type;
    private double amount;
    private String description;

    public Transaction(TransactionType type, double amount, String desc) {
        this.type = type;
        this.amount = amount;
        this.description = desc;
    }

    public void display() {
        System.out.println("    [" + description + "] Amount: $" + amount);
    }
}

// ===========================================================================
// CLASS: Account [Core Entity]
// Responsibility: Balance, PIN, daily limits, transaction history
// ===========================================================================
class Account {
    private String accountId;
    private String pin;
    private double balance;
    private double dailyWithdrawn;
    private List<Transaction> history = new ArrayList<>();
    private static final double DAILY_LIMIT = 5000.0;

    public Account(String id, double balance, String pin) {
        this.accountId = id;
        this.balance = balance;
        this.pin = pin;
        this.dailyWithdrawn = 0;
    }

    public boolean verifyPin(String input) { return pin.equals(input); }
    public double getBalance() { return balance; }
    public String getAccountId() { return accountId; }

    // Withdraw with balance + daily limit check
    public boolean withdraw(double amount) {
        if (amount > balance) {
            System.out.println("  [ERROR] Insufficient funds. Balance: $" + balance);
            return false;
        }
        if (dailyWithdrawn + amount > DAILY_LIMIT) {
            System.out.println("  [ERROR] Daily limit exceeded. Remaining: $" + (DAILY_LIMIT - dailyWithdrawn));
            return false;
        }
        balance -= amount;
        dailyWithdrawn += amount;
        history.add(new Transaction(TransactionType.WITHDRAWAL, amount, "Withdrawal"));
        return true;
    }

    public void deposit(double amount) {
        balance += amount;
        history.add(new Transaction(TransactionType.DEPOSIT, amount, "Deposit"));
    }

    public void recordInquiry() {
        history.add(new Transaction(TransactionType.BALANCE_INQUIRY, 0, "Balance Inquiry"));
    }

    public void showHistory() {
        System.out.println("  Transaction History for " + accountId + ":");
        for (Transaction t : history) t.display();
    }
}

// ===========================================================================
// CLASS: CashHandler [Chain of Responsibility]
// Responsibility: Dispense bills of one denomination, delegate remainder
// ===========================================================================
class CashHandler {
    private int denomination;
    private int count;
    private CashHandler next;

    public CashHandler(int denomination, int count) {
        this.denomination = denomination;
        this.count = count;
    }

    public void setNext(CashHandler handler) { this.next = handler; }

    // Dispense bills, delegate remaining amount to next handler
    public boolean dispense(int amount, Map<Integer, Integer> result) {
        int billsNeeded = amount / denomination;
        int billsToUse = Math.min(billsNeeded, count);

        if (billsToUse > 0) {
            result.put(denomination, billsToUse);
            count -= billsToUse;
            amount -= billsToUse * denomination;
        }

        if (amount > 0) {
            if (next != null) {
                return next.dispense(amount, result);
            } else {
                System.out.println("  [ERROR] Cannot dispense exact amount");
                if (billsToUse > 0) {
                    count += billsToUse;  // Rollback
                    result.remove(denomination);
                }
                return false;
            }
        }
        return true;
    }

    public void displayInventory() {
        System.out.println("  $" + denomination + " bills: " + count);
        if (next != null) next.displayInventory();
    }
}

// ===========================================================================
// INTERFACE: ATMState [State Pattern]
// Responsibility: Contract for state-specific behavior
// ===========================================================================
interface ATMState {
    void insertCard(ATMachine atm);
    void enterPin(ATMachine atm, String pin);
    void withdraw(ATMachine atm, double amount);
    void deposit(ATMachine atm, double amount);
    void checkBalance(ATMachine atm);
    void ejectCard(ATMachine atm);
    String getStateName();
}

// ===========================================================================
// CLASS: IdleState [State: Concrete — waiting for card]
// ===========================================================================
class IdleState implements ATMState {
    public void insertCard(ATMachine atm) {
        System.out.println("  Card inserted. Please enter PIN.");
        atm.setState(new CardInsertedState());
    }
    public void enterPin(ATMachine atm, String pin) { System.out.println("  [ERROR] Insert card first."); }
    public void withdraw(ATMachine atm, double amount) { System.out.println("  [ERROR] Insert card first."); }
    public void deposit(ATMachine atm, double amount) { System.out.println("  [ERROR] Insert card first."); }
    public void checkBalance(ATMachine atm) { System.out.println("  [ERROR] Insert card first."); }
    public void ejectCard(ATMachine atm) { System.out.println("  No card inserted."); }
    public String getStateName() { return "IDLE"; }
}

// ===========================================================================
// CLASS: CardInsertedState [State: Concrete — PIN verification]
// ===========================================================================
class CardInsertedState implements ATMState {
    private int attempts = 0;

    public void insertCard(ATMachine atm) { System.out.println("  [ERROR] Card already inserted."); }

    public void enterPin(ATMachine atm, String pin) {
        Account account = atm.getAccount();
        if (account == null) { System.out.println("  [ERROR] No account."); return; }

        if (account.verifyPin(pin)) {
            System.out.println("  PIN verified. Welcome!");
            atm.setState(new AuthenticatedState());
        } else {
            attempts++;
            if (attempts >= 3) {
                System.out.println("  [ERROR] 3 failed attempts. Card retained!");
                atm.setAccount(null);
                atm.setState(new IdleState());
            } else {
                System.out.println("  [ERROR] Wrong PIN. " + (3 - attempts) + " attempt(s) left.");
            }
        }
    }

    public void withdraw(ATMachine atm, double amount) { System.out.println("  [ERROR] Enter PIN first."); }
    public void deposit(ATMachine atm, double amount) { System.out.println("  [ERROR] Enter PIN first."); }
    public void checkBalance(ATMachine atm) { System.out.println("  [ERROR] Enter PIN first."); }
    public void ejectCard(ATMachine atm) {
        System.out.println("  Card ejected.");
        atm.setAccount(null);
        atm.setState(new IdleState());
    }
    public String getStateName() { return "CARD_INSERTED"; }
}

// ===========================================================================
// CLASS: AuthenticatedState [State: Concrete — full access]
// ===========================================================================
class AuthenticatedState implements ATMState {
    public void insertCard(ATMachine atm) { System.out.println("  [ERROR] Already authenticated."); }
    public void enterPin(ATMachine atm, String pin) { System.out.println("  [ERROR] Already authenticated."); }

    public void withdraw(ATMachine atm, double amount) {
        Account account = atm.getAccount();
        if (account == null) return;

        int intAmount = (int) amount;
        if (intAmount % 10 != 0) {
            System.out.println("  [ERROR] Amount must be multiple of $10.");
            return;
        }

        if (!account.withdraw(amount)) return;

        // Dispense via Chain of Responsibility
        Map<Integer, Integer> dispensed = new LinkedHashMap<>();
        if (atm.getDispenser().dispense(intAmount, dispensed)) {
            System.out.println("  Cash dispensed:");
            for (Map.Entry<Integer, Integer> e : dispensed.entrySet())
                System.out.println("    $" + e.getKey() + " x " + e.getValue());
            System.out.println("  New balance: $" + account.getBalance());
        } else {
            account.deposit(amount); // Rollback
            System.out.println("  [ERROR] ATM cannot dispense this amount.");
        }
    }

    public void deposit(ATMachine atm, double amount) {
        Account account = atm.getAccount();
        if (account == null) return;
        account.deposit(amount);
        System.out.println("  Deposited $" + amount + ". New balance: $" + account.getBalance());
    }

    public void checkBalance(ATMachine atm) {
        Account account = atm.getAccount();
        if (account == null) return;
        account.recordInquiry();
        System.out.println("  Balance: $" + account.getBalance());
    }

    public void ejectCard(ATMachine atm) {
        System.out.println("  Card ejected. Thank you!");
        atm.setAccount(null);
        atm.setState(new IdleState());
    }

    public String getStateName() { return "AUTHENTICATED"; }
}

// ===========================================================================
// CLASS: ATMachine [Main Context — State Pattern]
// Responsibility: Coordinates operations, manages state + dispenser
// ===========================================================================
class ATMachine {
    private ATMState state;
    private Account currentAccount;
    private CashHandler dispenser;

    public ATMachine() {
        this.state = new IdleState();

        // Build chain: $100 -> $50 -> $20 -> $10
        CashHandler h100 = new CashHandler(100, 50);
        CashHandler h50  = new CashHandler(50, 50);
        CashHandler h20  = new CashHandler(20, 100);
        CashHandler h10  = new CashHandler(10, 100);
        h100.setNext(h50);
        h50.setNext(h20);
        h20.setNext(h10);
        this.dispenser = h100;
    }

    public void setState(ATMState s) { this.state = s; }
    public void setAccount(Account a) { this.currentAccount = a; }
    public Account getAccount() { return currentAccount; }
    public CashHandler getDispenser() { return dispenser; }

    public void insertCard() { System.out.println("\n>> Insert Card (" + state.getStateName() + ")"); state.insertCard(this); }
    public void enterPin(String pin) { System.out.println("\n>> Enter PIN (" + state.getStateName() + ")"); state.enterPin(this, pin); }
    public void withdraw(double amt) { System.out.println("\n>> Withdraw $" + amt + " (" + state.getStateName() + ")"); state.withdraw(this, amt); }
    public void deposit(double amt) { System.out.println("\n>> Deposit $" + amt + " (" + state.getStateName() + ")"); state.deposit(this, amt); }
    public void checkBalance() { System.out.println("\n>> Check Balance (" + state.getStateName() + ")"); state.checkBalance(this); }
    public void ejectCard() { System.out.println("\n>> Eject Card (" + state.getStateName() + ")"); state.ejectCard(this); }
}

// ===========================================================================
// MAIN
// ===========================================================================
public class ATMSystem {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  ATM System — LLD Demo (Java)");
        System.out.println("============================================");

        Account acc1 = new Account("ACC001", 5000.00, "1234");
        Account acc2 = new Account("ACC002", 250.00, "5678");
        ATMachine atm = new ATMachine();

        // Scenario 1: Successful withdrawal
        System.out.println("\n====== Scenario 1: Withdrawal ======");
        atm.setAccount(acc1);
        atm.insertCard();
        atm.enterPin("1234");
        atm.checkBalance();
        atm.withdraw(270);
        atm.checkBalance();
        atm.ejectCard();

        // Scenario 2: Wrong PIN
        System.out.println("\n====== Scenario 2: Wrong PIN ======");
        atm.setAccount(acc2);
        atm.insertCard();
        atm.enterPin("0000");
        atm.enterPin("1111");
        atm.enterPin("2222"); // Card retained

        // Scenario 3: Deposit
        System.out.println("\n====== Scenario 3: Deposit ======");
        atm.setAccount(acc2);
        atm.insertCard();
        atm.enterPin("5678");
        atm.deposit(500);
        atm.checkBalance();
        atm.ejectCard();

        // History
        System.out.println("\n====== History ======");
        acc1.showHistory();
        acc2.showHistory();

        System.out.println("\n=== All scenarios complete ===");
    }
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> ATMachine (IdleState + CashHandler chain)
//     -> insertCard() -> IdleState.insertCard() -> setState(CardInsertedState)
//     -> enterPin("1234") -> CardInsertedState.enterPin() -> verifyPin() -> setState(AuthenticatedState)
//     -> withdraw(270) -> AuthenticatedState.withdraw()
//        -> account.withdraw(270) [balance+limit check]
//        -> dispenser.dispense(270) [CoR: $100x2 + $50x1 + $20x1]
//     -> ejectCard() -> setState(IdleState)

// METHOD CALL TREE:
//   atm.withdraw(270)
//     -> state.withdraw(atm, 270)          [State dispatch]
//        -> account.withdraw(270)           [Balance check]
//        -> dispenser.dispense(270, map)    [Chain of Responsibility]
//           -> h100.dispense(270) -> 2x$100, rem=70
//              -> h50.dispense(70) -> 1x$50, rem=20
//                 -> h20.dispense(20) -> 1x$20, rem=0 ✓

// CLASS RESPONSIBILITY TABLE:
//   Transaction          | Record type, amount, description
//   Account              | Balance, PIN, daily limit, history
//   CashHandler          | Dispense denomination, delegate to next
//   ATMState (interface) | Behavior contract per state
//   IdleState            | Only card insertion allowed
//   CardInsertedState    | PIN verification, 3-attempt limit
//   AuthenticatedState   | Full operations: withdraw/deposit/balance
//   ATMachine            | Context: coordinates state + dispenser

// DESIGN PATTERNS:
//   1. State     -> ATM states (Idle/CardInserted/Authenticated)
//   2. Chain of Responsibility -> Dispenser: $100→$50→$20→$10

// BEST PRACTICES:
//   1. Encapsulation  -> PIN/balance private
//   2. Polymorphism   -> ATMState dispatched at runtime
//   3. SRP            -> Each state handles its own behavior
//   4. Rollback       -> Dispenser failure re-deposits amount
//   5. Fail-safe      -> Card retained after 3 wrong PINs
