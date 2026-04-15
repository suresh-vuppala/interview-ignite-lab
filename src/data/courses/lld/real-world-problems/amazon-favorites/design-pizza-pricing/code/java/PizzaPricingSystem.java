// ===========================================================================
// DESIGN: Pizza Pricing System — Low Level Design
// ===========================================================================
// Fully functional single-file Java implementation
// Patterns: Decorator Pattern, Strategy Pattern
// Principles: SOLID, Composition over Inheritance, OCP
// ===========================================================================

// ---------------------------------------------------------------------------
// 1. FUNCTIONAL REQUIREMENTS
// ---------------------------------------------------------------------------
// FR1: Create base pizza with size (Small/Medium/Large) and crust (Thin/Regular/Stuffed)
// FR2: Add multiple toppings dynamically, each adding its own cost
// FR3: Calculate total = base price + sum of all topping prices
// FR4: Support discount strategies (Percentage, Flat, BOGO)
// FR5: Manage orders with multiple pizzas
// FR6: Generate itemized receipt

// ---------------------------------------------------------------------------
// 2. CONSTRAINTS & ASSUMPTIONS
// ---------------------------------------------------------------------------
// - Sizes: Small($6), Medium($8), Large($10)
// - Crusts: Thin(free), Regular(free), Stuffed(+$2)
// - Toppings: $0.50 to $3.00 each, max 10 per pizza
// - One discount per order

// ---------------------------------------------------------------------------
// 3. CORE ENTITIES & RELATIONSHIPS
// ---------------------------------------------------------------------------
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | ToppingDecorator   | Pizza            | Composition  | 1 -> 1      | Wraps a pizza              |
// | BasePizza          | Pizza            | Inheritance  | IS-A        | Concrete component         |
// | ToppingDecorator   | Pizza            | Inheritance  | IS-A        | Decorator IS-A Pizza       |
// | PizzaOrder         | Pizza            | Aggregation  | 1 -> many   | Order has pizzas           |
// | PizzaOrder         | DiscountStrategy | Association  | 1 -> 0..1   | Order may have discount    |
// | PercentageDiscount | DiscountStrategy | Inheritance  | IS-A        | Concrete strategy          |
// | FlatDiscount       | DiscountStrategy | Inheritance  | IS-A        | Concrete strategy          |
// +-------------------+------------------+--------------+-------------+----------------------------+

// ---------------------------------------------------------------------------
// 4. PLANTUML
// ---------------------------------------------------------------------------
// @startuml PizzaPricing
// interface Pizza { +getDescription():String \n +getCost():double }
// class BasePizza { -size:Size \n -crust:Crust }
// abstract class ToppingDecorator { #wrapped:Pizza }
// class CheeseTopping
// class PepperoniTopping
// class MushroomTopping
// class OlivesTopping
// class JalapenoTopping
// interface DiscountStrategy { +apply(total):double \n +describe():String }
// class PercentageDiscount { -percent }
// class FlatDiscount { -amount }
// class BOGODiscount
// class PizzaOrder { -pizzas:List<Pizza> \n -discount:DiscountStrategy }
// Pizza <|.. BasePizza
// Pizza <|.. ToppingDecorator
// ToppingDecorator *-- Pizza : wraps
// ToppingDecorator <|-- CheeseTopping
// ToppingDecorator <|-- PepperoniTopping
// ToppingDecorator <|-- MushroomTopping
// ToppingDecorator <|-- OlivesTopping
// ToppingDecorator <|-- JalapenoTopping
// DiscountStrategy <|.. PercentageDiscount
// DiscountStrategy <|.. FlatDiscount
// DiscountStrategy <|.. BOGODiscount
// PizzaOrder o-- "0..*" Pizza
// PizzaOrder --> "0..1" DiscountStrategy
// @enduml

import java.util.*;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================

// Pizza size with base pricing
enum Size {
    SMALL(6.00),
    MEDIUM(8.00),
    LARGE(10.00);

    private final double price;
    Size(double price) { this.price = price; }
    public double getPrice() { return price; }
}

// Crust type with surcharge
enum Crust {
    THIN(0.00),
    REGULAR(0.00),
    STUFFED(2.00);

    private final double surcharge;
    Crust(double surcharge) { this.surcharge = surcharge; }
    public double getSurcharge() { return surcharge; }
}

// ===========================================================================
// INTERFACE: Pizza [Decorator Pattern: Component]
// Responsibility: Contract for all pizza objects (base + decorated)
// ===========================================================================
interface Pizza {
    // Get description including all toppings
    String getDescription();

    // Get total cost including all toppings
    double getCost();
}

