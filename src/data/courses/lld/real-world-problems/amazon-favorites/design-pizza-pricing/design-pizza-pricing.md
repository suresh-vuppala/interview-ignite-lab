# Design a Pizza Pricing System

Design a flexible pricing system for a pizza shop that supports different sizes, crusts, toppings, and combo deals.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Base pizza** — choose size (Small, Medium, Large) and crust (Thin, Regular, Stuffed)
2. **Toppings** — add multiple toppings, each with its own price
3. **Dynamic pricing** — total = base price + sum of topping prices
4. **Combos/Deals** — buy-one-get-one, percentage off, flat discount
5. **Order management** — add multiple pizzas to an order, calculate total

### Extended Requirements

1. Half-and-half toppings
2. Seasonal/limited toppings
3. Loyalty points
4. Tax calculation

<br>

---

## Design Patterns Used

| Pattern | Where | Why |
|---------|-------|-----|
| **Decorator** | Toppings wrap base pizza — each adds cost | Dynamic topping stacking |
| **Builder** | PizzaBuilder for step-by-step construction | Many optional parameters |
| **Strategy** | Discount strategies (flat, percentage, BOGO) | Swappable pricing rules |

<br>

---

## Core Entities

```
<<interface>> Pizza
├─ getDescription(): String
├─ getCost(): double
│
├── BasePizza(size, crust)
├── ToppingDecorator (abstract, wraps Pizza)
│   ├── CheeseTopping
│   ├── PepperoniTopping
│   ├── MushroomTopping
│   └── OlivesTopping

<<interface>> DiscountStrategy
├─ apply(double total): double
├── PercentageDiscount
├── FlatDiscount
├── BOGODiscount

Order
├─ pizzas: List<Pizza>
├─ discount: DiscountStrategy
├─ calculateTotal(): double
```

<br>

---

## Interview Tips

- Decorator is the star pattern here — each topping wraps the pizza
- Builder for constructing complex pizza with many options
- Strategy for discount rules — easy to add new promotions
- Ask: "Can toppings have different prices by size?" (shows depth)
