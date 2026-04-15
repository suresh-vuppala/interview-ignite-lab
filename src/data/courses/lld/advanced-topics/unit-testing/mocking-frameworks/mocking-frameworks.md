# Mocking Frameworks

> **A mock replaces a real dependency with a controlled substitute** that you can program to return specific values and verify interactions.

<br>

---

## Mockito Basics (Java)

```java
// Create mock
EmailService mockEmail = mock(EmailService.class);

// Stub: program return values
when(mockEmail.send("hello")).thenReturn(true);
when(mockEmail.send(anyString())).thenReturn(true);
when(mockEmail.send("fail")).thenThrow(new RuntimeException("SMTP error"));

// Verify: check interactions
verify(mockEmail).send("hello");           // Was send("hello") called?
verify(mockEmail, times(2)).send(any());   // Called exactly 2 times?
verify(mockEmail, never()).send("spam");   // Never called with "spam"?
```

<br>

---

## Mock vs Stub vs Spy

| Type | Purpose |
|------|---------|
| **Mock** | Verify interactions (was method called?) |
| **Stub** | Return canned answers (when X → return Y) |
| **Spy** | Wrap real object, override specific methods |

```java
// Spy — real object with overrides
List<String> realList = new ArrayList<>();
List<String> spy = spy(realList);
doReturn(100).when(spy).size(); // Override size()
spy.add("hello"); // Actually adds to real list
spy.size();        // Returns 100 (overridden)
```

<br>

---

## Best Practices

1. **Mock interfaces, not concrete classes**
2. **Don't mock what you don't own** — wrap third-party code in your own interface
3. **One assert per test** (ideal) — clear failure messages
4. **Test behavior, not implementation** — don't verify every internal call
5. **Use `@InjectMocks`** for auto-wiring mocks into the class under test

<br>

---

## Key Takeaways

1. **Mockito** is the standard Java mocking framework
2. **`when().thenReturn()`** for stubs, **`verify()`** for verification
3. **Mock at boundaries** — external services, databases, APIs
4. **In LLD interviews:** mentioning testability shows senior thinking
