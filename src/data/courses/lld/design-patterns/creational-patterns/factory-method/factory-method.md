# Factory Method Pattern

> **Intent:** Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

<br>

---

## When to Use

- **Don't know the exact type** at compile time — determined by input/config
- **Want to decouple** object creation from usage
- **Need to centralize** creation logic (validation, caching, logging)
- **Eliminate `new` scattered** everywhere

<br>

---

## Simple Factory vs Factory Method

### Simple Factory (static method)
```java
class NotificationFactory {
    public static Notification create(String type) {
        return switch (type) {
            case "email" -> new EmailNotification();
            case "sms"   -> new SMSNotification();
            case "push"  -> new PushNotification();
            default -> throw new IllegalArgumentException("Unknown: " + type);
        };
    }
}

// Usage
Notification n = NotificationFactory.create("email");
n.send("Hello!");
```

### Factory Method (inheritance-based)
```java
abstract class NotificationCreator {
    // Factory method — subclasses decide what to create
    protected abstract Notification createNotification();
    
    // Template: create + configure + send
    public void notify(String message) {
        Notification n = createNotification();
        n.configure();
        n.send(message);
    }
}

class EmailNotificationCreator extends NotificationCreator {
    protected Notification createNotification() { return new EmailNotification(); }
}

class SMSNotificationCreator extends NotificationCreator {
    protected Notification createNotification() { return new SMSNotification(); }
}
```

<br>

---

## Real-World LLD Example: Document Parser

```java
interface Document { void parse(); String getContent(); }

class PDFDocument implements Document {
    public void parse() { /* PDF parsing logic */ }
    public String getContent() { return "PDF content"; }
}
class WordDocument implements Document {
    public void parse() { /* DOCX parsing logic */ }
    public String getContent() { return "Word content"; }
}
class ExcelDocument implements Document {
    public void parse() { /* XLSX parsing logic */ }
    public String getContent() { return "Excel content"; }
}

class DocumentFactory {
    public static Document create(String filename) {
        String ext = filename.substring(filename.lastIndexOf('.') + 1).toLowerCase();
        return switch (ext) {
            case "pdf"  -> new PDFDocument();
            case "docx" -> new WordDocument();
            case "xlsx" -> new ExcelDocument();
            default -> throw new UnsupportedOperationException("Unsupported: " + ext);
        };
    }
}

// Client code — doesn't know or care about concrete types
Document doc = DocumentFactory.create("report.pdf");
doc.parse();
System.out.println(doc.getContent());
```

<br>

---

## Common Interview Questions

1. **"Factory vs Constructor?"** → Factory centralizes creation, can return subtypes, can cache instances
2. **"Simple Factory vs Factory Method?"** → Simple = static method (not a GoF pattern); Factory Method = inheritance-based (GoF pattern)
3. **"Factory vs Abstract Factory?"** → Factory creates ONE product; Abstract Factory creates FAMILIES of related products

<br>

---

## Key Takeaways

1. **Centralizes object creation** — one place to change
2. **Returns interface type** — client doesn't know concrete class
3. **Open-Closed friendly** — add new types by adding new factories
4. **Simple Factory** is most commonly used in interviews
5. **Use when type is determined at runtime** (by input, config, etc.)
