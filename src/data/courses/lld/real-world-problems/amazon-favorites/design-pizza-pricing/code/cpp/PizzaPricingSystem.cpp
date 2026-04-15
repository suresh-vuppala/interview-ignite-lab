// ===========================================================================
// DESIGN: Pizza Pricing System — Low Level Design
// ===========================================================================
// Fully functional single-file C++ implementation
// Patterns: Decorator Pattern, Strategy Pattern, Builder Pattern
// Principles: SOLID, Composition over Inheritance, OCP
// ===========================================================================

// ---------------------------------------------------------------------------
// 1. FUNCTIONAL REQUIREMENTS
// ---------------------------------------------------------------------------
// FR1: Create base pizza with size (Small/Medium/Large) and crust (Thin/Regular/Stuffed)
// FR2: Add multiple toppings dynamically, each adding its own cost
// FR3: Calculate total price = base price + sum of all topping prices
// FR4: Support discount strategies (Percentage off, Flat discount, BOGO)
// FR5: Manage orders with multiple pizzas and total calculation
// FR6: Generate itemized receipt with breakdown

// ---------------------------------------------------------------------------
// 2. CONSTRAINTS & ASSUMPTIONS
// ---------------------------------------------------------------------------
// - Sizes: Small($6), Medium($8), Large($10)
// - Crusts: Thin(free), Regular(free), Stuffed(+$2)
// - Toppings: $0.50 to $3.00 each, max 10 per pizza
// - Only one discount per order
// - Minimum order: 1 pizza, Maximum: 50 pizzas

// ---------------------------------------------------------------------------
// 3. CORE ENTITIES & RELATIONSHIPS
// ---------------------------------------------------------------------------
// +-------------------+------------------+--------------+-------------+----------------------------+
// | Source             | Destination      | Type         | Cardinality | Description                |
// +-------------------+------------------+--------------+-------------+----------------------------+
// | ToppingDecorator   | Pizza            | Composition  | 1 -> 1      | Decorator wraps pizza      |
// | BasePizza          | Pizza            | Inheritance  | IS-A        | Base implements Pizza      |
// | ToppingDecorator   | Pizza            | Inheritance  | IS-A        | Decorator IS-A Pizza       |
// | CheeseTopping      | ToppingDecorator | Inheritance  | IS-A        | Concrete decorator         |
// | PepperoniTopping   | ToppingDecorator | Inheritance  | IS-A        | Concrete decorator         |
// | PizzaOrder         | Pizza            | Aggregation  | 1 -> many   | Order has pizzas           |
// | PizzaOrder         | DiscountStrategy | Association  | 1 -> 0..1   | Order may have discount    |
// | PercentageDiscount | DiscountStrategy | Inheritance  | IS-A        | Concrete strategy          |
// | FlatDiscount       | DiscountStrategy | Inheritance  | IS-A        | Concrete strategy          |
// +-------------------+------------------+--------------+-------------+----------------------------+

// ---------------------------------------------------------------------------
// 4. PLANTUML
// ---------------------------------------------------------------------------
// @startuml PizzaPricing
// interface Pizza { +getDescription():string \n +getCost():double }
// class BasePizza { -size:Size \n -crust:Crust }
// abstract class ToppingDecorator { #wrapped:Pizza* }
// class CheeseTopping
// class PepperoniTopping
// class MushroomTopping
// class OlivesTopping
// interface DiscountStrategy { +apply(total):double \n +describe():string }
// class PercentageDiscount { -percent:double }
// class FlatDiscount { -amount:double }
// class PizzaOrder { -pizzas:vector<Pizza*> \n -discount:DiscountStrategy* }
//
// Pizza <|.. BasePizza
// Pizza <|.. ToppingDecorator
// ToppingDecorator *-- Pizza : wraps
// ToppingDecorator <|-- CheeseTopping
// ToppingDecorator <|-- PepperoniTopping
// ToppingDecorator <|-- MushroomTopping
// ToppingDecorator <|-- OlivesTopping
// DiscountStrategy <|.. PercentageDiscount
// DiscountStrategy <|.. FlatDiscount
// PizzaOrder o-- "0..*" Pizza
// PizzaOrder --> "0..1" DiscountStrategy
// @enduml

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

// ===========================================================================
// ENUMERATIONS
// ===========================================================================

// Pizza size options with corresponding base prices
enum Size {
    SMALL,    // $6.00
    MEDIUM,   // $8.00
    LARGE     // $10.00
};

