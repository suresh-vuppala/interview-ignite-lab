# Composition over Inheritance

> **"Favor object composition over class inheritance."** — Gang of Four

<br>

---

## Why Composition Wins

| Inheritance | Composition |
|------------|-------------|
| Static — decided at compile time | Dynamic — can change at runtime |
| Tight coupling to parent | Loose coupling via interfaces |
| Breaks encapsulation (subclass sees parent internals) | Black-box reuse |
| Single inheritance limit (Java) | Compose unlimited behaviors |
| Fragile base class problem | No base class dependency |

<br>

---

## Example: Notification System

### ❌ Inheritance approach — rigid

```java
class Notification { void send() { ... } }
class EmailNotification extends Notification { ... }
class EncryptedEmailNotification extends EmailNotification { ... }
class LoggedEncryptedEmailNotification extends EncryptedEmailNotification { ... }
// Explosion of subclasses for every combination!
```

### ✅ Composition approach — flexible

```java
interface MessageSender { void send(String msg); }
interface MessageEncryptor { String encrypt(String msg); }
interface MessageLogger { void log(String msg); }

class NotificationService {
    private MessageSender sender;
    private MessageEncryptor encryptor;  // Optional
    private MessageLogger logger;        // Optional
    
    public NotificationService(MessageSender sender) { this.sender = sender; }
    
    public void setEncryptor(MessageEncryptor e) { this.encryptor = e; }
    public void setLogger(MessageLogger l) { this.logger = l; }
    
    public void send(String message) {
        if (encryptor != null) message = encryptor.encrypt(message);
        if (logger != null) logger.log(message);
        sender.send(message);
    }
}

// Mix and match at runtime!
NotificationService svc = new NotificationService(new EmailSender());
svc.setEncryptor(new AESEncryptor());
svc.setLogger(new FileLogger());
```

<br>

---

## When Inheritance IS Appropriate

1. **True IS-A relationship** — Dog IS-A Animal (behavior + state shared)
2. **Stable hierarchy** — unlikely to change
3. **Template Method pattern** — shared algorithm skeleton
4. **Framework extension** — overriding specific hooks

<br>

---

## Key Takeaways

1. **Default to composition** — use inheritance only for true IS-A
2. **Composition = HAS-A** with interface-based delegation
3. **Avoids fragile base class problem**
4. **Enables runtime flexibility** — swap behaviors dynamically
5. **In interviews: always mention this when designing class hierarchies**
