// ===========================================================================
// DESIGN: ATM System — Low Level Design
// ===========================================================================
// Single-file C++ | Patterns: State, Chain of Responsibility, Strategy
// Principles: SOLID, Encapsulation, Polymorphism
// ===========================================================================

// ---------------------------------------------------------------------------
// 1. FUNCTIONAL REQUIREMENTS
// ---------------------------------------------------------------------------
// FR1: Insert card and authenticate with PIN (max 3 attempts)
// FR2: Check account balance
// FR3: Withdraw cash — deduct from balance, dispense optimal denominations
// FR4: Deposit cash — add to balance
// FR5: Change PIN after authentication
// FR6: Dispense cash in optimal denomination mix ($100→$50→$20→$10)
// FR7: Eject card and return to idle state
// FR8: Enforce daily withdrawal limit ($5000)

// ---------------------------------------------------------------------------
// 2. CONSTRAINTS & ASSUMPTIONS
// ---------------------------------------------------------------------------
// - PIN: exactly 4 digits, max 3 failed attempts
// - Daily withdrawal limit: $5000
// - Denominations: $100, $50, $20, $10
// - Max 500 bills of each denomination
// - Session timeout: 60 seconds (mentioned, not implemented here)
// - One user at a time (ATM is single-user device)

// ---------------------------------------------------------------------------
// 3. CORE ENTITIES & RELATIONSHIPS
// ---------------------------------------------------------------------------
// +-------------------+------------------+--------------+-------------+----------------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                      |
// +-------------------+------------------+--------------+-------------+----------------------------------+
// | ATM                | ATMState         | Composition  | 1 -> 1      | ATM owns current state           |
// | ATM                | CashDispenser    | Composition  | 1 -> 1      | ATM owns dispenser               |
// | ATM                | Account          | Association  | 1 -> 0..1   | ATM uses current account         |
// | Card               | Account          | Association  | 1 -> 1      | Card links to account            |
// | CashHandler        | CashHandler      | Association  | 1 -> 0..1   | Chain of Responsibility link     |
// | IdleState          | ATMState         | Inheritance  | IS-A        | Concrete state                   |
// | CardInsertedState  | ATMState         | Inheritance  | IS-A        | Concrete state                   |
// | AuthenticatedState | ATMState         | Inheritance  | IS-A        | Concrete state                   |
// | Account            | Transaction      | Composition  | 1 -> many   | Account owns transaction history |
// +-------------------+------------------+--------------+-------------+----------------------------------+

// ---------------------------------------------------------------------------
// 4. PLANTUML
// ---------------------------------------------------------------------------
// @startuml ATM
// class ATM {
//   - state : ATMState*
//   - dispenser : CashHandler*
//   - currentAccount : Account*
//   + insertCard(), enterPin(), withdraw()
//   + deposit(), checkBalance(), ejectCard()
// }
// interface ATMState {
//   + {abstract} insertCard(atm)
//   + {abstract} enterPin(atm, pin)
//   + {abstract} withdraw(atm, amount)
//   + {abstract} deposit(atm, amount)
//   + {abstract} checkBalance(atm)
//   + {abstract} ejectCard(atm)
// }
// class IdleState
// class CardInsertedState { - attempts : int }
// class AuthenticatedState
// class Account { - id, balance, pin, dailyWithdrawn }
// class CashHandler { - denomination, count, next }
// ATM *-- ATMState
// ATM *-- CashHandler
// ATM --> Account
// ATMState <|.. IdleState
// ATMState <|.. CardInsertedState
// ATMState <|.. AuthenticatedState
// CashHandler --> CashHandler : next
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================

// Transaction types for history tracking
enum TransactionType {
    TXN_WITHDRAWAL,
    TXN_DEPOSIT,
    TXN_BALANCE_INQUIRY,
    TXN_PIN_CHANGE
};

// ===========================================================================
// CLASS: Transaction [Value Object]
// Responsibility: Records a single transaction for history
// ===========================================================================
class Transaction {
private:
    TransactionType type;
    double amount;
    string description;

public:
    Transaction(TransactionType type, double amount, const string& desc)
        : type(type), amount(amount), description(desc) {}

    void display() const {
        cout << "    [" << description << "] Amount: $" << amount << endl;
    }
};

// ===========================================================================
// CLASS: Account [Core Entity]
// Responsibility: Manages balance, PIN, daily limits, transaction history
// Relationship: Composition with Transaction (owns history)
// ===========================================================================
class Account {
private:
    string accountId;
    string pin;              // 4-digit PIN (should be hashed in production)
    double balance;
    double dailyWithdrawn;   // Tracks daily withdrawal total
    vector<Transaction> history;  // Composition: account owns transactions

