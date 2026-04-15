// OCP Example — Extensible Pricing System
interface PricingRule {
    boolean appliesTo(Order order);
    double calculatePrice(Order order);
}

class StandardPricing implements PricingRule {
    public boolean appliesTo(Order order) { return true; } // Default
    public double calculatePrice(Order order) { return order.getBaseTotal(); }
}

class BulkDiscount implements PricingRule {
    public boolean appliesTo(Order order) { return order.getItemCount() > 100; }
    public double calculatePrice(Order order) { return order.getBaseTotal() * 0.85; }
}

class LoyaltyDiscount implements PricingRule {
    public boolean appliesTo(Order order) { return order.getCustomer().isLoyal(); }
    public double calculatePrice(Order order) { return order.getBaseTotal() * 0.90; }
}

// NEW: Holiday pricing — NO changes to existing rules!
class HolidayPricing implements PricingRule {
    public boolean appliesTo(Order order) { return isHolidaySeason(); }
    public double calculatePrice(Order order) { return order.getBaseTotal() * 0.80; }
}

// Engine — NEVER changes (closed for modification)
class PricingEngine {
    private List<PricingRule> rules;
    
    public double calculateBestPrice(Order order) {
        return rules.stream()
            .filter(r -> r.appliesTo(order))
            .mapToDouble(r -> r.calculatePrice(order))
            .min()
            .orElse(order.getBaseTotal());
    }
}
