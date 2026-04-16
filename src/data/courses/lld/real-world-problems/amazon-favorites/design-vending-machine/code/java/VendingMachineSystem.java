// ===========================================================================
// DESIGN: Vending Machine — Low Level Design (Java)
// ===========================================================================
// Pattern: State Pattern | Principles: SOLID, Encapsulation
// ===========================================================================

// 1. FUNCTIONAL REQUIREMENTS: Display products, accept payment, select product,
//    dispense with change, cancel transaction, inventory tracking
// 2. CONSTRAINTS: 10 slots, max 20 items/slot, $0.50-$10 prices
// 3. RELATIONSHIPS: VendingMachine*--VendingState, VendingMachine*--Product
//    IdleState/HasMoneyState/DispensingState implements VendingState
// 4. PLANTUML: (see C++ file for full diagram)

import java.util.*;

// ===========================================================================
// CLASS: Product
// ===========================================================================
class Product {
    private String code, name;
    private double price;
    private int quantity;

    public Product(String code, String name, double price, int qty) {
        this.code = code; this.name = name; this.price = price; this.quantity = qty;
    }

    public String getCode() { return code; }
    public String getName() { return name; }
    public double getPrice() { return price; }
    public int getQuantity() { return quantity; }
    public boolean isAvailable() { return quantity > 0; }
    public void decrement() { if (quantity > 0) quantity--; }

    public void display() {
        System.out.printf("  [%s] %-20s $%.2f  (Stock: %d)%s%n",
            code, name, price, quantity, quantity == 0 ? " SOLD OUT" : "");
    }
}

// ===========================================================================
// INTERFACE: VendingState [State Pattern]
// ===========================================================================
interface VendingState {
    void insertMoney(VendingMach vm, double amount);
    void selectProduct(VendingMach vm, String code);
    void dispense(VendingMach vm);
    void cancel(VendingMach vm);
    String getStateName();
}

// ===========================================================================
// Concrete States
// ===========================================================================
class IdleState implements VendingState {
    public void insertMoney(VendingMach vm, double amount) {
        vm.addBalance(amount);
        System.out.printf("  Inserted $%.2f. Balance: $%.2f%n", amount, vm.getBalance());
        vm.setState(new HasMoneyState());
    }
    public void selectProduct(VendingMach vm, String code) { System.out.println("  [ERROR] Insert money first."); }
    public void dispense(VendingMach vm) { System.out.println("  [ERROR] Insert money first."); }
    public void cancel(VendingMach vm) { System.out.println("  Nothing to cancel."); }
    public String getStateName() { return "IDLE"; }
}

class HasMoneyState implements VendingState {
    public void insertMoney(VendingMach vm, double amount) {
        vm.addBalance(amount);
        System.out.printf("  Added $%.2f. Balance: $%.2f%n", amount, vm.getBalance());
    }

    public void selectProduct(VendingMach vm, String code) {
        Product p = vm.getProduct(code);
        if (p == null) { System.out.println("  [ERROR] Invalid code: " + code); return; }
        if (!p.isAvailable()) { System.out.println("  [ERROR] " + p.getName() + " SOLD OUT."); return; }
        if (vm.getBalance() < p.getPrice()) {
            System.out.printf("  [ERROR] Need $%.2f more.%n", p.getPrice() - vm.getBalance()); return;
        }
        System.out.println("  Selected: " + p.getName());
        vm.setSelectedProduct(p);
        vm.setState(new DispensingState());
        vm.dispense();
    }

    public void dispense(VendingMach vm) { System.out.println("  Select a product first."); }

    public void cancel(VendingMach vm) {
        System.out.printf("  Returning $%.2f. Cancelled.%n", vm.getBalance());
        vm.resetBalance(); vm.setSelectedProduct(null); vm.setState(new IdleState());
    }

    public String getStateName() { return "HAS_MONEY"; }
}

