# Facade Pattern

> **Intent:** Provide a simplified, unified interface to a complex subsystem of classes.

<br>

---

## When to Use

- **Complex subsystem** with many classes — simplify access for clients
- **Layer between client and subsystem** — reduce dependencies
- **Third-party library** — wrap complex API with simple methods

<br>

---

## Example: Home Theater System

```java
// Complex subsystem — many classes with their own APIs
class DVDPlayer { void on() {} void play(String movie) {} void off() {} }
class Projector { void on() {} void setInput(String src) {} void off() {} }
class SurroundSound { void on() {} void setVolume(int v) {} void off() {} }
class Lights { void dim(int level) {} void on() {} }
class Screen { void down() {} void up() {} }

// FACADE — one simple interface for the whole subsystem
class HomeTheaterFacade {
    private DVDPlayer dvd;
    private Projector projector;
    private SurroundSound sound;
    private Lights lights;
    private Screen screen;
    
    public HomeTheaterFacade(DVDPlayer d, Projector p, SurroundSound s, Lights l, Screen sc) {
        this.dvd = d; this.projector = p; this.sound = s; this.lights = l; this.screen = sc;
    }
    
    // ONE method instead of 8 calls!
    public void watchMovie(String movie) {
        lights.dim(10);
        screen.down();
        projector.on();
        projector.setInput("DVD");
        sound.on();
        sound.setVolume(50);
        dvd.on();
        dvd.play(movie);
    }
    
    public void endMovie() {
        dvd.off(); sound.off(); projector.off(); screen.up(); lights.on();
    }
}

// Client — simple!
HomeTheaterFacade theater = new HomeTheaterFacade(...);
theater.watchMovie("Inception"); // One call does everything
```

<br>

---

## Real-World LLD: Order Processing Facade

```java
class OrderFacade {
    private InventoryService inventory;
    private PaymentService payment;
    private ShippingService shipping;
    private NotificationService notification;
    
    public OrderResult placeOrder(OrderRequest request) {
        // 1. Check inventory
        if (!inventory.checkAvailability(request.getItems())) 
            return OrderResult.outOfStock();
        // 2. Process payment
        PaymentResult payResult = payment.charge(request.getPaymentInfo());
        if (!payResult.isSuccess()) return OrderResult.paymentFailed();
        // 3. Create shipment
        String trackingId = shipping.createShipment(request.getAddress(), request.getItems());
        // 4. Send confirmation
        notification.sendOrderConfirmation(request.getEmail(), trackingId);
        
        return OrderResult.success(trackingId);
    }
}
```

<br>

---

## Key Takeaways

1. **Simplifies complex subsystem** — one method instead of many
2. **Doesn't hide subsystem** — clients can still access directly if needed
3. **Reduces coupling** — client depends on facade, not 10 subsystem classes
4. **Common in API design** — SDKs wrap complex REST APIs
