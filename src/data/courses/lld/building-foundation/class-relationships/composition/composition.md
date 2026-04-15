# Composition

Composition is a **strong whole-part relationship** where the part **cannot exist independently** of the whole. If the whole is destroyed, all its parts are destroyed too.

<br>

---

## The Key Rule

> **If the container is destroyed, all contained parts are destroyed too.**

<br>

---

## Example

```java
class House {
    private List<Room> rooms;  // Rooms cannot exist without a House
    
    public House(int numRooms) {
        rooms = new ArrayList<>();
        for (int i = 0; i < numRooms; i++) {
            rooms.add(new Room(i + 1));  // Created INSIDE — owned by House
        }
    }
    // When House is garbage collected, all Rooms go with it
}

class Room {
    private int roomNumber;
    // Room has no meaning outside a House
    
    public Room(int number) { this.roomNumber = number; }
}
```

<br>

---

## Composition vs Aggregation — Side by Side

```java
// COMPOSITION — Engine is created by and dies with Car
class Car {
    private Engine engine;
    
    public Car() {
        this.engine = new Engine();  // Created internally — strong ownership
    }
}

// AGGREGATION — Driver exists independently of Car
class Car {
    private Driver driver;
    
    public Car(Driver driver) {
        this.driver = driver;  // Passed in — independent lifecycle
    }
}
```

<br>

---

## UML Notation

**Filled diamond (◆) on the whole side**

```
House ◆──── Room
(whole)     (part — dies with whole)
```

<br>

---

## Real-World LLD Example: Order System

```java
class Order {
    private String orderId;
    private List<OrderItem> items;      // COMPOSITION — items die with order
    private ShippingAddress address;     // COMPOSITION — address is specific to this order
    private Customer customer;           // AGGREGATION — customer exists independently
    
    public Order(String orderId, Customer customer) {
        this.orderId = orderId;
        this.customer = customer;        // Passed in (aggregation)
        this.items = new ArrayList<>();  // Created inside (composition)
        this.address = new ShippingAddress(); // Created inside (composition)
    }
    
    public void addItem(String product, int qty, double price) {
        items.add(new OrderItem(product, qty, price));  // Order owns its items
    }
}

class OrderItem {
    private String productName;
    private int quantity;
    private double unitPrice;
    // OrderItem has no meaning outside an Order
}
```

<br>

---

## Common Interview Questions

1. **"Composition vs Aggregation?"** → Composition = part dies with whole (◆); Aggregation = part survives (◇)
2. **"Give a real example of each"** → Car-Engine (composition), Team-Player (aggregation)
3. **"Composition vs Inheritance?"** → Composition = HAS-A (flexible), Inheritance = IS-A (rigid). **Prefer composition.**
4. **"How to decide?"** → Ask: "Does the part make sense without the whole?" Yes = aggregation, No = composition

<br>

---

## Key Takeaways

1. **Part cannot exist without whole** — strongest relationship
2. **Objects created inside** the whole (not passed in)
3. **Filled diamond in UML** (◆)
4. **"Favor composition over inheritance"** — GoF design principle
5. **Composition gives more flexibility** than inheritance
