// Factory Method — Payment Processor Factory
interface PaymentProcessor {
    void processPayment(double amount);
    boolean supportsRefund();
}

class CreditCardProcessor implements PaymentProcessor {
    public void processPayment(double amount) { System.out.println("CC charge: $" + amount); }
    public boolean supportsRefund() { return true; }
}

class UPIProcessor implements PaymentProcessor {
    public void processPayment(double amount) { System.out.println("UPI transfer: ₹" + amount); }
    public boolean supportsRefund() { return false; }
}

class PayPalProcessor implements PaymentProcessor {
    public void processPayment(double amount) { System.out.println("PayPal: $" + amount); }
    public boolean supportsRefund() { return true; }
}

class PaymentProcessorFactory {
    public static PaymentProcessor create(String method) {
        return switch (method.toLowerCase()) {
            case "credit_card" -> new CreditCardProcessor();
            case "upi"         -> new UPIProcessor();
            case "paypal"      -> new PayPalProcessor();
            default -> throw new IllegalArgumentException("Unsupported payment: " + method);
        };
    }
}
