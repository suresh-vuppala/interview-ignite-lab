// Pizza Pricing System — Decorator + Builder + Strategy
import java.util.*;

// ========== PIZZA (Decorator Pattern) ==========
interface Pizza {
    String getDescription();
    double getCost();
}

enum Size { SMALL, MEDIUM, LARGE }
enum Crust { THIN, REGULAR, STUFFED }

class BasePizza implements Pizza {
    private Size size;
    private Crust crust;
    private static final Map<Size, Double> SIZE_PRICE = Map.of(
        Size.SMALL, 6.0, Size.MEDIUM, 8.0, Size.LARGE, 10.0);
    private static final Map<Crust, Double> CRUST_PRICE = Map.of(
        Crust.THIN, 0.0, Crust.REGULAR, 0.0, Crust.STUFFED, 2.0);
    
    public BasePizza(Size size, Crust crust) { this.size = size; this.crust = crust; }
    public String getDescription() { return size + " " + crust + " Pizza"; }
    public double getCost() { return SIZE_PRICE.get(size) + CRUST_PRICE.get(crust); }
}

abstract class ToppingDecorator implements Pizza {
    protected Pizza pizza;
    public ToppingDecorator(Pizza pizza) { this.pizza = pizza; }
}

class CheeseTopping extends ToppingDecorator {
    public CheeseTopping(Pizza p) { super(p); }
    public String getDescription() { return pizza.getDescription() + " + Cheese"; }
    public double getCost() { return pizza.getCost() + 1.50; }
}

class PepperoniTopping extends ToppingDecorator {
    public PepperoniTopping(Pizza p) { super(p); }
    public String getDescription() { return pizza.getDescription() + " + Pepperoni"; }
    public double getCost() { return pizza.getCost() + 2.00; }
}

class MushroomTopping extends ToppingDecorator {
    public MushroomTopping(Pizza p) { super(p); }
    public String getDescription() { return pizza.getDescription() + " + Mushroom"; }
    public double getCost() { return pizza.getCost() + 1.00; }
}

// ========== DISCOUNT (Strategy Pattern) ==========
interface DiscountStrategy {
    double apply(double total);
    String getDescription();
}

class PercentageDiscount implements DiscountStrategy {
    private double percent;
    public PercentageDiscount(double percent) { this.percent = percent; }
    public double apply(double total) { return total * (1 - percent / 100); }
    public String getDescription() { return percent + "% off"; }
}

class FlatDiscount implements DiscountStrategy {
    private double amount;
    public FlatDiscount(double amount) { this.amount = amount; }
    public double apply(double total) { return Math.max(0, total - amount); }
    public String getDescription() { return "$" + amount + " off"; }
}

// ========== ORDER ==========
class PizzaOrder {
    private List<Pizza> pizzas = new ArrayList<>();
    private DiscountStrategy discount;
    
    public void addPizza(Pizza pizza) { pizzas.add(pizza); }
    public void setDiscount(DiscountStrategy d) { this.discount = d; }
    
    public double getSubtotal() {
        return pizzas.stream().mapToDouble(Pizza::getCost).sum();
    }
    
    public double getTotal() {
        double subtotal = getSubtotal();
        return discount != null ? discount.apply(subtotal) : subtotal;
    }
    
    public void printReceipt() {
        System.out.println("=== Pizza Order ===");
        for (Pizza p : pizzas)
            System.out.printf("  %s — $%.2f%n", p.getDescription(), p.getCost());
        System.out.printf("Subtotal: $%.2f%n", getSubtotal());
        if (discount != null) System.out.println("Discount: " + discount.getDescription());
        System.out.printf("TOTAL: $%.2f%n", getTotal());
    }
}

// Usage:
// Pizza p1 = new PepperoniTopping(new CheeseTopping(new BasePizza(Size.LARGE, Crust.STUFFED)));
// Pizza p2 = new MushroomTopping(new BasePizza(Size.MEDIUM, Crust.THIN));
// PizzaOrder order = new PizzaOrder();
// order.addPizza(p1); order.addPizza(p2);
// order.setDiscount(new PercentageDiscount(10));
// order.printReceipt();
