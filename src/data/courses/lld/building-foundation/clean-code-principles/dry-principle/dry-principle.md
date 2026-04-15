# DRY — Don't Repeat Yourself

> "Every piece of knowledge must have a single, unambiguous, authoritative representation within a system."

<br>

---

## The Problem: Code Duplication

```java
// ❌ Duplicated validation logic in 3 places
class UserService {
    public void createUser(String email) {
        if (email == null || !email.contains("@") || email.length() > 255)
            throw new IllegalArgumentException("Invalid email");
        // ... create user
    }
    
    public void updateEmail(int userId, String email) {
        if (email == null || !email.contains("@") || email.length() > 255)  // DUPLICATED!
            throw new IllegalArgumentException("Invalid email");
        // ... update email
    }
}
```

## The Fix: Extract and Reuse

```java
// ✅ Single source of truth
class EmailValidator {
    public static void validate(String email) {
        if (email == null || !email.contains("@") || email.length() > 255)
            throw new IllegalArgumentException("Invalid email");
    }
}

class UserService {
    public void createUser(String email) {
        EmailValidator.validate(email);  // One call
    }
    public void updateEmail(int userId, String email) {
        EmailValidator.validate(email);  // Same call
    }
}
```

<br>

---

## Types of Duplication

1. **Code duplication** — same logic copy-pasted
2. **Knowledge duplication** — same business rule in multiple places
3. **Data duplication** — same constant defined in multiple files

<br>

---

## Key Takeaways

1. **Extract common logic** into methods/classes
2. **Constants in one place** — not magic numbers scattered everywhere
3. **BUT: Don't over-DRY** — sometimes similar-looking code has different reasons to change
4. **DRY is about knowledge, not just code** — two identical lines serving different purposes aren't duplication
