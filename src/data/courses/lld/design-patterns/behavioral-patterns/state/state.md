# State Pattern

> **Intent:** Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.

<br>

---

## When to Use

- Object has **distinct states with different behaviors** (Order: Created → Paid → Shipped → Delivered)
- **Replace complex if-else/switch** on state with polymorphism
- **State transitions have rules** — not all transitions are valid

<br>

---

## Example: Vending Machine

```java
interface VendingMachineState {
    void insertCoin(VendingMachine machine);
    void selectProduct(VendingMachine machine, String product);
    void dispense(VendingMachine machine);
}

class IdleState implements VendingMachineState {
    public void insertCoin(VendingMachine m) {
        System.out.println("Coin accepted");
        m.setState(new HasCoinState());
    }
    public void selectProduct(VendingMachine m, String p) {
        System.out.println("Insert coin first!");
    }
    public void dispense(VendingMachine m) {
        System.out.println("Insert coin and select product first!");
    }
}

class HasCoinState implements VendingMachineState {
    public void insertCoin(VendingMachine m) {
        System.out.println("Coin already inserted");
    }
    public void selectProduct(VendingMachine m, String product) {
        if (m.hasProduct(product)) {
            System.out.println("Product selected: " + product);
            m.setState(new DispensingState(product));
        } else {
            System.out.println("Out of stock! Refunding...");
            m.setState(new IdleState());
        }
    }
    public void dispense(VendingMachine m) {
        System.out.println("Select a product first!");
    }
}

class DispensingState implements VendingMachineState {
    private String product;
    public DispensingState(String product) { this.product = product; }
    public void insertCoin(VendingMachine m) { System.out.println("Please wait..."); }
    public void selectProduct(VendingMachine m, String p) { System.out.println("Please wait..."); }
    public void dispense(VendingMachine m) {
        System.out.println("Dispensing " + product + "...");
        m.removeProduct(product);
        m.setState(new IdleState()); // Back to idle
    }
}

class VendingMachine {
    private VendingMachineState state;
    private Map<String, Integer> inventory;
    
    public VendingMachine() { this.state = new IdleState(); }
    
    public void setState(VendingMachineState s) { this.state = s; }
    public void insertCoin() { state.insertCoin(this); }
    public void selectProduct(String p) { state.selectProduct(this, p); }
    public void dispense() { state.dispense(this); }
    public boolean hasProduct(String p) { return inventory.getOrDefault(p, 0) > 0; }
    public void removeProduct(String p) { inventory.merge(p, -1, Integer::sum); }
}
```

<br>

---

## State vs Strategy

| State | Strategy |
|-------|----------|
| Object transitions between states **internally** | Client **chooses** the strategy |
| States know about **valid transitions** | Strategies are **independent** alternatives |
| Behavior changes as state changes | Behavior changes when strategy is swapped |
| `order.ship()` → state changes | `cart.setPayment(new UPI())` → client decides |

<br>

---

## Key Takeaways

1. **Each state = a class** with its own behavior
2. **Eliminates state-checking if-else** chains
3. **State transitions are explicit** — each state knows valid next states
4. **Maps directly from State Diagrams** (UML) to code
5. **Used in:** Order lifecycle, ATM, traffic light, game character states