// ===========================================================================
// CLASS: BasePizza [Decorator: Concrete Component]
// Responsibility: Base pizza with size and crust pricing
// ===========================================================================
class BasePizza implements Pizza {
    private final Size size;      // Determines base price
    private final Crust crust;    // May add surcharge

    public BasePizza(Size size, Crust crust) {
        this.size = size;
        this.crust = crust;
    }

    @Override
    public String getDescription() {
        return size.name() + " " + crust.name() + " Pizza";
    }

    @Override
    public double getCost() {
        return size.getPrice() + crust.getSurcharge();
    }
}

// ===========================================================================
// CLASS: ToppingDecorator [Decorator: Base Decorator]
// Responsibility: Wraps a Pizza and adds topping behavior
// Relationship: IS-A Pizza AND HAS-A Pizza (Composition)
// ===========================================================================
abstract class ToppingDecorator implements Pizza {
    protected final Pizza wrapped;  // The pizza being decorated

    public ToppingDecorator(Pizza pizza) {
        this.wrapped = pizza;
    }
}

// ===========================================================================
// Concrete Topping Decorators
// ===========================================================================

// Cheese: +$1.50
class CheeseTopping extends ToppingDecorator {
    public CheeseTopping(Pizza p) { super(p); }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + " + Cheese";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 1.50;
    }
}

// Pepperoni: +$2.00
class PepperoniTopping extends ToppingDecorator {
    public PepperoniTopping(Pizza p) { super(p); }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + " + Pepperoni";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 2.00;
    }
}

// Mushroom: +$1.00
class MushroomTopping extends ToppingDecorator {
    public MushroomTopping(Pizza p) { super(p); }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + " + Mushroom";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 1.00;
    }
}

// Olives: +$0.75
class OlivesTopping extends ToppingDecorator {
    public OlivesTopping(Pizza p) { super(p); }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + " + Olives";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 0.75;
    }
}

// Jalapeno: +$0.50
class JalapenoTopping extends ToppingDecorator {
    public JalapenoTopping(Pizza p) { super(p); }

    @Override
    public String getDescription() {
        return wrapped.getDescription() + " + Jalapeno";
    }

    @Override
    public double getCost() {
        return wrapped.getCost() + 0.50;
    }
}

// ===========================================================================
// INTERFACE: DiscountStrategy [Strategy Pattern]
// Responsibility: Contract for discount calculation
// ===========================================================================
interface DiscountStrategy {
    double apply(double total);
    String describe();
}

// ===========================================================================
// Concrete Discount Strategies
// ===========================================================================

// Percentage off
class PercentageDiscount implements DiscountStrategy {
    private final double percent;

    public PercentageDiscount(double percent) {
        this.percent = percent;
    }

    @Override
    public double apply(double total) {
        return total * (1.0 - percent / 100.0);
    }

    @Override
    public String describe() {
        return String.format("%.0f%% off", percent);
    }
}

// Flat amount off
class FlatDiscount implements DiscountStrategy {
    private final double amount;

    public FlatDiscount(double amount) {
        this.amount = amount;
    }

    @Override
    public double apply(double total) {
        return Math.max(0, total - amount);
    }

    @Override
    public String describe() {
        return String.format("$%.2f off", amount);
    }
}

// Buy One Get One (50% off simplified)
class BOGODiscount implements DiscountStrategy {
    @Override
    public double apply(double total) {
        return total * 0.5;
    }

    @Override
    public String describe() {
        return "Buy One Get One (50% off)";
    }
}

// ===========================================================================
// CLASS: PizzaOrder [Order Aggregator]
// Responsibility: Manages pizzas, applies discount, generates receipt
// Relationship: Aggregation with Pizza, Association with DiscountStrategy
// ===========================================================================
class PizzaOrder {
    private final List<Pizza> pizzas = new ArrayList<>();  // Aggregation
    private DiscountStrategy discount;                      // Optional association

    // Add pizza to order
    public void addPizza(Pizza pizza) {
        pizzas.add(pizza);
    }

    // Set discount strategy (Strategy pattern — swap at runtime)
    public void setDiscount(DiscountStrategy d) {
        this.discount = d;
    }

    // Subtotal before discount
    public double getSubtotal() {
        double total = 0;
        for (Pizza p : pizzas) {
            total += p.getCost();
        }
        return total;
    }

    // Final total after discount
    public double getTotal() {
        double sub = getSubtotal();
        return (discount != null) ? discount.apply(sub) : sub;
    }