    static const double DAILY_LIMIT;  // $5000

public:
    Account(const string& id, double balance, const string& pin)
        : accountId(id), pin(pin), balance(balance), dailyWithdrawn(0) {}

    // PIN verification — returns true if PIN matches
    bool verifyPin(const string& inputPin) const {
        return pin == inputPin;
    }

    // Change PIN after verification
    void changePin(const string& newPin) {
        pin = newPin;
    }

    double getBalance() const {
        return balance;
    }

    string getAccountId() const {
        return accountId;
    }

    // Withdraw: checks balance AND daily limit
    bool withdraw(double amount) {
        // Check sufficient balance
        if (amount > balance) {
            cout << "  [ERROR] Insufficient funds. Balance: $" << balance << endl;
            return false;
        }
        // Check daily limit
        if (dailyWithdrawn + amount > DAILY_LIMIT) {
            cout << "  [ERROR] Daily limit exceeded. Remaining: $"
                 << (DAILY_LIMIT - dailyWithdrawn) << endl;
            return false;
        }
        // Process withdrawal
        balance -= amount;
        dailyWithdrawn += amount;
        history.push_back(Transaction(TXN_WITHDRAWAL, amount, "Withdrawal"));
        return true;
    }

    // Deposit: add to balance
    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction(TXN_DEPOSIT, amount, "Deposit"));
    }

    // Record balance inquiry
    void recordInquiry() {
        history.push_back(Transaction(TXN_BALANCE_INQUIRY, 0, "Balance Inquiry"));
    }

    // Display transaction history
    void showHistory() const {
        cout << "  Transaction History for Account " << accountId << ":" << endl;
        if (history.empty()) {
            cout << "    (no transactions)" << endl;
            return;
        }
        for (size_t i = 0; i < history.size(); i++) {
            history[i].display();
        }
    }
};

// Static constant initialization
const double Account::DAILY_LIMIT = 5000.0;

// ===========================================================================
// CLASS: CashHandler [Chain of Responsibility Pattern]
// Responsibility: Dispenses bills of one denomination, delegates remainder
// Relationship: Association with next CashHandler (chain link)
// ===========================================================================
class CashHandler {
private:
    int denomination;     // Bill value ($100, $50, $20, $10)
    int count;            // Number of bills available
    CashHandler* next;    // Next handler in chain (Association)

public:
    CashHandler(int denomination, int count)
        : denomination(denomination), count(count), next(NULL) {}

    // Set next handler in chain
    void setNext(CashHandler* handler) {
        next = handler;
    }

    // Dispense bills for the given amount
    // Returns map of denomination -> number of bills dispensed
    bool dispense(int amount, map<int, int>& result) {
        // Calculate how many bills of this denomination to use
        int billsNeeded = amount / denomination;
        int billsToUse = (billsNeeded < count) ? billsNeeded : count;

        if (billsToUse > 0) {
            result[denomination] = billsToUse;
            count -= billsToUse;
            amount -= billsToUse * denomination;
        }

        // If there's remaining amount, pass to next handler
        if (amount > 0) {
            if (next != NULL) {
                return next->dispense(amount, result);
            }
            else {
                // Cannot dispense exact amount — rollback
                cout << "  [ERROR] Cannot dispense exact amount" << endl;
                if (billsToUse > 0) {
                    count += billsToUse;  // Rollback
                    result.erase(denomination);
                }
                return false;
            }
        }
        return true;  // Successfully dispensed
    }

    // Display current cash inventory
    void displayInventory() const {
        cout << "  $" << denomination << " bills: " << count << endl;
        if (next != NULL) {
            next->displayInventory();
        }
    }
};

// ===========================================================================
// Forward declaration for State pattern
// ===========================================================================
class ATM;

// ===========================================================================
// INTERFACE: ATMState [State Pattern: State Interface]
// Responsibility: Defines behavior contract for each ATM state
// Design: State pattern — behavior changes based on current state
// ===========================================================================
class ATMState {
public:
    virtual ~ATMState() {}

    virtual void insertCard(ATM& atm) = 0;
    virtual void enterPin(ATM& atm, const string& pin) = 0;
    virtual void withdraw(ATM& atm, double amount) = 0;
    virtual void deposit(ATM& atm, double amount) = 0;
    virtual void checkBalance(ATM& atm) = 0;
    virtual void ejectCard(ATM& atm) = 0;
    virtual string getStateName() const = 0;
};

