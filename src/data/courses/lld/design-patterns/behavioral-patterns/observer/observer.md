# Observer Pattern

> **Intent:** Define a one-to-many dependency between objects so that when one object (subject) changes state, all its dependents (observers) are notified and updated automatically.

<br>

---

## When to Use

- **Event-driven systems** — notify when something happens
- **Publish-subscribe** — multiple listeners for one event
- **Decoupled communication** — subject doesn't know concrete observers
- **UI updates** — model changes, views update automatically

<br>

---

## Structure

```
Subject (Observable)          Observer
├─ subscribe(observer)        ├─ update(event)
├─ unsubscribe(observer)      
├─ notify()                   ConcreteObserverA
│   └─ for each observer:     ConcreteObserverB
│       observer.update()     ConcreteObserverC
```

<br>

---

## Example: Stock Price Alert System

```java
interface StockObserver {
    void update(String symbol, double price);
}

class StockExchange {
    private Map<String, Double> prices = new HashMap<>();
    private Map<String, List<StockObserver>> observers = new HashMap<>();
    
    public void subscribe(String symbol, StockObserver observer) {
        observers.computeIfAbsent(symbol, k -> new ArrayList<>()).add(observer);
    }
    
    public void unsubscribe(String symbol, StockObserver observer) {
        List<StockObserver> list = observers.get(symbol);
        if (list != null) list.remove(observer);
    }
    
    public void updatePrice(String symbol, double price) {
        prices.put(symbol, price);
        notifyObservers(symbol, price);
    }
    
    private void notifyObservers(String symbol, double price) {
        List<StockObserver> list = observers.getOrDefault(symbol, List.of());
        for (StockObserver obs : list) obs.update(symbol, price);
    }
}

class PriceAlert implements StockObserver {
    private String name;
    private double threshold;
    
    public PriceAlert(String name, double threshold) {
        this.name = name; this.threshold = threshold;
    }
    
    public void update(String symbol, double price) {
        if (price > threshold)
            System.out.println("🚨 " + name + ": " + symbol + " crossed $" + threshold + "! Now $" + price);
    }
}

class PortfolioTracker implements StockObserver {
    public void update(String symbol, double price) {
        System.out.println("📊 Portfolio updated: " + symbol + " = $" + price);
    }
}
```

<br>

---

## Push vs Pull Model

| Push | Pull |
|------|------|
| Subject sends data: `update(data)` | Subject sends signal: `update()` |
| Observer receives everything | Observer queries subject for what it needs |
| Simple but may send unnecessary data | More flexible but more coupling |

<br>

---

## Common Interview Questions

1. **"What is Observer?"** → One-to-many notification when subject state changes
2. **"Observer vs Pub-Sub?"** → Observer is direct; Pub-Sub uses a message broker in between
3. **"How to avoid memory leaks?"** → Unsubscribe when observer is destroyed (weak references)
4. **"Real examples?"** → `java.util.Observer` (deprecated), event listeners, RxJava, message queues

<br>

---

## Key Takeaways

1. **Decouples subject from observers** — subject doesn't know concrete types
2. **One-to-many notification** — any number of observers can subscribe
3. **Used everywhere**: event systems, UI frameworks, message queues, reactive streams
4. **Watch for memory leaks** — always unsubscribe when done
