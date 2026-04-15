# Activity Diagrams

Activity diagrams show the **workflow or business logic** of a system — like a fancy flowchart with support for parallelism and decision points.

<br>

---

## Core Elements

| Element | Symbol | Purpose |
|---------|--------|---------|
| **Start** | ● (filled circle) | Entry point |
| **End** | ⊙ (bull's eye) | Terminal point |
| **Action** | Rounded rectangle | A step/activity |
| **Decision** | Diamond ◇ | Branch (if-else) |
| **Fork/Join** | Thick bar | Parallel execution |
| **Swimlanes** | Vertical columns | Responsibility assignment |

<br>

---

## Example: Order Processing Workflow

```
● Start
    │
    ▼
[Receive Order]
    │
    ◇──── Is payment valid? ──── No ──→ [Reject Order] → ⊙
    │ Yes
    ▼
════════════ Fork ════════════
    │                    │
    ▼                    ▼
[Reserve Inventory]  [Process Payment]
    │                    │
════════════ Join ════════════
    │
    ▼
[Ship Order]
    │
    ▼
[Send Confirmation]
    │
    ▼
⊙ End
```

<br>

---

## When to Use in LLD Interviews

- **Complex business workflows** (order processing, loan approval)
- **State transitions** with conditions
- **Parallel operations** (fork/join)
- **Multi-actor flows** using swimlanes

<br>

---

## Key Takeaways

1. **Flowchart on steroids** — supports parallelism and swimlanes
2. **Good for business logic** and approval workflows
3. **Less common than class/sequence** in LLD interviews
4. **Use when interviewer asks "walk me through the workflow"**
