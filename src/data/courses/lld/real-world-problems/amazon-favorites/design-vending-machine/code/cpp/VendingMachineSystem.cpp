// ===========================================================================
// DESIGN: Vending Machine — Low Level Design
// ===========================================================================
// Single-file C++ | Pattern: State Pattern
// Principles: SOLID, Encapsulation, Polymorphism
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS
// FR1: Display products with name, price, availability, product code
// FR2: Accept payment — coins ($0.25, $0.50, $1.00), bills ($1, $5)
// FR3: Select product by code — validate payment covers price
// FR4: Dispense product and return correct change
// FR5: Cancel transaction — return all inserted money
// FR6: Inventory management — track stock per slot

// 2. CONSTRAINTS: 10 slots, max 20 items/slot, $0.50-$10 prices

// 3. RELATIONSHIPS
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | VendingMachine     | VendingState     | Composition  | 1 -> 1      | Machine owns current state |
// | VendingMachine     | Product          | Composition  | 1 -> many   | Machine owns inventory     |
// | IdleState          | VendingState     | Inheritance  | IS-A        | Concrete state             |
// | HasMoneyState      | VendingState     | Inheritance  | IS-A        | Concrete state             |
// | DispensingState    | VendingState     | Inheritance  | IS-A        | Concrete state             |
// +-------------------+------------------+--------------+-------------+----------------------------+

// 4. PLANTUML
// @startuml VendingMachine
// class VendingMachine { -state:VendingState* \n -inventory:map \n -balance:double }
// interface VendingState { +insertMoney() +selectProduct() +dispense() +cancel() }
// class IdleState
// class HasMoneyState
// class DispensingState
// class Product { -code -name -price -quantity }
// VendingMachine *-- VendingState
// VendingMachine *-- "0..*" Product
// VendingState <|.. IdleState
// VendingState <|.. HasMoneyState
// VendingState <|.. DispensingState
// @enduml

#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

// ===========================================================================
// CLASS: Product [Inventory Item]
// ===========================================================================
class Product {
private:
    string code;     // e.g., "A1", "B2"
    string name;     // Product name
    double price;    // Price in dollars
    int quantity;    // Current stock

public:
    Product() : price(0), quantity(0) {}

    Product(const string& code, const string& name, double price, int qty)
        : code(code), name(name), price(price), quantity(qty) {}

    string getCode() const { return code; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    bool isAvailable() const { return quantity > 0; }

    void decrement() {
        if (quantity > 0) quantity--;
    }

    void display() const {
        printf("  [%s] %-20s $%.2f  (Stock: %d)%s\n",
               code.c_str(), name.c_str(), price, quantity,
               quantity == 0 ? " SOLD OUT" : "");
    }
};

// Forward declaration
class VendingMachine;

// ===========================================================================
// INTERFACE: VendingState [State Pattern]
// Responsibility: Define behavior for each machine state
// ===========================================================================
class VendingState {
public:
    virtual ~VendingState() {}
    virtual void insertMoney(VendingMachine& vm, double amount) = 0;
    virtual void selectProduct(VendingMachine& vm, const string& code) = 0;
    virtual void dispense(VendingMachine& vm) = 0;
    virtual void cancel(VendingMachine& vm) = 0;
    virtual string getStateName() const = 0;
};

// ===========================================================================
// CLASS: VendingMachine [Context — State Pattern]
// ===========================================================================
class VendingMachine {
private:
    VendingState* state;
    map<string, Product> inventory;
    double balance;
    Product* selectedProduct;

public:
    VendingMachine();
    ~VendingMachine() { delete state; }

    void setState(VendingState* s) {
        delete state;
        state = s;
    }

    void addProduct(const Product& p) { inventory[p.getCode()] = p; }

    Product* getProduct(const string& code) {
        map<string, Product>::iterator it = inventory.find(code);
        return (it != inventory.end()) ? &it->second : NULL;
    }

