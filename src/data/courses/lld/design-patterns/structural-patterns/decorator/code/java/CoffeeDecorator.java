// Decorator — Coffee Shop Pricing
interface Coffee {
    String getDescription();
    double getCost();
}

class SimpleCoffee implements Coffee {
    public String getDescription() { return "Simple Coffee"; }
    public double getCost() { return 2.00; }
}

abstract class CoffeeDecorator implements Coffee {
    protected Coffee decorated;
    public CoffeeDecorator(Coffee coffee) { this.decorated = coffee; }
}

class MilkDecorator extends CoffeeDecorator {
    public MilkDecorator(Coffee c) { super(c); }
    public String getDescription() { return decorated.getDescription() + " + Milk"; }
    public double getCost() { return decorated.getCost() + 0.50; }
}

class SugarDecorator extends CoffeeDecorator {
    public SugarDecorator(Coffee c) { super(c); }
    public String getDescription() { return decorated.getDescription() + " + Sugar"; }
    public double getCost() { return decorated.getCost() + 0.25; }
}

class WhipCreamDecorator extends CoffeeDecorator {
    public WhipCreamDecorator(Coffee c) { super(c); }
    public String getDescription() { return decorated.getDescription() + " + Whip Cream"; }
    public double getCost() { return decorated.getCost() + 0.75; }
}

// Usage — compose at runtime
// Coffee order = new WhipCreamDecorator(new MilkDecorator(new SimpleCoffee()));
// order.getDescription() → "Simple Coffee + Milk + Whip Cream"
// order.getCost() → 2.00 + 0.50 + 0.75 = 3.25