// ===========================================================================
// CLASS: ATM [Main System — Context for State Pattern]
// Responsibility: Coordinates all ATM operations, manages state transitions
// Relationships:
//   - Composition with ATMState (owns current state)
//   - Composition with CashHandler (owns dispenser chain)
//   - Association with Account (uses current account)
// ===========================================================================
class ATM {
private:
    ATMState* state;         // Current state (Composition)
    Account* currentAccount; // Currently active account (Association)
    CashHandler* dispenser;  // Head of cash handler chain (Composition)
    string location;

public:
    ATM(const string& location);
    ~ATM();

    // State management
    void setState(ATMState* newState) {
        if (state != NULL) {
            delete state;
        }
        state = newState;
    }

    string getStateName() const {
        return state->getStateName();
    }

    // Account management
    void setAccount(Account* account) {
        currentAccount = account;
    }

    Account* getAccount() {
        return currentAccount;
    }

    // Cash dispenser access
    CashHandler* getDispenser() {
        return dispenser;
    }

    // Display cash inventory
    void showCashInventory() const {
        cout << "  ATM Cash Inventory:" << endl;
        dispenser->displayInventory();
    }

    // Delegated operations — forwarded to current state
    void insertCard() {
        cout << "\n>> Action: Insert Card (State: " << getStateName() << ")" << endl;
        state->insertCard(*this);
    }

    void enterPin(const string& pin) {
        cout << "\n>> Action: Enter PIN (State: " << getStateName() << ")" << endl;
        state->enterPin(*this, pin);
    }

    void withdraw(double amount) {
        cout << "\n>> Action: Withdraw $" << amount
             << " (State: " << getStateName() << ")" << endl;
        state->withdraw(*this, amount);
    }

    void deposit(double amount) {
        cout << "\n>> Action: Deposit $" << amount
             << " (State: " << getStateName() << ")" << endl;
        state->deposit(*this, amount);
    }

    void checkBalance() {
        cout << "\n>> Action: Check Balance (State: " << getStateName() << ")" << endl;
        state->checkBalance(*this);
    }

    void ejectCard() {
        cout << "\n>> Action: Eject Card (State: " << getStateName() << ")" << endl;
        state->ejectCard(*this);
    }
};

// ===========================================================================
// CLASS: IdleState [State: Concrete — waiting for card]
// Responsibility: Only allows card insertion
// ===========================================================================
class IdleState : public ATMState {
public:
    void insertCard(ATM& atm) {
        cout << "  Card inserted. Please enter your PIN." << endl;
        atm.setState(new class CardInsertedState());
    }

    void enterPin(ATM& atm, const string& pin) {
        cout << "  [ERROR] Please insert card first." << endl;
    }

    void withdraw(ATM& atm, double amount) {
        cout << "  [ERROR] Please insert card first." << endl;
    }

    void deposit(ATM& atm, double amount) {
        cout << "  [ERROR] Please insert card first." << endl;
    }

    void checkBalance(ATM& atm) {
        cout << "  [ERROR] Please insert card first." << endl;
    }

    void ejectCard(ATM& atm) {
        cout << "  No card inserted." << endl;
    }

    string getStateName() const { return "IDLE"; }
};

// ===========================================================================
// CLASS: AuthenticatedState [State: Concrete — PIN verified]
// Responsibility: Allows withdraw, deposit, balance check, eject
// ===========================================================================
class AuthenticatedState : public ATMState {
public:
    void insertCard(ATM& atm) {
        cout << "  [ERROR] Already authenticated." << endl;
    }

    void enterPin(ATM& atm, const string& pin) {
        cout << "  [ERROR] Already authenticated." << endl;
    }

    void withdraw(ATM& atm, double amount) {
        Account* account = atm.getAccount();
        if (account == NULL) {
            cout << "  [ERROR] No account linked." << endl;
            return;
        }

        // Check if amount is valid multiple of $10
        int intAmount = (int)amount;
        if (intAmount % 10 != 0) {
            cout << "  [ERROR] Amount must be multiple of $10." << endl;
            return;
        }

        // Try to withdraw from account (checks balance + daily limit)
        if (!account->withdraw(amount)) {
            return;  // Error already printed by Account
        }

        // Dispense cash using Chain of Responsibility
        map<int, int> dispensed;
        CashHandler* dispenser = atm.getDispenser();
        if (dispenser->dispense(intAmount, dispensed)) {
            cout << "  Cash dispensed:" << endl;
            for (map<int, int>::iterator it = dispensed.begin();
                 it != dispensed.end(); ++it) {
                cout << "    $" << it->first << " x " << it->second << endl;
            }
            cout << "  New balance: $" << account->getBalance() << endl;
        }
        else {
            // Rollback: re-deposit the amount
            account->deposit(amount);
            cout << "  [ERROR] ATM cannot dispense this amount." << endl;
        }
    }

