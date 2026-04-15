# Design a Pizza Pricing System

Design a flexible pricing system for a pizza shop that supports different sizes, crusts, toppings, and combo deals.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **Base pizza** — choose size (Small, Medium, Large) and crust (Thin, Regular, Stuffed)
2. **Toppings** — add multiple toppings, each with its own price
3. **Dynamic pricing** — total = base price + sum of topping prices
4. **Combos/Deals** — percentage off, flat discount, buy-one-get-one
5. **Order management** — add multiple pizzas to an order, calculate total
6. **Receipt generation** — itemized breakdown of all pizzas and discounts

### Extended Requirements (If Time Permits)

1. Half-and-half toppings (different toppings per half)
2. Seasonal/limited-edition toppings with time-based availability
3. Loyalty points (earn/redeem)
4. Tax calculation by region
5. Topping quantity (extra cheese = double topping price)
6. Meal combos (pizza + drink + sides)

<br>

---

## Constraints

- Pizza sizes: Small ($6), Medium ($8), Large ($10)
- Crust types: Thin (free), Regular (free), Stuffed (+$2)
- Toppings: $0.50 to $3.00 each, max 10 toppings per pizza
- Discounts: only one discount per order
- Minimum order: 1 pizza
- Maximum order: 50 pizzas

<br>

---

## Identify Primary Actors

1. **Customer** — builds pizzas, selects toppings, places order
   - Actions: choose size/crust, add toppings, apply discount, checkout

2. **Cashier/System** — processes order, calculates totals
   - Actions: apply pricing rules, generate receipt, process payment

3. **Admin/Manager** — configures pricing and promotions
   - Actions: set topping prices, create discount campaigns, manage menu

<br>

---

## Core Entities

### 1. Pizza (Interface — Decorator base)
- **Methods**: getDescription(): String, getCost(): double
- **Responsibilities**: Define the pricing contract for base pizza + toppings

### 2. BasePizza (implements Pizza)
- **Attributes**: size (SMALL/MEDIUM/LARGE), crust (THIN/REGULAR/STUFFED)
- **Responsibilities**: Calculate base price from size + crust

### 3. ToppingDecorator (abstract, implements Pizza)
- **Attributes**: wrapped: Pizza (the pizza being decorated)
- **Responsibilities**: Add topping cost and description to wrapped pizza

### 4. Concrete Toppings (CheeseTopping, PepperoniTopping, MushroomTopping, OlivesTopping)
- **Responsibilities**: Each adds its specific price and description

### 5. DiscountStrategy (Interface)
- **Method**: apply(double total): double, getDescription(): String
- **Implementations**: PercentageDiscount, FlatDiscount, BOGODiscount

### 6. PizzaOrder
- **Attributes**: pizzas: List<Pizza>, discount: DiscountStrategy
- **Responsibilities**: Calculate subtotal, apply discount, generate receipt

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| ToppingDecorator | wraps | Pizza | Composition (◆) |
| BasePizza | implements | Pizza | Implementation |
| ToppingDecorator | implements | Pizza | Implementation |
| PizzaOrder | contains | Pizza[] | Aggregation (◇) |
| PizzaOrder | uses | DiscountStrategy | Association |
| PercentageDiscount | implements | DiscountStrategy | Implementation |
| FlatDiscount | implements | DiscountStrategy | Implementation |

<br>

---

## Relationships Diagram (Textual UML)

```
  <<interface>> Pizza
  +getDescription(): String
  +getCost(): double
       △
  ┌────┴────────────┐
BasePizza    ToppingDecorator(abstract)
  -size        ◆──→ Pizza (wrapped)
  -crust           △
               ┌───┼───┬───┐
          Cheese Pepperoni Mushroom Olives


  <<interface>> DiscountStrategy
  +apply(total): double
       △
  ┌────┼────────────┐
Percentage   Flat   BOGO


  PizzaOrder
  -pizzas: List<Pizza>
  -discount: DiscountStrategy
  +getSubtotal(): double
  +getTotal(): double
  +printReceipt()
```

<br>

---

## Design Patterns Used

### 1. **Decorator Pattern**
- **Where**: Toppings wrap the base pizza, each adding cost and description
- **Why**: Avoids subclass explosion — instead of `CheesePepperoniMushroomPizza`, just stack decorators
- **Benefit**: `new Pepperoni(new Cheese(new BasePizza(LARGE, STUFFED)))` — dynamic composition at runtime

### 2. **Strategy Pattern**
- **Where**: DiscountStrategy interface with interchangeable discount implementations
- **Why**: Different promotions (10% off, $5 off, BOGO) can be swapped without changing order logic
- **Benefit**: New discount types added without modifying existing code (OCP)

### 3. **Builder Pattern** (optional)
- **Where**: PizzaBuilder for step-by-step construction
- **Why**: Pizza has many optional parameters (toppings, crust, size)
- **Benefit**: Readable construction: `new PizzaBuilder(LARGE).crust(STUFFED).cheese().pepperoni().build()`

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **Order creation**: Each order is single-threaded (one customer, one order)
- **Menu/pricing updates**: Use `ReadWriteLock` — reads (customer views) are concurrent, writes (admin updates prices) are exclusive
- **Discount codes**: `ConcurrentHashMap<String, DiscountStrategy>` for thread-safe code lookup

### Race Conditions Handled
- **Concurrent discount application**: Validate discount is still active before applying
- **Price change during order**: Snapshot prices at order creation time

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **No toppings** — just base pizza (valid)
2. **Same topping added twice** — allowed (extra cheese = 2x CheeseTopping)
3. **Discount exceeds total** — floor at $0, never negative
4. **Empty order** — reject, throw `EmptyOrderException`
5. **Expired discount code** — reject with clear error message
6. **Maximum toppings reached** — reject additional toppings, inform customer
7. **Free pizza after BOGO** — cheapest pizza is free, not most expensive
8. **Tax on discounted total** — tax calculated AFTER discount applied

### Error Handling Strategy
- **InvalidSizeException**: If unknown size is provided
- **ToppingLimitExceededException**: More than 10 toppings
- **ExpiredDiscountException**: Discount code no longer valid
- **InvalidOrderException**: Empty order or negative amounts

<br>

---

## Implementation

```code```
