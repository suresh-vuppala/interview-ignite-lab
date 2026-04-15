# Chain of Responsibility Pattern

> **Intent:** Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

<br>

---

## When to Use

- **Multiple handlers** for a request, handler determined at runtime
- **Logging levels** — DEBUG → INFO → WARN → ERROR
- **Middleware/filters** — authentication → authorization → validation → processing
- **Approval workflows** — manager → director → VP → CEO

<br>

---

## Example: Expense Approval Chain

```java
abstract class ApprovalHandler {
    protected ApprovalHandler next;
    
    public ApprovalHandler setNext(ApprovalHandler handler) {
        this.next = handler;
        return handler; // Enable chaining
    }
    
    public void approve(ExpenseRequest request) {
        if (canApprove(request)) {
            processApproval(request);
        } else if (next != null) {
            next.approve(request); // Pass to next handler
        } else {
            System.out.println("❌ No one can approve $" + request.getAmount());
        }
    }
    
    protected abstract boolean canApprove(ExpenseRequest request);
    protected abstract void processApproval(ExpenseRequest request);
}

class Manager extends ApprovalHandler {
    protected boolean canApprove(ExpenseRequest r) { return r.getAmount() <= 1000; }
    protected void processApproval(ExpenseRequest r) {
        System.out.println("✅ Manager approved $" + r.getAmount());
    }
}

class Director extends ApprovalHandler {
    protected boolean canApprove(ExpenseRequest r) { return r.getAmount() <= 10000; }
    protected void processApproval(ExpenseRequest r) {
        System.out.println("✅ Director approved $" + r.getAmount());
    }
}

class VP extends ApprovalHandler {
    protected boolean canApprove(ExpenseRequest r) { return r.getAmount() <= 100000; }
    protected void processApproval(ExpenseRequest r) {
        System.out.println("✅ VP approved $" + r.getAmount());
    }
}

// Build chain: Manager → Director → VP
ApprovalHandler chain = new Manager();
chain.setNext(new Director()).setNext(new VP());

chain.approve(new ExpenseRequest(500));    // Manager approves
chain.approve(new ExpenseRequest(5000));   // Director approves
chain.approve(new ExpenseRequest(50000));  // VP approves
chain.approve(new ExpenseRequest(500000)); // No one can approve
```

<br>

---

## Real-World Examples

- **Java Servlet Filters** — `FilterChain.doFilter()`
- **Spring Security** — authentication filter chain
- **Logging frameworks** — log level handlers
- **HTTP middleware** — Express.js, Spring interceptors

<br>

---

## Key Takeaways

1. **Decouple sender from receiver** — sender doesn't know who handles it
2. **Chain of handlers** — each decides: handle or pass along
3. **Order matters** — first handler that can process wins
4. **Used in:** logging, middleware, approval workflows, event bubbling
