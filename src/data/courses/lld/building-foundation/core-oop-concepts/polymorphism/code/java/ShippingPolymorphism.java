// Polymorphism Example — Shipping Cost Calculator
interface ShippingStrategy {
    double calculateCost(double weight, double distance);
    String getEstimatedDelivery();
}

class StandardShipping implements ShippingStrategy {
    public double calculateCost(double weight, double distance) {
        return weight * 0.5 + distance * 0.1;
    }
    public String getEstimatedDelivery() { return "5-7 business days"; }
}

class ExpressShipping implements ShippingStrategy {
    public double calculateCost(double weight, double distance) {
        return weight * 1.5 + distance * 0.3 + 10; // Surcharge
    }
    public String getEstimatedDelivery() { return "1-2 business days"; }
}

class FreeShipping implements ShippingStrategy {
    public double calculateCost(double weight, double distance) { return 0; }
    public String getEstimatedDelivery() { return "7-10 business days"; }
}

// Usage — polymorphism in action
class Order {
    private ShippingStrategy shipping;  // Declared as interface
    
    public void setShipping(ShippingStrategy strategy) { this.shipping = strategy; }
    
    public double getShippingCost(double weight, double distance) {
        return shipping.calculateCost(weight, distance);  // Runtime dispatch
    }
}
