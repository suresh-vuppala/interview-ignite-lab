# Adapter Pattern

> **Intent:** Convert the interface of a class into another interface that clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

<br>

---

## When to Use

- **Legacy system integration** — old API doesn't match new interface
- **Third-party library** — their interface differs from yours
- **Two systems** with incompatible interfaces need to communicate

<br>

---

## Real-World Analogy

A **power adapter** converts a US plug to a European socket — same electricity, different interface.

<br>

---

## Example: Payment Gateway Integration

```java
// YOUR interface (what your system expects)
interface PaymentGateway {
    boolean charge(String customerId, double amount, String currency);
    boolean refund(String transactionId);
}

// THIRD-PARTY library (incompatible interface)
class StripeAPI {
    public StripeResponse createCharge(StripeChargeRequest request) { ... }
    public StripeResponse createRefund(StripeRefundRequest request) { ... }
}

// ADAPTER — makes Stripe work with YOUR interface
class StripeAdapter implements PaymentGateway {
    private StripeAPI stripe;
    
    public StripeAdapter(StripeAPI stripe) { this.stripe = stripe; }
    
    @Override
    public boolean charge(String customerId, double amount, String currency) {
        StripeChargeRequest req = new StripeChargeRequest();
        req.setCustomer(customerId);
        req.setAmount((int)(amount * 100)); // Stripe uses cents!
        req.setCurrency(currency);
        StripeResponse res = stripe.createCharge(req);
        return res.isSuccess();
    }
    
    @Override
    public boolean refund(String transactionId) {
        StripeRefundRequest req = new StripeRefundRequest();
        req.setChargeId(transactionId);
        StripeResponse res = stripe.createRefund(req);
        return res.isSuccess();
    }
}

// Client code — doesn't know about Stripe
class OrderService {
    private PaymentGateway gateway; // Works with ANY gateway
    
    public OrderService(PaymentGateway gateway) { this.gateway = gateway; }
    
    public void checkout(Order order) {
        gateway.charge(order.getCustomerId(), order.getTotal(), "USD");
    }
}

// Wire up: OrderService → StripeAdapter → StripeAPI
OrderService svc = new OrderService(new StripeAdapter(new StripeAPI()));
```

<br>

---

## Key Takeaways

1. **Wraps incompatible interface** to match what client expects
2. **Doesn't change the adaptee** — wraps it
3. **Common in legacy/third-party integration**
4. **Object Adapter** (composition) preferred over **Class Adapter** (inheritance)
