// Abstraction Example — Notification Service
interface NotificationSender {
    void send(String recipient, String message);
    boolean isAvailable();
}

class EmailSender implements NotificationSender {
    private String smtpHost;
    
    public EmailSender(String smtpHost) { this.smtpHost = smtpHost; }
    
    public void send(String recipient, String message) {
        System.out.println("Sending email to " + recipient + " via " + smtpHost);
    }
    
    public boolean isAvailable() { return smtpHost != null; }
}

class SMSSender implements NotificationSender {
    private String apiKey;
    
    public SMSSender(String apiKey) { this.apiKey = apiKey; }
    
    public void send(String recipient, String message) {
        System.out.println("Sending SMS to " + recipient);
    }
    
    public boolean isAvailable() { return apiKey != null; }
}

// Client depends on abstraction — doesn't know concrete sender
class AlertService {
    private NotificationSender sender;
    
    public AlertService(NotificationSender sender) {
        this.sender = sender;  // Dependency injection
    }
    
    public void alert(String recipient, String message) {
        if (sender.isAvailable()) {
            sender.send(recipient, message);
        }
    }
}
