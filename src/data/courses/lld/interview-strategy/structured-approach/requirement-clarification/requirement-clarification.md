# Step 1: Requirement Clarification

> **The first 5 minutes of an LLD interview determine 80% of your score.** Jumping into code without clarifying requirements is the #1 reason candidates fail.

<br>

---

## Why This Step Matters

Interviewers **deliberately leave requirements vague** to test if you:
- Can identify **ambiguity** and ask smart questions
- Understand the difference between **functional** and **non-functional** requirements
- Can **scope** the problem to fit 45 minutes
- Think about **edge cases** before coding

**Candidates who start coding immediately** often design the wrong system.

<br>

---

## The Framework: FENCE

Use this mnemonic to structure your clarification:

| Letter | Question Type | Examples |
|--------|-------------|----------|
| **F** | **Functional** | What are the core features? What can users do? |
| **E** | **Entities** | What are the main objects/actors? |
| **N** | **Non-functional** | Scale? Concurrency? Latency? |
| **C** | **Constraints** | Limits? Data sizes? Rules? |
| **E** | **Edge cases** | What happens when X fails? Concurrent access? |

<br>

---

## Functional Requirements — What to Ask

### Template Questions
1. "What are the **core use cases** we need to support?"
2. "Who are the **primary actors** (users, admins, systems)?"
3. "Can you help me **prioritize** — which features are must-have vs nice-to-have?"
4. "Should we support [specific feature] or is that out of scope?"

### Example: "Design a Parking Lot"

```
You: "Let me clarify a few things first..."

1. "How many floors? Is multi-floor a requirement?"
   → Interviewer: "Yes, multiple floors."

2. "What vehicle types? Just cars, or motorcycles and trucks too?"
   → Interviewer: "Cars, motorcycles, and trucks."

3. "Do we need payment processing or just spot allocation?"
   → Interviewer: "Both — hourly pricing."

4. "Multiple entry/exit points or single?"
   → Interviewer: "Let's start with single, extend later."

5. "Do we need reserved spots (handicapped, VIP)?"
   → Interviewer: "Nice-to-have, focus on core first."
```

**Result:** You now have a clear, scoped problem.

<br>

---

## Non-Functional Requirements — What to Ask

| Category | Question |
|----------|----------|
| **Scale** | "How many concurrent users/requests?" |
| **Concurrency** | "Multiple threads accessing shared resources?" |
| **Latency** | "Any real-time requirements?" |
| **Durability** | "In-memory OK or need persistence?" |
| **Extensibility** | "Should the design support adding new types easily?" |

### LLD-Specific Non-Functional Concerns

For LLD (unlike system design), focus on:
- **Thread safety** — "Can multiple users book the same resource?"
- **Extensibility** — "Should I design for new vehicle/payment types?"
- **Testability** — "Should we discuss testing approach?"

<br>

---

## Scoping — What to Include vs Exclude

### The 45-Minute Rule

You have ~45 minutes total:
- **5 min**: Requirement clarification ← YOU ARE HERE
- **10 min**: Entity identification + relationships
- **10 min**: Class diagram
- **15 min**: Code implementation
- **5 min**: Discussion (patterns, trade-offs, extensions)

### What to Say

> "Given 45 minutes, I'll focus on [core features]. I'll mention [extensions] but implement the core. Does that sound good?"

This shows you can **prioritize** and manage time — a senior skill.

<br>

---

## Common Mistakes

| Mistake | Why It's Bad | Fix |
|---------|-------------|-----|
| **Jump straight to coding** | Miss requirements, design wrong system | Always clarify first |
| **Ask too many questions (10+ min)** | Wastes time, seems indecisive | 5 min max, then move on |
| **Never ask questions** | Design may miss key features | At least 3-5 clarifying Qs |
| **Ask obvious questions** | "What is a parking lot?" wastes time | Ask about ambiguous parts only |
| **Don't scope** | Try to implement everything, run out of time | Explicitly scope with interviewer |

<br>

---

## Key Takeaways

1. **5 minutes of clarification saves 15 minutes of wrong design**
2. **FENCE framework**: Functional, Entities, Non-functional, Constraints, Edge cases
3. **Scope explicitly** — "I'll focus on X, mention Y, skip Z"
4. **Ask about concurrency** — it's the #1 LLD differentiator
5. **Write requirements down** — bullet list on whiteboard/doc before designing