    double getBalance() const { return balance; }
    void addBalance(double a) { balance += a; }
    void resetBalance() { balance = 0; }
    Product* getSelectedProduct() { return selectedProduct; }
    void setSelectedProduct(Product* p) { selectedProduct = p; }

    // Display all products
    void showProducts() const {
        cout << "\n--- Products ---" << endl;
        for (map<string, Product>::const_iterator it = inventory.begin();
             it != inventory.end(); ++it) {
            it->second.display();
        }
    }

    // Delegated to current state
    void insertMoney(double amount) {
        cout << "\n>> Insert $" << amount << " (State: " << state->getStateName() << ")" << endl;
        state->insertMoney(*this, amount);
    }

    void selectProduct(const string& code) {
        cout << "\n>> Select " << code << " (State: " << state->getStateName() << ")" << endl;
        state->selectProduct(*this, code);
    }

    void dispense() { state->dispense(*this); }

    void cancel() {
        cout << "\n>> Cancel (State: " << state->getStateName() << ")" << endl;
        state->cancel(*this);
    }
};

// ===========================================================================
// Concrete States
// ===========================================================================

class IdleState : public VendingState {
public:
    void insertMoney(VendingMachine& vm, double amount) {
        vm.addBalance(amount);
        printf("  Inserted $%.2f. Balance: $%.2f\n", amount, vm.getBalance());
        // Transition to HasMoney state
        vm.setState(new class HasMoneyState());
    }

    void selectProduct(VendingMachine& vm, const string& code) {
        cout << "  [ERROR] Insert money first." << endl;
    }

    void dispense(VendingMachine& vm) {
        cout << "  [ERROR] Insert money first." << endl;
    }

    void cancel(VendingMachine& vm) {
        cout << "  Nothing to cancel." << endl;
    }

    string getStateName() const { return "IDLE"; }
};

class DispensingState : public VendingState {
public:
    void insertMoney(VendingMachine& vm, double amount) {
        cout << "  Please wait, dispensing..." << endl;
    }

    void selectProduct(VendingMachine& vm, const string& code) {
        cout << "  Please wait, dispensing..." << endl;
    }

    void dispense(VendingMachine& vm) {
        Product* p = vm.getSelectedProduct();
        if (p == NULL) return;

        // Dispense product
        p->decrement();
        double change = vm.getBalance() - p->getPrice();

        cout << "  ** Dispensing: " << p->getName() << " **" << endl;
        if (change > 0.001) {
            printf("  Change returned: $%.2f\n", change);
        }

        // Reset and return to idle
        vm.resetBalance();
        vm.setSelectedProduct(NULL);
        vm.setState(new IdleState());
    }

    void cancel(VendingMachine& vm) {
        cout << "  Cannot cancel during dispensing." << endl;
    }

    string getStateName() const { return "DISPENSING"; }
};

class HasMoneyState : public VendingState {
public:
    void insertMoney(VendingMachine& vm, double amount) {
        vm.addBalance(amount);
        printf("  Added $%.2f. Balance: $%.2f\n", amount, vm.getBalance());
    }

    void selectProduct(VendingMachine& vm, const string& code) {
        Product* p = vm.getProduct(code);

        // Validate product
        if (p == NULL) {
            cout << "  [ERROR] Invalid product code: " << code << endl;
            return;
        }
        if (!p->isAvailable()) {
            cout << "  [ERROR] " << p->getName() << " is SOLD OUT." << endl;
            return;
        }
        if (vm.getBalance() < p->getPrice()) {
            printf("  [ERROR] Need $%.2f more.\n", p->getPrice() - vm.getBalance());
            return;
        }

        // Proceed to dispense
        cout << "  Selected: " << p->getName() << endl;
        vm.setSelectedProduct(p);
        vm.setState(new DispensingState());
        vm.dispense();  // Auto-dispense
    }

    void dispense(VendingMachine& vm) {
        cout << "  Select a product first." << endl;
    }

