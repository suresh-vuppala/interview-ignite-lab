# Pattern X vs Pattern Y

> **"Why did you choose Strategy over State?"** — Interviewers use this to test depth. Knowing patterns is table stakes; knowing WHEN to use which is senior-level.

<br>

---

## Strategy vs State

| Aspect | Strategy | State |
|--------|----------|-------|
| **Who decides** | Client chooses the algorithm | Object transitions internally |
| **Awareness** | Client is aware of strategies | Client may not know about states |
| **Interchangeable** | Strategies are independent alternatives | States have specific transitions |
| **When to use** | Multiple algorithms for same task | Object behavior changes with state |
| **Example** | `cart.setPayment(new UPI())` | `order.ship()` → auto transitions |

**Rule of thumb:** If the CLIENT picks the behavior → Strategy. If the OBJECT changes behavior on its own → State.

<br>

---

## Factory vs Builder

| Aspect | Factory | Builder |
|--------|---------|---------|
| **Purpose** | Create different types | Construct complex objects step by step |
| **Parameters** | Few (type selector) | Many (optional, step by step) |
| **Returns** | Different subtypes | Same type, different configurations |
| **Example** | `NotificationFactory.create("email")` | `new Pizza.Builder(LARGE).cheese().pepperoni().build()` |

**Rule:** Type varies → Factory. Configuration varies → Builder.

<br>

---

## Observer vs Mediator

| Aspect | Observer | Mediator |
|--------|----------|---------|
| **Communication** | One-to-many (broadcast) | Many-to-many (through mediator) |
| **Coupling** | Subject doesn't know observers | Objects don't know each other at all |
| **Direction** | One direction (subject → observers) | Bidirectional (via mediator) |
| **Example** | Stock price → alert all subscribers | Chat room mediating messages between users |

<br>

---

## Decorator vs Proxy

| Aspect | Decorator | Proxy |
|--------|-----------|-------|
| **Purpose** | Add behavior | Control access |
| **Wraps** | Same interface, enhanced | Same interface, controlled |
| **Stacking** | Multiple decorators stack | Usually single proxy |
| **Example** | EncryptionDecorator(CompressionDecorator(file)) | CachingProxy, SecurityProxy |

<br>

---

## Template Method vs Strategy

| Aspect | Template Method | Strategy |
|--------|----------------|----------|
| **Mechanism** | Inheritance (override steps) | Composition (inject algorithm) |
| **Flexibility** | Fixed skeleton, vary steps | Entire algorithm swappable |
| **Binding** | Compile-time | Runtime |
| **When** | Shared algorithm skeleton | Completely different algorithms |

<br>

---

## How to Discuss Trade-offs in Interviews

### The TRADE Framework

1. **T**wo options: "I considered both Strategy and State here."
2. **R**eason for choice: "I chose Strategy because the client needs to select the algorithm."
3. **A**dvantage: "This gives us runtime swappability and OCP compliance."
4. **D**isadvantage acknowledged: "The downside is the client needs to know about all strategies."
5. **E**xtensibility: "If requirements change to auto-transitions, I'd refactor to State."

<br>

---

## Key Takeaways

1. **Know 5+ pattern comparisons cold** — they come up in every interview
2. **Use the TRADE framework** to structure your answer
3. **"It depends"** is OK — but always say WHAT it depends on
4. **Acknowledge trade-offs** — shows maturity over "my pattern is best"
5. **Be ready to refactor** — "If requirements change to X, I'd switch to Y"
