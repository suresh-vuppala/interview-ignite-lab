#include <string>
#include <map>
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

// ========== ACCOUNT ==========
class Account {
    string accountId, pin;
    double balance, dailyWithdrawn = 0;
    static constexpr double DAILY_LIMIT = 5000;
public:
    Account(string id, double bal, string pin) : accountId(move(id)), balance(bal), pin(move(pin)) {}
    bool verifyPin(const string& input) const { return pin == input; }
    double getBalance() const { return balance; }
    bool withdraw(double amount) {
        if (amount > balance || dailyWithdrawn + amount > DAILY_LIMIT) return false;
        balance -= amount; dailyWithdrawn += amount; return true;
    }
    void deposit(double amount) { balance += amount; }
};

// ========== CASH DISPENSER (Chain of Responsibility) ==========
class CashHandler {
    int denomination, count;
    shared_ptr<CashHandler> next;
public:
    CashHandler(int denom, int cnt) : denomination(denom), count(cnt) {}
    void setNext(shared_ptr<CashHandler> n) { next = move(n); }
    map<int, int> dispense(int amount) {
        map<int, int> result;
        int bills = min(amount / denomination, count);
        if (bills > 0) { result[denomination] = bills; count -= bills; amount -= bills * denomination; }
        if (amount > 0 && next) {
            auto rest = next->dispense(amount);
            result.insert(rest.begin(), rest.end());
        } else if (amount > 0) {
            throw runtime_error("Cannot dispense exact amount");
        }
        return result;
    }
};

// ========== ATM STATE ==========
class ATM; // Forward declaration

class ATMState {
public:
    virtual ~ATMState() = default;
    virtual void insertCard(ATM& atm) = 0;
    virtual void enterPin(ATM& atm, const string& pin) = 0;
    virtual void withdraw(ATM& atm, double amount) = 0;
    virtual void deposit(ATM& atm, double amount) = 0;
    virtual void checkBalance(ATM& atm) = 0;
    virtual void ejectCard(ATM& atm) = 0;
};

class ATM {
    shared_ptr<ATMState> state;
    shared_ptr<Account> account;
    shared_ptr<CashHandler> dispenser;
public:
    ATM();
    void setState(shared_ptr<ATMState> s) { state = move(s); }
    void setAccount(shared_ptr<Account> a) { account = move(a); }
    shared_ptr<Account>& getAccount() { return account; }
    shared_ptr<CashHandler>& getDispenser() { return dispenser; }
    void insertCard() { state->insertCard(*this); }
    void enterPin(const string& pin) { state->enterPin(*this, pin); }
    void withdraw(double amt) { state->withdraw(*this, amt); }
    void deposit(double amt) { state->deposit(*this, amt); }
    void checkBalance() { state->checkBalance(*this); }
    void ejectCard() { state->ejectCard(*this); }
};

class IdleState : public ATMState {
public:
    void insertCard(ATM& atm) override;
    void enterPin(ATM&, const string&) override { cout << "Insert card first" << endl; }
    void withdraw(ATM&, double) override { cout << "Insert card first" << endl; }
    void deposit(ATM&, double) override { cout << "Insert card first" << endl; }
    void checkBalance(ATM&) override { cout << "Insert card first" << endl; }
    void ejectCard(ATM&) override { cout << "No card inserted" << endl; }
};

class AuthenticatedState : public ATMState {
public:
    void insertCard(ATM&) override { cout << "Already authenticated" << endl; }
    void enterPin(ATM&, const string&) override { cout << "Already authenticated" << endl; }
    void withdraw(ATM& atm, double amount) override {
        if (atm.getAccount()->withdraw(amount)) {
            auto bills = atm.getDispenser()->dispense((int)amount);
            cout << "Dispensed: ";
            for (auto& [d, c] : bills) cout << "$" << d << "x" << c << " ";
            cout << endl;
        } else cout << "Insufficient funds or daily limit reached" << endl;
    }
    void deposit(ATM& atm, double amount) override {
        atm.getAccount()->deposit(amount);
        cout << "Deposited $" << amount << ". Balance: $" << atm.getAccount()->getBalance() << endl;
    }
    void checkBalance(ATM& atm) override { cout << "Balance: $" << atm.getAccount()->getBalance() << endl; }
    void ejectCard(ATM& atm) override { cout << "Card ejected" << endl; atm.setState(make_shared<IdleState>()); }
};

class CardInsertedState : public ATMState {
    int attempts = 0;
public:
    void insertCard(ATM&) override { cout << "Card already inserted" << endl; }
    void enterPin(ATM& atm, const string& pin) override {
        if (atm.getAccount()->verifyPin(pin)) {
            cout << "PIN verified" << endl;
            atm.setState(make_shared<AuthenticatedState>());
        } else if (++attempts >= 3) {
            cout << "Card blocked!" << endl;
            atm.setState(make_shared<IdleState>());
        } else cout << "Wrong PIN. " << (3 - attempts) << " attempts left" << endl;
    }
    void withdraw(ATM&, double) override { cout << "Enter PIN first" << endl; }
    void deposit(ATM&, double) override { cout << "Enter PIN first" << endl; }
    void checkBalance(ATM&) override { cout << "Enter PIN first" << endl; }
    void ejectCard(ATM& atm) override { cout << "Card ejected" << endl; atm.setState(make_shared<IdleState>()); }
};

void IdleState::insertCard(ATM& atm) {
    cout << "Card inserted" << endl;
    atm.setState(make_shared<CardInsertedState>());
}

ATM::ATM() : state(make_shared<IdleState>()) {
    auto h100 = make_shared<CashHandler>(100, 100);
    auto h50 = make_shared<CashHandler>(50, 100);
    auto h20 = make_shared<CashHandler>(20, 100);
    auto h10 = make_shared<CashHandler>(10, 100);
    h100->setNext(h50); h50->setNext(h20); h20->setNext(h10);
    dispenser = h100;
}