    void cancel(VendingMachine& vm) {
        printf("  Returning $%.2f. Transaction cancelled.\n", vm.getBalance());
        vm.resetBalance();
        vm.setSelectedProduct(NULL);
        vm.setState(new IdleState());
    }

    string getStateName() const { return "HAS_MONEY"; }
};

// Constructor
VendingMachine::VendingMachine()
    : balance(0), selectedProduct(NULL) {
    state = new IdleState();
}

// ===========================================================================
// MAIN
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Vending Machine — LLD Demo" << endl;
    cout << "============================================" << endl;

    VendingMachine vm;
    vm.addProduct(Product("A1", "Coca-Cola", 1.50, 5));
    vm.addProduct(Product("A2", "Pepsi", 1.50, 3));
    vm.addProduct(Product("B1", "Chips", 2.00, 2));
    vm.addProduct(Product("B2", "Candy Bar", 1.25, 0));  // SOLD OUT
    vm.addProduct(Product("C1", "Water", 1.00, 10));

    vm.showProducts();

    // Scenario 1: Successful purchase
    cout << "\n====== Scenario 1: Buy Coca-Cola ======" << endl;
    vm.insertMoney(1.00);
    vm.insertMoney(1.00);
    vm.selectProduct("A1");

    // Scenario 2: Insufficient payment
    cout << "\n====== Scenario 2: Insufficient ======" << endl;
    vm.insertMoney(0.50);
    vm.selectProduct("B1");  // Needs $2.00

    // Scenario 3: Cancel and get refund
    cout << "\n====== Scenario 3: Cancel ======" << endl;
    vm.cancel();  // Get $0.50 back

    // Scenario 4: Sold out
    cout << "\n====== Scenario 4: Sold Out ======" << endl;
    vm.insertMoney(2.00);
    vm.selectProduct("B2");  // Candy Bar is sold out
    vm.cancel();

    // Scenario 5: Invalid code
    cout << "\n====== Scenario 5: Invalid Code ======" << endl;
    vm.insertMoney(1.00);
    vm.selectProduct("Z9");
    vm.cancel();

    // Show final inventory
    vm.showProducts();

    cout << "\n============================================" << endl;
    cout << "  All scenarios completed!" << endl;
    cout << "============================================" << endl;

    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> VendingMachine (IdleState) -> addProducts
//     -> insertMoney(1.00) -> IdleState.insertMoney() -> addBalance + setState(HasMoney)
//     -> insertMoney(1.00) -> HasMoneyState.insertMoney() -> addBalance
//     -> selectProduct("A1") -> HasMoneyState.selectProduct()
//        -> validate code + stock + balance
//        -> setState(DispensingState) -> dispense()
//           -> product.decrement() + calculate change + setState(Idle)

// METHOD CALL TREE:
//   vm.insertMoney(amount) -> state->insertMoney(vm, amount) [State dispatch]
//   vm.selectProduct(code) -> state->selectProduct(vm, code) [State dispatch]
//     -> vm.getProduct(code) -> isAvailable()? -> balance >= price?
//     -> setState(Dispensing) -> dispense()
//        -> product.decrement() -> calculate change -> resetBalance -> setState(Idle)

// CLASS RESPONSIBILITY TABLE:
//   Product        | Code, name, price, quantity, availability
//   VendingState   | State interface: insertMoney, select, dispense, cancel
//   IdleState      | Only accepts money insertion
//   HasMoneyState  | Accepts more money, product selection, cancel
//   DispensingState| Dispenses product, returns change
//   VendingMachine | Context: inventory, balance, state management

// DESIGN PATTERNS:
//   1. State -> Machine states (Idle/HasMoney/Dispensing)
//      Reason: Same action behaves differently per state

// BEST PRACTICES:
//   1. Encapsulation  -> balance/state private, methods for access
//   2. Polymorphism   -> VendingState dispatched at runtime
//   3. SRP            -> Each state handles only its behavior
//   4. OCP            -> New states without modifying VendingMachine
//   5. Validation     -> Product exists? Available? Balance sufficient?
