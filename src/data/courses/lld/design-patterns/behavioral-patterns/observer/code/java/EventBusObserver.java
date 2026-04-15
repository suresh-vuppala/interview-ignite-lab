// Observer — Event System for E-commerce
interface EventListener {
    void handle(String eventType, Map<String, Object> data);
}

class EventBus {
    private final Map<String, List<EventListener>> listeners = new HashMap<>();
    
    public void subscribe(String eventType, EventListener listener) {
        listeners.computeIfAbsent(eventType, k -> new ArrayList<>()).add(listener);
    }
    
    public void unsubscribe(String eventType, EventListener listener) {
        List<EventListener> list = listeners.get(eventType);
        if (list != null) list.remove(listener);
    }
    
    public void publish(String eventType, Map<String, Object> data) {
        for (EventListener l : listeners.getOrDefault(eventType, List.of())) {
            l.handle(eventType, data);
        }
    }
}

class EmailNotifier implements EventListener {
    public void handle(String eventType, Map<String, Object> data) {
        System.out.println("📧 Email: " + eventType + " → " + data.get("email"));
    }
}

class InventoryUpdater implements EventListener {
    public void handle(String eventType, Map<String, Object> data) {
        if ("ORDER_PLACED".equals(eventType)) {
            System.out.println("📦 Inventory reduced for order " + data.get("orderId"));
        }
    }
}

class AnalyticsTracker implements EventListener {
    public void handle(String eventType, Map<String, Object> data) {
        System.out.println("📊 Analytics: " + eventType + " tracked");
    }
}

// Setup
// EventBus bus = new EventBus();
// bus.subscribe("ORDER_PLACED", new EmailNotifier());
// bus.subscribe("ORDER_PLACED", new InventoryUpdater());
// bus.subscribe("ORDER_PLACED", new AnalyticsTracker());
// bus.publish("ORDER_PLACED", Map.of("orderId", "123", "email", "user@example.com"));