// Crust type options
enum Crust {
    THIN,      // Free
    REGULAR,   // Free
    STUFFED    // +$2.00
};

// Helper: convert enum to string for display
string sizeToString(Size s) {
    switch (s) {
        case SMALL: return "Small";
        case MEDIUM: return "Medium";
        case LARGE: return "Large";
    }
    return "Unknown";
}

string crustToString(Crust c) {
    switch (c) {
        case THIN: return "Thin";
        case REGULAR: return "Regular";
        case STUFFED: return "Stuffed";
    }
    return "Unknown";
}

// ===========================================================================
// INTERFACE: Pizza [Decorator Pattern: Component Interface]
// Responsibility: Defines contract for all pizza objects (base + decorated)
// ===========================================================================
class Pizza {
public:
    virtual ~Pizza() {}

    // Get full description (base + all toppings)
    virtual string getDescription() const = 0;

    // Get total cost (base price + all topping prices)
    virtual double getCost() const = 0;
};

// ===========================================================================
// CLASS: BasePizza [Decorator Pattern: Concrete Component]
// Responsibility: The base pizza with size and crust pricing
// Relationship: BasePizza IS-A Pizza (Inheritance)
// ===========================================================================
class BasePizza : public Pizza {
private:
    Size size;     // Determines base price
    Crust crust;   // May add extra cost

    // Calculate base price from size
    double sizePrice() const {
        switch (size) {
            case SMALL:  return 6.00;
            case MEDIUM: return 8.00;
            case LARGE:  return 10.00;
        }
        return 0.0;
    }

    // Calculate crust surcharge
    double crustPrice() const {
        return (crust == STUFFED) ? 2.00 : 0.00;
    }

public:
    BasePizza(Size size, Crust crust)
        : size(size), crust(crust) {}

    string getDescription() const {
        return sizeToString(size) + " " + crustToString(crust) + " Pizza";
    }

    double getCost() const {
        return sizePrice() + crustPrice();
    }
};

// ===========================================================================
// CLASS: ToppingDecorator [Decorator Pattern: Base Decorator]
// Responsibility: Wraps a Pizza, adds topping cost and description
// Relationship: ToppingDecorator IS-A Pizza AND HAS-A Pizza (Composition)
// Key Insight: Each decorator wraps the previous, forming a chain
// ===========================================================================
class ToppingDecorator : public Pizza {
protected:
    Pizza* wrapped;   // The pizza being decorated (Composition)

public:
    // Takes ownership of the wrapped pizza
    ToppingDecorator(Pizza* pizza)
        : wrapped(pizza) {}

    // Clean up the wrapped pizza chain
    virtual ~ToppingDecorator() {
        delete wrapped;
    }
};

// ===========================================================================
// Concrete Topping Decorators — each adds cost and description
// ===========================================================================

// Cheese: +$1.50
class CheeseTopping : public ToppingDecorator {
public:
    CheeseTopping(Pizza* p) : ToppingDecorator(p) {}

    string getDescription() const {
        return wrapped->getDescription() + " + Cheese";
    }

    double getCost() const {
        return wrapped->getCost() + 1.50;
    }
};

// Pepperoni: +$2.00
class PepperoniTopping : public ToppingDecorator {
public:
    PepperoniTopping(Pizza* p) : ToppingDecorator(p) {}

    string getDescription() const {
        return wrapped->getDescription() + " + Pepperoni";
    }

    double getCost() const {
        return wrapped->getCost() + 2.00;
    }
};

// Mushroom: +$1.00
class MushroomTopping : public ToppingDecorator {
public:
    MushroomTopping(Pizza* p) : ToppingDecorator(p) {}

    string getDescription() const {
        return wrapped->getDescription() + " + Mushroom";
    }

    double getCost() const {
        return wrapped->getCost() + 1.00;
    }
};

// Olives: +$0.75
class OlivesTopping : public ToppingDecorator {
public:
    OlivesTopping(Pizza* p) : ToppingDecorator(p) {}

    string getDescription() const {
        return wrapped->getDescription() + " + Olives";
    }

    double getCost() const {
        return wrapped->getCost() + 0.75;
    }
};

// Jalapeno: +$0.50
class JalapenoTopping : public ToppingDecorator {
public:
    JalapenoTopping(Pizza* p) : ToppingDecorator(p) {}

    string getDescription() const {
        return wrapped->getDescription() + " + Jalapeno";
    }

