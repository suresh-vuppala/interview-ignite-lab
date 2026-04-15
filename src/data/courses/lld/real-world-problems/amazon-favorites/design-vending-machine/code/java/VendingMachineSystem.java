// Vending Machine — State Pattern
import java.util.*;

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
    public void decrementQuantity() { quantity--; }
    public boolean isAvailable() { return quantity > 0; }
}

interface VendingState {
    void insertMoney(VendingMachine vm, double amount);
    void selectProduct(VendingMachine vm, String code);
    void dispense(VendingMachine vm);
    void cancel(VendingMachine vm);
}

class IdleVendingState implements VendingState {
    public void insertMoney(VendingMachine vm, double amount) {
        vm.addBalance(amount);
        System.out.println("Inserted $" + amount + ". Balance: $" + vm.getBalance());
        vm.setState(new HasMoneyState());
    }
    public void selectProduct(VendingMachine vm, String code) { System.out.println("Insert money first"); }
    public void dispense(VendingMachine vm) { System.out.println("Insert money first"); }
    public void cancel(VendingMachine vm) { System.out.println("Nothing to cancel"); }
}

class HasMoneyState implements VendingState {
    public void insertMoney(VendingMachine vm, double amount) {
        vm.addBalance(amount);
        System.out.println("Balance: $" + vm.getBalance());
    }
    public void selectProduct(VendingMachine vm, String code) {
        Product p = vm.getProduct(code);
        if (p == null) { System.out.println("Invalid code"); return; }
        if (!p.isAvailable()) { System.out.println("Out of stock"); return; }
        if (vm.getBalance() < p.getPrice()) {
            System.out.printf("Need $%.2f more%n", p.getPrice() - vm.getBalance()); return;
        }
        vm.setSelectedProduct(p);
        vm.setState(new DispensingVendingState());
        vm.dispense();
    }
    public void dispense(VendingMachine vm) { System.out.println("Select a product first"); }
    public void cancel(VendingMachine vm) {
        System.out.println("Returning $" + vm.getBalance());
        vm.resetBalance();
        vm.setState(new IdleVendingState());
    }
}

class DispensingVendingState implements VendingState {
    public void insertMoney(VendingMachine vm, double a) { System.out.println("Please wait..."); }
    public void selectProduct(VendingMachine vm, String c) { System.out.println("Please wait..."); }
    public void dispense(VendingMachine vm) {
        Product p = vm.getSelectedProduct();
        p.decrementQuantity();
        double change = vm.getBalance() - p.getPrice();
        System.out.println("🎉 Dispensing: " + p.getName());
        if (change > 0) System.out.printf("Change: $%.2f%n", change);
        vm.resetBalance();
        vm.setSelectedProduct(null);
        vm.setState(new IdleVendingState());
    }
    public void cancel(VendingMachine vm) { System.out.println("Cannot cancel during dispensing"); }
}

class VendingMachine {
    private VendingState state = new IdleVendingState();
    private Map<String, Product> inventory = new LinkedHashMap<>();
    private double balance = 0;
    private Product selectedProduct;
    
    public void addProduct(Product p) { inventory.put(p.getCode(), p); }
    public Product getProduct(String code) { return inventory.get(code); }
    public void setState(VendingState s) { this.state = s; }
    public double getBalance() { return balance; }
    public void addBalance(double a) { balance += a; }
    public void resetBalance() { balance = 0; }
    public Product getSelectedProduct() { return selectedProduct; }
    public void setSelectedProduct(Product p) { this.selectedProduct = p; }
    
    public void insertMoney(double amount) { state.insertMoney(this, amount); }
    public void selectProduct(String code) { state.selectProduct(this, code); }
    public void dispense() { state.dispense(this); }
    public void cancel() { state.cancel(this); }
}
