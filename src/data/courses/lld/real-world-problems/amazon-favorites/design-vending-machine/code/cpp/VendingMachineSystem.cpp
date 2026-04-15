#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <iomanip>
using namespace std;

struct Product {
    string code, name;
    double price;
    int quantity;
    bool isAvailable() const { return quantity > 0; }
    void decrement() { quantity--; }
};

class VendingMachine; // Forward

class VendingState {
public:
    virtual ~VendingState() = default;
    virtual void insertMoney(VendingMachine& vm, double amount) = 0;
    virtual void selectProduct(VendingMachine& vm, const string& code) = 0;
    virtual void dispense(VendingMachine& vm) = 0;
    virtual void cancel(VendingMachine& vm) = 0;
};

class VendingMachine {
    shared_ptr<VendingState> state;
    map<string, Product> inventory;
    double balance = 0;
    Product* selectedProduct = nullptr;
public:
    VendingMachine();
    void setState(shared_ptr<VendingState> s) { state = move(s); }
    void addProduct(Product p) { inventory[p.code] = move(p); }
    Product* getProduct(const string& code) { auto it = inventory.find(code); return it != inventory.end() ? &it->second : nullptr; }
    double getBalance() const { return balance; }
    void addBalance(double a) { balance += a; }
    void resetBalance() { balance = 0; }
    Product* getSelectedProduct() { return selectedProduct; }
    void setSelectedProduct(Product* p) { selectedProduct = p; }
    void insertMoney(double a) { state->insertMoney(*this, a); }
    void selectProduct(const string& code) { state->selectProduct(*this, code); }
    void dispense() { state->dispense(*this); }
    void cancel() { state->cancel(*this); }
};

class IdleVState : public VendingState {
public:
    void insertMoney(VendingMachine& vm, double amount) override;
    void selectProduct(VendingMachine&, const string&) override { cout << "Insert money first" << endl; }
    void dispense(VendingMachine&) override { cout << "Insert money first" << endl; }
    void cancel(VendingMachine&) override { cout << "Nothing to cancel" << endl; }
};

class HasMoneyState : public VendingState {
public:
    void insertMoney(VendingMachine& vm, double amount) override { vm.addBalance(amount); cout << "Balance: $" << fixed << setprecision(2) << vm.getBalance() << endl; }
    void selectProduct(VendingMachine& vm, const string& code) override;
    void dispense(VendingMachine&) override { cout << "Select a product first" << endl; }
    void cancel(VendingMachine& vm) override { cout << "Returning $" << vm.getBalance() << endl; vm.resetBalance(); vm.setState(make_shared<IdleVState>()); }
};

class DispensingVState : public VendingState {
public:
    void insertMoney(VendingMachine&, double) override { cout << "Please wait..." << endl; }
    void selectProduct(VendingMachine&, const string&) override { cout << "Please wait..." << endl; }
    void dispense(VendingMachine& vm) override {
        auto* p = vm.getSelectedProduct();
        p->decrement();
        double change = vm.getBalance() - p->price;
        cout << "Dispensing: " << p->name << endl;
        if (change > 0) cout << "Change: $" << fixed << setprecision(2) << change << endl;
        vm.resetBalance(); vm.setSelectedProduct(nullptr); vm.setState(make_shared<IdleVState>());
    }
    void cancel(VendingMachine&) override { cout << "Cannot cancel during dispensing" << endl; }
};

void IdleVState::insertMoney(VendingMachine& vm, double amount) {
    vm.addBalance(amount); cout << "Inserted $" << amount << ". Balance: $" << vm.getBalance() << endl;
    vm.setState(make_shared<HasMoneyState>());
}
void HasMoneyState::selectProduct(VendingMachine& vm, const string& code) {
    auto* p = vm.getProduct(code);
    if (!p) { cout << "Invalid code" << endl; return; }
    if (!p->isAvailable()) { cout << "Out of stock" << endl; return; }
    if (vm.getBalance() < p->price) { cout << "Need $" << (p->price - vm.getBalance()) << " more" << endl; return; }
    vm.setSelectedProduct(p); vm.setState(make_shared<DispensingVState>()); vm.dispense();
}
VendingMachine::VendingMachine() : state(make_shared<IdleVState>()) {}
