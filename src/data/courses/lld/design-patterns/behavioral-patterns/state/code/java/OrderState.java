// State — Order Lifecycle
interface OrderState {
    void pay(Order order);
    void ship(Order order);
    void deliver(Order order);
    void cancel(Order order);
    String getStatus();
}

class Order {
    private OrderState state;
    private String orderId;
    
    public Order(String orderId) {
        this.orderId = orderId;
        this.state = new CreatedState();
    }
    
    public void setState(OrderState state) { this.state = state; }
    public void pay() { state.pay(this); }
    public void ship() { state.ship(this); }
    public void deliver() { state.deliver(this); }
    public void cancel() { state.cancel(this); }
    public String getStatus() { return state.getStatus(); }
}

class CreatedState implements OrderState {
    public void pay(Order o) { System.out.println("Payment received"); o.setState(new PaidState()); }
    public void ship(Order o) { System.out.println("❌ Cannot ship unpaid order"); }
    public void deliver(Order o) { System.out.println("❌ Cannot deliver unpaid order"); }
    public void cancel(Order o) { System.out.println("Order cancelled"); o.setState(new CancelledState()); }
    public String getStatus() { return "CREATED"; }
}

class PaidState implements OrderState {
    public void pay(Order o) { System.out.println("❌ Already paid"); }
    public void ship(Order o) { System.out.println("Order shipped"); o.setState(new ShippedState()); }
    public void deliver(Order o) { System.out.println("❌ Must ship first"); }
    public void cancel(Order o) { System.out.println("Refund issued, order cancelled"); o.setState(new CancelledState()); }
    public String getStatus() { return "PAID"; }
}

class ShippedState implements OrderState {
    public void pay(Order o) { System.out.println("❌ Already paid"); }
    public void ship(Order o) { System.out.println("❌ Already shipped"); }
    public void deliver(Order o) { System.out.println("Order delivered!"); o.setState(new DeliveredState()); }
    public void cancel(Order o) { System.out.println("❌ Cannot cancel shipped order"); }
    public String getStatus() { return "SHIPPED"; }
}

class DeliveredState implements OrderState {
    public void pay(Order o) { System.out.println("❌ Already complete"); }
    public void ship(Order o) { System.out.println("❌ Already complete"); }
    public void deliver(Order o) { System.out.println("❌ Already delivered"); }
    public void cancel(Order o) { System.out.println("❌ Cannot cancel delivered order"); }
    public String getStatus() { return "DELIVERED"; }
}

class CancelledState implements OrderState {
    public void pay(Order o) { System.out.println("❌ Order is cancelled"); }
    public void ship(Order o) { System.out.println("❌ Order is cancelled"); }
    public void deliver(Order o) { System.out.println("❌ Order is cancelled"); }
    public void cancel(Order o) { System.out.println("❌ Already cancelled"); }
    public String getStatus() { return "CANCELLED"; }
}
