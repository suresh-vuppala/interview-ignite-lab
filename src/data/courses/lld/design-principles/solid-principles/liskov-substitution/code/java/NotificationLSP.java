// LSP Example — Notification System
// All notification types must honor the send() contract

interface Notification {
    void send(String recipient, String message);
    boolean isDelivered();
}

class EmailNotification implements Notification {
    private boolean delivered = false;
    
    @Override
    public void send(String recipient, String message) {
        // Always attempts delivery — honors contract
        System.out.println("Email to " + recipient + ": " + message);
        delivered = true;
    }
    
    @Override
    public boolean isDelivered() { return delivered; }
}

class SMSNotification implements Notification {
    private boolean delivered = false;
    
    @Override
    public void send(String recipient, String message) {
        if (message.length() > 160) {
            // Still sends — truncates instead of throwing exception
            message = message.substring(0, 157) + "...";
        }
        System.out.println("SMS to " + recipient + ": " + message);
        delivered = true;
    }
    
    @Override
    public boolean isDelivered() { return delivered; }
}

// ❌ BAD: This would violate LSP
// class FaxNotification implements Notification {
//     public void send(String recipient, String message) {
//         throw new UnsupportedOperationException("Fax not supported");
//         // Breaks the contract — callers expect send() to work!
//     }
// }

// Client code works with ANY Notification — LSP satisfied
class NotificationService {
    public void broadcast(List<Notification> channels, String recipient, String msg) {
        for (Notification n : channels) {
            n.send(recipient, msg);  // Safe — all implementations honor the contract
        }
    }
}