class DispensingState implements VendingState {
    public void insertMoney(VendingMach vm, double a) { System.out.println("  Please wait..."); }
    public void selectProduct(VendingMach vm, String c) { System.out.println("  Please wait..."); }

    public void dispense(VendingMach vm) {
        Product p = vm.getSelectedProduct();
        p.decrement();
        double change = vm.getBalance() - p.getPrice();
        System.out.println("  ** Dispensing: " + p.getName() + " **");
        if (change > 0.001) System.out.printf("  Change: $%.2f%n", change);
        vm.resetBalance(); vm.setSelectedProduct(null); vm.setState(new IdleState());
    }

    public void cancel(VendingMach vm) { System.out.println("  Cannot cancel during dispensing."); }
    public String getStateName() { return "DISPENSING"; }
}

// ===========================================================================
// CLASS: VendingMach [Context — State Pattern]
// ===========================================================================
class VendingMach {
    private VendingState state = new IdleState();
    private Map<String, Product> inventory = new LinkedHashMap<>();
    private double balance = 0;
    private Product selectedProduct;

    public void setState(VendingState s) { this.state = s; }
    public void addProduct(Product p) { inventory.put(p.getCode(), p); }
    public Product getProduct(String code) { return inventory.get(code); }
    public double getBalance() { return balance; }
    public void addBalance(double a) { balance += a; }
    public void resetBalance() { balance = 0; }
    public Product getSelectedProduct() { return selectedProduct; }
    public void setSelectedProduct(Product p) { this.selectedProduct = p; }

    public void showProducts() {
        System.out.println("\n--- Products ---");
        for (Product p : inventory.values()) p.display();
    }

    public void insertMoney(double a) {
        System.out.println("\n>> Insert $" + a + " (" + state.getStateName() + ")");
        state.insertMoney(this, a);
    }
    public void selectProduct(String code) {
        System.out.println("\n>> Select " + code + " (" + state.getStateName() + ")");
        state.selectProduct(this, code);
    }
    public void dispense() { state.dispense(this); }
    public void cancel() {
        System.out.println("\n>> Cancel (" + state.getStateName() + ")");
        state.cancel(this);
    }
}

// ===========================================================================
// MAIN
// ===========================================================================
public class VendingMachineSystem {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  Vending Machine — LLD Demo (Java)");
        System.out.println("============================================");

        VendingMach vm = new VendingMach();
        vm.addProduct(new Product("A1", "Coca-Cola", 1.50, 5));
        vm.addProduct(new Product("A2", "Pepsi", 1.50, 3));
        vm.addProduct(new Product("B1", "Chips", 2.00, 2));
        vm.addProduct(new Product("B2", "Candy Bar", 1.25, 0));
        vm.addProduct(new Product("C1", "Water", 1.00, 10));
        vm.showProducts();

        // Scenario 1: Buy Coca-Cola
        System.out.println("\n====== Buy Coca-Cola ======");
        vm.insertMoney(1.00); vm.insertMoney(1.00); vm.selectProduct("A1");

        // Scenario 2: Insufficient
        System.out.println("\n====== Insufficient ======");
        vm.insertMoney(0.50); vm.selectProduct("B1"); vm.cancel();

        // Scenario 3: Sold Out
        System.out.println("\n====== Sold Out ======");
        vm.insertMoney(2.00); vm.selectProduct("B2"); vm.cancel();

        vm.showProducts();
        System.out.println("\n=== All scenarios complete ===");
    }
}

// SUMMARY:
// EXECUTION FLOW: main() -> VendingMach(IdleState) -> insertMoney -> setState(HasMoney)
//   -> selectProduct -> validate -> setState(Dispensing) -> dispense -> setState(Idle)
// DESIGN PATTERNS: State -> Idle/HasMoney/Dispensing
// CLASS TABLE: Product(inventory) | VendingState(interface) | IdleState/HasMoneyState/DispensingState | VendingMach(context)
// BEST PRACTICES: Encapsulation, Polymorphism, SRP per state, OCP for new states