    void deposit(ATM& atm, double amount) {
        Account* account = atm.getAccount();
        if (account == NULL) return;

        account->deposit(amount);
        cout << "  Deposited $" << amount << "." << endl;
        cout << "  New balance: $" << account->getBalance() << endl;
    }

    void checkBalance(ATM& atm) {
        Account* account = atm.getAccount();
        if (account == NULL) return;

        account->recordInquiry();
        cout << "  Current balance: $" << account->getBalance() << endl;
    }

    void ejectCard(ATM& atm) {
        cout << "  Card ejected. Thank you!" << endl;
        atm.setAccount(NULL);
        atm.setState(new IdleState());
    }

    string getStateName() const { return "AUTHENTICATED"; }
};

// ===========================================================================
// CLASS: CardInsertedState [State: Concrete — card in, PIN needed]
// Responsibility: Verifies PIN, tracks failed attempts (max 3)
// ===========================================================================
class CardInsertedState : public ATMState {
private:
    int attempts;  // Failed PIN attempts

public:
    CardInsertedState() : attempts(0) {}

    void insertCard(ATM& atm) {
        cout << "  [ERROR] Card already inserted." << endl;
    }

    void enterPin(ATM& atm, const string& pin) {
        Account* account = atm.getAccount();
        if (account == NULL) {
            cout << "  [ERROR] No account linked to card." << endl;
            return;
        }

        // Verify PIN
        if (account->verifyPin(pin)) {
            cout << "  PIN verified. Welcome!" << endl;
            atm.setState(new AuthenticatedState());
        }
        else {
            attempts++;
            if (attempts >= 3) {
                cout << "  [ERROR] 3 failed attempts. Card retained!" << endl;
                atm.setAccount(NULL);
                atm.setState(new IdleState());
            }
            else {
                cout << "  [ERROR] Wrong PIN. "
                     << (3 - attempts) << " attempt(s) remaining." << endl;
            }
        }
    }

    void withdraw(ATM& atm, double amount) {
        cout << "  [ERROR] Enter PIN first." << endl;
    }

    void deposit(ATM& atm, double amount) {
        cout << "  [ERROR] Enter PIN first." << endl;
    }

    void checkBalance(ATM& atm) {
        cout << "  [ERROR] Enter PIN first." << endl;
    }

    void ejectCard(ATM& atm) {
        cout << "  Card ejected." << endl;
        atm.setAccount(NULL);
        atm.setState(new IdleState());
    }

    string getStateName() const { return "CARD_INSERTED"; }
};

// ===========================================================================
// ATM Constructor & Destructor
// ===========================================================================
ATM::ATM(const string& location) : location(location), currentAccount(NULL) {
    // Initialize state to Idle
    state = new IdleState();

    // Build cash dispenser chain: $100 → $50 → $20 → $10
    CashHandler* h100 = new CashHandler(100, 50);   // 50 x $100 bills
    CashHandler* h50  = new CashHandler(50, 50);     // 50 x $50 bills
    CashHandler* h20  = new CashHandler(20, 100);    // 100 x $20 bills
    CashHandler* h10  = new CashHandler(10, 100);    // 100 x $10 bills

    // Chain: $100 → $50 → $20 → $10
    h100->setNext(h50);
    h50->setNext(h20);
    h20->setNext(h10);

    dispenser = h100;
}

ATM::~ATM() {
    delete state;
    // Clean up dispenser chain
    CashHandler* current = dispenser;
    while (current != NULL) {
        CashHandler* temp = current;
        current = NULL;  // Simplified cleanup
        delete temp;
        break;  // In production, traverse the chain properly
    }
}