    double getCost() const {
        return wrapped->getCost() + 0.50;
    }
};

// ===========================================================================
// INTERFACE: DiscountStrategy [Strategy Pattern]
// Responsibility: Defines contract for discount calculation
// SOLID: OCP — new discounts without modifying existing code
// ===========================================================================
class DiscountStrategy {
public:
    virtual ~DiscountStrategy() {}

    // Apply discount to total amount
    virtual double apply(double total) const = 0;

    // Description for receipt
    virtual string describe() const = 0;
};

// ===========================================================================
// CLASS: PercentageDiscount [Strategy: Concrete — percentage off]
// ===========================================================================
class PercentageDiscount : public DiscountStrategy {
private:
    double percent;   // e.g., 10 for 10%

public:
    PercentageDiscount(double percent)
        : percent(percent) {}

    double apply(double total) const {
        return total * (1.0 - percent / 100.0);
    }

    string describe() const {
        char buf[32];
        sprintf(buf, "%.0f%% off", percent);
        return string(buf);
    }
};

// ===========================================================================
// CLASS: FlatDiscount [Strategy: Concrete — flat amount off]
// ===========================================================================
class FlatDiscount : public DiscountStrategy {
private:
    double amount;

public:
    FlatDiscount(double amount)
        : amount(amount) {}

    double apply(double total) const {
        double result = total - amount;
        return (result > 0) ? result : 0;
    }

    string describe() const {
        char buf[32];
        sprintf(buf, "$%.2f off", amount);
        return string(buf);
    }
};

// ===========================================================================
// CLASS: BOGODiscount [Strategy: Buy One Get One — cheapest free]
// ===========================================================================
class BOGODiscount : public DiscountStrategy {
public:
    // BOGO: 50% off (simplified — half price)
    double apply(double total) const {
        return total * 0.5;
    }

    string describe() const {
        return "Buy One Get One (50% off)";
    }
};

// ===========================================================================
// CLASS: PizzaOrder [Order Aggregator]
// Responsibility: Manages multiple pizzas, applies discount, generates receipt
// Relationship: Aggregation with Pizza (order HAS pizzas, pizzas can exist independently)
// Relationship: Association with DiscountStrategy (optional)
// ===========================================================================
class PizzaOrder {
private:
    vector<Pizza*> pizzas;           // Aggregation: order has pizzas
    DiscountStrategy* discount;      // Optional discount strategy

public:
    PizzaOrder()
        : discount(NULL) {}

    // Clean up pizzas and discount
    ~PizzaOrder() {
        for (size_t i = 0; i < pizzas.size(); i++) {
            delete pizzas[i];
        }
        if (discount != NULL) {
            delete discount;
        }
    }

    // Add a pizza to the order
    void addPizza(Pizza* pizza) {
        pizzas.push_back(pizza);
    }

    // Set discount strategy (takes ownership)
    void setDiscount(DiscountStrategy* d) {
        if (discount != NULL) {
            delete discount;
        }
        discount = d;
    }

    // Calculate subtotal (before discount)
    double getSubtotal() const {
        double total = 0;
        for (size_t i = 0; i < pizzas.size(); i++) {
            total += pizzas[i]->getCost();
        }
        return total;
    }

    // Calculate final total (after discount)
    double getTotal() const {
        double sub = getSubtotal();
        if (discount != NULL) {
            return discount->apply(sub);
        }
        return sub;
    }

    // Print itemized receipt
    void printReceipt() const {
        cout << "============================================" << endl;
        cout << "           PIZZA ORDER RECEIPT" << endl;
        cout << "============================================" << endl;

        for (size_t i = 0; i < pizzas.size(); i++) {
            printf("  %zu. %-40s $%.2f\n",
                   i + 1,
                   pizzas[i]->getDescription().c_str(),
                   pizzas[i]->getCost());
        }

        cout << "--------------------------------------------" << endl;
        printf("  Subtotal:                                $%.2f\n", getSubtotal());

        if (discount != NULL) {
            printf("  Discount (%s):              -$%.2f\n",
                   discount->describe().c_str(),
                   getSubtotal() - getTotal());
        }

        cout << "============================================" << endl;
        printf("  TOTAL:                                   $%.2f\n", getTotal());
        cout << "============================================" << endl;
    }
};

