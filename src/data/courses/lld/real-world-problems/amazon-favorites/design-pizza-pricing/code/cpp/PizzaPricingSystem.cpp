#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>
#include <numeric>
using namespace std;

// ========== PIZZA (Decorator Pattern) ==========
class Pizza {
public:
    virtual ~Pizza() = default;
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
};

enum class Size { SMALL, MEDIUM, LARGE };
enum class Crust { THIN, REGULAR, STUFFED };

class BasePizza : public Pizza {
    Size size; Crust crust;
    double sizePrice() const { return size == Size::SMALL ? 6.0 : size == Size::MEDIUM ? 8.0 : 10.0; }
    double crustPrice() const { return crust == Crust::STUFFED ? 2.0 : 0.0; }
    string sizeName() const { return size == Size::SMALL ? "Small" : size == Size::MEDIUM ? "Medium" : "Large"; }
    string crustName() const { return crust == Crust::THIN ? "Thin" : crust == Crust::REGULAR ? "Regular" : "Stuffed"; }
public:
    BasePizza(Size s, Crust c) : size(s), crust(c) {}
    string getDescription() const override { return sizeName() + " " + crustName() + " Pizza"; }
    double getCost() const override { return sizePrice() + crustPrice(); }
};

class ToppingDecorator : public Pizza {
protected:
    unique_ptr<Pizza> pizza;
public:
    ToppingDecorator(unique_ptr<Pizza> p) : pizza(move(p)) {}
};

class CheeseTopping : public ToppingDecorator {
public:
    CheeseTopping(unique_ptr<Pizza> p) : ToppingDecorator(move(p)) {}
    string getDescription() const override { return pizza->getDescription() + " + Cheese"; }
    double getCost() const override { return pizza->getCost() + 1.50; }
};

class PepperoniTopping : public ToppingDecorator {
public:
    PepperoniTopping(unique_ptr<Pizza> p) : ToppingDecorator(move(p)) {}
    string getDescription() const override { return pizza->getDescription() + " + Pepperoni"; }
    double getCost() const override { return pizza->getCost() + 2.00; }
};

class MushroomTopping : public ToppingDecorator {
public:
    MushroomTopping(unique_ptr<Pizza> p) : ToppingDecorator(move(p)) {}
    string getDescription() const override { return pizza->getDescription() + " + Mushroom"; }
    double getCost() const override { return pizza->getCost() + 1.00; }
};

// ========== DISCOUNT (Strategy Pattern) ==========
class DiscountStrategy {
public:
    virtual ~DiscountStrategy() = default;
    virtual double apply(double total) const = 0;
    virtual string getDescription() const = 0;
};

class PercentageDiscount : public DiscountStrategy {
    double percent;
public:
    PercentageDiscount(double p) : percent(p) {}
    double apply(double total) const override { return total * (1 - percent / 100); }
    string getDescription() const override { return to_string((int)percent) + "% off"; }
};

class FlatDiscount : public DiscountStrategy {
    double amount;
public:
    FlatDiscount(double a) : amount(a) {}
    double apply(double total) const override { return max(0.0, total - amount); }
    string getDescription() const override { return "$" + to_string((int)amount) + " off"; }
};

// ========== ORDER ==========
class PizzaOrder {
    vector<unique_ptr<Pizza>> pizzas;
    unique_ptr<DiscountStrategy> discount;
public:
    void addPizza(unique_ptr<Pizza> p) { pizzas.push_back(move(p)); }
    void setDiscount(unique_ptr<DiscountStrategy> d) { discount = move(d); }
    double getSubtotal() const {
        double sum = 0;
        for (auto& p : pizzas) sum += p->getCost();
        return sum;
    }
    double getTotal() const {
        double sub = getSubtotal();
        return discount ? discount->apply(sub) : sub;
    }
    void printReceipt() const {
        cout << "=== Pizza Order ===" << endl;
        for (auto& p : pizzas)
            cout << "  " << p->getDescription() << " - $" << fixed << setprecision(2) << p->getCost() << endl;
        cout << "Subtotal: $" << getSubtotal() << endl;
        if (discount) cout << "Discount: " << discount->getDescription() << endl;
        cout << "TOTAL: $" << getTotal() << endl;
    }
};
