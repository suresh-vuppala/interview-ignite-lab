// Inheritance Example — Payment Processing Hierarchy
abstract class Payment {
    protected String paymentId;
    protected double amount;
    protected PaymentStatus status;
    
    public Payment(String paymentId, double amount) {
        this.paymentId = paymentId;
        this.amount = amount;
        this.status = PaymentStatus.PENDING;
    }
    
    // Template pattern: common flow, specific steps
    public final void process() {
        validate();
        executePayment();
        updateStatus();
        sendConfirmation();
    }
    
    protected void validate() {
        if (amount <= 0) throw new IllegalArgumentException("Amount must be positive");
    }
    
    protected abstract void executePayment();  // Subclass-specific
    
    protected void updateStatus() { this.status = PaymentStatus.COMPLETED; }
    protected void sendConfirmation() { System.out.println("Payment " + paymentId + " confirmed"); }
}

class CreditCardPayment extends Payment {
    private String cardNumber;
    private String cvv;
    
    public CreditCardPayment(String id, double amount, String cardNumber, String cvv) {
        super(id, amount);
        this.cardNumber = cardNumber;
        this.cvv = cvv;
    }
    
    @Override
    protected void validate() {
        super.validate();  // Amount check
        if (cardNumber == null || cardNumber.length() != 16)
            throw new IllegalArgumentException("Invalid card number");
    }
    
    @Override
    protected void executePayment() {
        System.out.println("Charging card ending in " + cardNumber.substring(12));
    }
}

class UPIPayment extends Payment {
    private String upiId;
    
    public UPIPayment(String id, double amount, String upiId) {
        super(id, amount);
        this.upiId = upiId;
    }
    
    @Override
    protected void executePayment() {
        System.out.println("Processing UPI payment via " + upiId);
    }
}

enum PaymentStatus { PENDING, COMPLETED, FAILED }
