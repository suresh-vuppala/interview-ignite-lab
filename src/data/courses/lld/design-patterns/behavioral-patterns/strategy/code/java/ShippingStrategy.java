// Strategy — Shipping Cost Calculator
interface ShippingStrategy {
    double calculate(double weight, double distance);
    int getEstimatedDays();
}

class StandardShipping implements ShippingStrategy {
    public double calculate(double weight, double distance) {
        return weight * 0.5 + distance * 0.01;
    }
    public int getEstimatedDays() { return 7; }
}

class ExpressShipping implements ShippingStrategy {
    public double calculate(double weight, double distance) {
        return weight * 1.5 + distance * 0.05 + 15.00;
    }
    public int getEstimatedDays() { return 2; }
}

class FreeShipping implements ShippingStrategy {
    public double calculate(double weight, double distance) { return 0; }
    public int getEstimatedDays() { return 14; }
}

class Order {
    private ShippingStrategy shippingStrategy;
    private double weight;
    private double distance;
    
    public void setShippingStrategy(ShippingStrategy strategy) {
        this.shippingStrategy = strategy;
    }
    
    public double getShippingCost() {
        return shippingStrategy.calculate(weight, distance);
    }
}
