# KISS — Keep It Simple, Stupid

> "The simplest solution that works is usually the best."

<br>

---

## The Problem: Over-Engineering

```java
// ❌ Over-engineered: AbstractStrategyFactoryBuilderProxy for a simple task
class UserNameFormatterStrategyFactory {
    public UserNameFormatterStrategy create(String type) {
        return switch(type) {
            case "first-last" -> new FirstLastStrategy();
            case "last-first" -> new LastFirstStrategy();
            default -> new DefaultStrategy();
        };
    }
}
// ... 5 classes for what could be 3 lines
```

## The Fix: Simple and Direct

```java
// ✅ Simple and clear
class UserNameFormatter {
    public static String format(String first, String last, boolean lastNameFirst) {
        return lastNameFirst ? last + ", " + first : first + " " + last;
    }
}
```

<br>

---

## Practical Guidelines

1. **Don't add patterns preemptively** — add complexity only when needed
2. **Fewer abstractions** — not every method needs an interface
3. **Clear names over clever code** — `isEligibleForDiscount()` not `chk_dsc()`
4. **If you can't explain it simply, it's too complex**

<br>

---

## Key Takeaways

1. **Start simple, refactor when complexity is justified**
2. **Patterns are tools, not goals** — don't use Factory when `new` works fine
3. **Simple code is easier to test, debug, and maintain**
4. **Complexity should be proportional to the problem**