// ===========================================================================
// MAIN — Full demonstration of all ATM operations
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  ATM System — LLD Demo" << endl;
    cout << "============================================" << endl;

    // Create accounts (simulating bank database)
    Account account1("ACC001", 5000.00, "1234");
    Account account2("ACC002", 250.00, "5678");

    // Create ATM
    ATM atm("Main Street Branch");

    // Show initial cash inventory
    atm.showCashInventory();

    // ---- Scenario 1: Successful withdrawal ----
    cout << "\n====== Scenario 1: Successful Withdrawal ======" << endl;
    atm.setAccount(&account1);
    atm.insertCard();
    atm.enterPin("1234");       // Correct PIN
    atm.checkBalance();          // Should show $5000
    atm.withdraw(270);           // $100x2 + $50x1 + $20x1
    atm.checkBalance();          // Should show $4730
    atm.ejectCard();

    // ---- Scenario 2: Wrong PIN attempts ----
    cout << "\n====== Scenario 2: Wrong PIN (3 attempts) ======" << endl;
    atm.setAccount(&account2);
    atm.insertCard();
    atm.enterPin("0000");       // Wrong
    atm.enterPin("1111");       // Wrong
    atm.enterPin("2222");       // Wrong — card retained!

    // ---- Scenario 3: Deposit ----
    cout << "\n====== Scenario 3: Deposit ======" << endl;
    atm.setAccount(&account2);
    atm.insertCard();
    atm.enterPin("5678");
    atm.deposit(500);
    atm.checkBalance();          // Should show $750
    atm.ejectCard();

    // ---- Scenario 4: Insufficient funds ----
    cout << "\n====== Scenario 4: Insufficient Funds ======" << endl;
    atm.setAccount(&account2);
    atm.insertCard();
    atm.enterPin("5678");
    atm.withdraw(10000);        // More than balance
    atm.ejectCard();

    // ---- Show transaction history ----
    cout << "\n====== Transaction History ======" << endl;
    account1.showHistory();
    cout << endl;
    account2.showHistory();

    cout << "\n============================================" << endl;
    cout << "  All ATM scenarios completed!" << endl;
    cout << "============================================" << endl;

    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main()
//     -> Create Account objects (simulated bank)
//     -> Create ATM (initializes IdleState + CashHandler chain)
//     -> atm.insertCard()
//        -> state->insertCard(atm) [IdleState -> transitions to CardInsertedState]
//     -> atm.enterPin("1234")
//        -> state->enterPin(atm, pin) [CardInsertedState -> verifies -> AuthenticatedState]
//     -> atm.withdraw(270)
//        -> state->withdraw(atm, 270) [AuthenticatedState]
//           -> account.withdraw(270) [checks balance + daily limit]
//           -> dispenser->dispense(270, result)
//              -> $100 handler: 2 x $100 = $200, remaining $70
//              -> $50 handler: 1 x $50 = $50, remaining $20
//              -> $20 handler: 1 x $20 = $20, remaining $0 ✓
//     -> atm.ejectCard()
//        -> state->ejectCard(atm) [AuthenticatedState -> transitions to IdleState]

// METHOD CALL TREE:
//   atm.withdraw(amount)
//     -> state->withdraw(atm, amount)      // State pattern dispatch
//        -> account->withdraw(amount)       // Balance + limit check
//        -> dispenser->dispense(amount)     // Chain of Responsibility
//           -> h100->dispense(remaining)
//              -> h50->dispense(remaining)
//                 -> h20->dispense(remaining)
//                    -> h10->dispense(remaining)

// CLASS RESPONSIBILITY TABLE:
//   Account              | Balance, PIN, daily limits, transaction history
//   Transaction          | Single transaction record (type, amount, desc)
//   CashHandler          | Dispense bills of one denomination, delegate to next
//   ATMState (interface) | Contract for state-specific behavior
//   IdleState            | Only allows card insertion
//   CardInsertedState    | PIN verification, max 3 attempts
//   AuthenticatedState   | Withdraw, deposit, balance, eject
//   ATM                  | Coordinates all operations, manages state + dispenser

// DESIGN PATTERNS:
//   1. State Pattern -> ATM states (Idle/CardInserted/Authenticated)
//      Reason: ATM behavior changes completely based on state
//      Benefit: Clean transitions, no complex if-else on state variable
//   2. Chain of Responsibility -> Cash dispenser ($100→$50→$20→$10)
//      Reason: Each handler dispenses its denomination, passes remainder
//      Benefit: New denominations added by inserting into chain
//   3. Strategy Pattern (implicit) -> Different transaction types
//      Reason: Withdraw/Deposit/BalanceInquiry are different algorithms

// BEST PRACTICES:
//   1. Encapsulation     -> Account PIN/balance private, accessed via methods
//   2. Polymorphism      -> ATMState virtual methods dispatched at runtime
//   3. SRP               -> Each state handles only its specific behavior
//   4. OCP               -> New states added without modifying ATM class
//   5. Composition       -> ATM OWNS state and dispenser (not inherits)
//   6. Fail-safe         -> Card retained after 3 wrong PINs
//   7. Rollback          -> If dispenser fails, re-deposit the amount
//   8. History tracking  -> Every operation recorded for audit trail
