// SRP Example — Order Processing System
// Each class has exactly ONE responsibility

// 1. Domain model — holds data and business rules
class Order {
    private String orderId;
    private List<OrderItem> items;
    private OrderStatus status;
    
    public double calculateTotal() {
        return items.stream().mapToDouble(OrderItem::getSubtotal).sum();
    }
    
    public void addItem(OrderItem item) {
        if (status != OrderStatus.DRAFT) 
            throw new IllegalStateException("Cannot modify non-draft order");
        items.add(item);
    }
}

// 2. Persistence — save/load orders
class OrderRepository {
    public void save(Order order) { /* Database INSERT/UPDATE */ }
    public Order findById(String id) { /* Database SELECT */ }
    public List<Order> findByCustomer(String customerId) { /* Query */ }
}

// 3. Validation — check order validity
class OrderValidator {
    public void validate(Order order) {
        if (order.getItems().isEmpty()) 
            throw new ValidationException("Order must have items");
        if (order.calculateTotal() <= 0) 
            throw new ValidationException("Order total must be positive");
    }
}

// 4. Notification — inform customer
class OrderNotificationService {
    private final EmailService emailService;
    private final SMSService smsService;
    
    public void notifyOrderPlaced(Order order, Customer customer) {
        emailService.send(customer.getEmail(), "Order Confirmed", 
            "Your order " + order.getOrderId() + " has been placed.");
    }
}

// 5. PDF generation — create invoice
class InvoiceGenerator {
    public byte[] generatePDF(Order order) {
        // PDF creation logic — formatting, layout, etc.
        return new byte[0]; // PDF bytes
    }
}