// ===========================================================================
// MAIN — Full demonstration
// ===========================================================================
int main() {
    cout << "============================================" << endl;
    cout << "  Pizza Pricing System — LLD Demo" << endl;
    cout << "============================================" << endl;

    // --- Create Order ---
    PizzaOrder order;

    // Pizza 1: Large Stuffed + Cheese + Pepperoni + Mushroom
    // Decorator chain: Mushroom(Pepperoni(Cheese(BasePizza)))
    Pizza* pizza1 = new BasePizza(LARGE, STUFFED);
    pizza1 = new CheeseTopping(pizza1);      // Wrap with cheese
    pizza1 = new PepperoniTopping(pizza1);   // Wrap with pepperoni
    pizza1 = new MushroomTopping(pizza1);    // Wrap with mushroom
    order.addPizza(pizza1);

    // Pizza 2: Medium Thin + Olives + Jalapeno
    Pizza* pizza2 = new BasePizza(MEDIUM, THIN);
    pizza2 = new OlivesTopping(pizza2);
    pizza2 = new JalapenoTopping(pizza2);
    order.addPizza(pizza2);

    // Pizza 3: Small Regular (no toppings)
    Pizza* pizza3 = new BasePizza(SMALL, REGULAR);
    order.addPizza(pizza3);

    // Print receipt without discount
    cout << "\n--- Receipt WITHOUT discount ---" << endl;
    order.printReceipt();

    // Apply 15% discount
    order.setDiscount(new PercentageDiscount(15));
    cout << "\n--- Receipt WITH 15% discount ---" << endl;
    order.printReceipt();

    // Switch to flat $5 discount (Strategy swap at runtime!)
    order.setDiscount(new FlatDiscount(5.00));
    cout << "\n--- Receipt WITH $5 flat discount ---" << endl;
    order.printReceipt();

    // Switch to BOGO
    order.setDiscount(new BOGODiscount());
    cout << "\n--- Receipt WITH BOGO ---" << endl;
    order.printReceipt();

    cout << "\n=== All demonstrations complete ===" << endl;
    return 0;
}

// ===========================================================================
// 5. SUMMARY
// ===========================================================================

// EXECUTION FLOW:
//   main()
//     -> Create PizzaOrder
//     -> Create BasePizza(LARGE, STUFFED) = $12.00
//     -> Wrap: CheeseTopping(base) -> getCost() = base.getCost() + 1.50
//     -> Wrap: PepperoniTopping(cheese) -> getCost() = cheese.getCost() + 2.00
//     -> Wrap: MushroomTopping(pepperoni) -> getCost() = pepperoni.getCost() + 1.00
//     -> order.addPizza(mushroom)  // Final: $16.50
//     -> order.printReceipt() -> iterates pizzas, calls getCost() chain
//     -> order.setDiscount(PercentageDiscount(15))
//     -> order.getTotal() -> getSubtotal() * 0.85

// METHOD CALL TREE:
//   order.printReceipt()
//     -> for each pizza: pizza->getCost()
//        -> MushroomTopping.getCost()
//           -> PepperoniTopping.getCost()
//              -> CheeseTopping.getCost()
//                 -> BasePizza.getCost() = sizePrice() + crustPrice()
//              -> + 1.50 (cheese)
//           -> + 2.00 (pepperoni)
//        -> + 1.00 (mushroom)
//     -> getSubtotal() = sum of all pizza costs
//     -> discount->apply(subtotal) [polymorphic: Percentage/Flat/BOGO]

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
//   PercentageDiscount     | X% off the total
//   FlatDiscount           | $X off the total
//   BOGODiscount           | 50% off (buy one get one)
//   PizzaOrder             | Aggregates pizzas, applies discount, receipt

// DESIGN PATTERNS:
//   1. Decorator  -> Toppings wrap base pizza, each adding cost
//                    Avoids subclass explosion (no CheesePepperoniPizza class)
//   2. Strategy   -> DiscountStrategy with interchangeable implementations
//                    Swap discount at runtime without changing Order
//   3. Builder    -> (Implicit) Chained decorator construction

// BEST PRACTICES:
//   1. Encapsulation        -> Private fields, behavior via methods
//   2. Polymorphism         -> getCost() dispatched through decorator chain
//   3. OCP                  -> New toppings = new class, no existing changes
//   4. SRP                  -> Each topping handles only its own pricing
//   5. Composition > Inherit-> Decorators compose behavior, not inherit it
//   6. Memory management    -> Destructors clean up owned objects
//   7. Runtime flexibility  -> Discount strategy swappable at any time