    // Print itemized receipt
    public void printReceipt() {
        System.out.println("============================================");
        System.out.println("           PIZZA ORDER RECEIPT");
        System.out.println("============================================");

        for (int i = 0; i < pizzas.size(); i++) {
            System.out.printf("  %d. %-40s $%.2f%n",
                i + 1,
                pizzas.get(i).getDescription(),
                pizzas.get(i).getCost());
        }

        System.out.println("--------------------------------------------");
        System.out.printf("  Subtotal:                                $%.2f%n", getSubtotal());

        if (discount != null) {
            System.out.printf("  Discount (%s):              -$%.2f%n",
                discount.describe(),
                getSubtotal() - getTotal());
        }

        System.out.println("============================================");
        System.out.printf("  TOTAL:                                   $%.2f%n", getTotal());
        System.out.println("============================================");
    }
}

// ===========================================================================
// MAIN — Full demonstration
// ===========================================================================
public class PizzaPricingSystem {
    public static void main(String[] args) {
        System.out.println("============================================");
        System.out.println("  Pizza Pricing System — LLD Demo (Java)");
        System.out.println("============================================");

        PizzaOrder order = new PizzaOrder();

        // Pizza 1: Large Stuffed + Cheese + Pepperoni + Mushroom
        Pizza p1 = new BasePizza(Size.LARGE, Crust.STUFFED);
        p1 = new CheeseTopping(p1);
        p1 = new PepperoniTopping(p1);
        p1 = new MushroomTopping(p1);
        order.addPizza(p1);

        // Pizza 2: Medium Thin + Olives + Jalapeno
        Pizza p2 = new BasePizza(Size.MEDIUM, Crust.THIN);
        p2 = new OlivesTopping(p2);
        p2 = new JalapenoTopping(p2);
        order.addPizza(p2);

        // Pizza 3: Small Regular (plain)
        order.addPizza(new BasePizza(Size.SMALL, Crust.REGULAR));

        // Receipt without discount
        System.out.println("\n--- Receipt WITHOUT discount ---");
        order.printReceipt();

        // Apply 15% discount
        order.setDiscount(new PercentageDiscount(15));
        System.out.println("\n--- Receipt WITH 15% discount ---");
        order.printReceipt();

        // Swap to flat $5 off (runtime strategy swap!)
        order.setDiscount(new FlatDiscount(5.00));
        System.out.println("\n--- Receipt WITH $5 flat discount ---");
        order.printReceipt();

        // Swap to BOGO
        order.setDiscount(new BOGODiscount());
        System.out.println("\n--- Receipt WITH BOGO ---");
        order.printReceipt();

        System.out.println("\n=== All demonstrations complete ===");
    }
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main() -> PizzaOrder -> addPizza(Decorator chain) -> printReceipt()
//     -> pizza.getCost() -> MushroomTopping.getCost()
//        -> PepperoniTopping.getCost() -> CheeseTopping.getCost()
//           -> BasePizza.getCost() = size.getPrice() + crust.getSurcharge()
//     -> discount.apply(subtotal) [Strategy: polymorphic dispatch]

// METHOD CALL TREE:
//   order.printReceipt()
//     -> pizzas.forEach -> pizza.getCost() [decorator chain unwinds]
//        -> ToppingN.getCost() = wrapped.getCost() + toppingPrice
//           -> ... -> BasePizza.getCost()
//     -> getSubtotal() = sum of all costs
//     -> discount.apply(subtotal) [Percentage/Flat/BOGO]

// CLASS RESPONSIBILITY TABLE:
//   Pizza (interface)      | Contract: getDescription(), getCost()
//   BasePizza              | Base pizza with size + crust pricing
//   ToppingDecorator       | Abstract decorator wrapping a Pizza
//   CheeseTopping          | +$1.50 decorator
//   PepperoniTopping       | +$2.00 decorator
//   MushroomTopping        | +$1.00 decorator
//   OlivesTopping          | +$0.75 decorator
//   JalapenoTopping        | +$0.50 decorator
//   DiscountStrategy       | Contract: apply(total), describe()
//   PercentageDiscount     | X% off
//   FlatDiscount           | $X off
//   BOGODiscount           | 50% off
//   PizzaOrder             | Aggregates pizzas, discount, receipt

// DESIGN PATTERNS:
//   1. Decorator -> Toppings wrap pizza, each adding cost (avoids subclass explosion)
//   2. Strategy  -> DiscountStrategy swappable at runtime (OCP)

// BEST PRACTICES:
//   1. Encapsulation      -> private final fields, behavior via methods
//   2. Polymorphism       -> getCost() chain dispatched through decorators
//   3. OCP                -> New toppings/discounts = new class only
//   4. SRP                -> Each topping handles its own pricing
//   5. Composition        -> Decorator CONTAINS pizza, not extends it
//   6. Java Enum          -> Size/Crust with pricing as enum constants
//   7. Immutable fields   -> final where possible
