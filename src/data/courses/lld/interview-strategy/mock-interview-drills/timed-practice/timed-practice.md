# Mock Interview Drills — Timed Practice

> **You don't rise to the level of your knowledge. You fall to the level of your practice.** Timed practice is the single best way to prepare.

<br>

---

## The 45-Minute Template

| Time | Phase | Activity | Deliverable |
|------|-------|----------|-------------|
| 0-5 min | **Clarify** | Ask requirements, scope, constraints | Written requirements list |
| 5-10 min | **Entities** | Noun-verb extraction, identify 5-8 classes | Entity list with key attributes |
| 10-20 min | **Class Diagram** | Draw entities, relationships, interfaces | Complete class diagram |
| 20-25 min | **Sequence Diagram** | Walk through core flow | 1 sequence diagram |
| 25-40 min | **Code** | Implement core classes + key method | Working code for 3-5 classes |
| 40-45 min | **Discuss** | Patterns used, trade-offs, extensions | Verbal discussion |

<br>

---

## Self-Evaluation Rubric

After each practice, score yourself (1-5 on each):

| Criteria | 1 (Poor) | 3 (Average) | 5 (Excellent) |
|----------|----------|-------------|---------------|
| **Requirements** | Skipped or obvious Qs | Some clarification | FENCE framework, scoped well |
| **Entities** | Missing key entities | Core entities found | All entities + enums + services |
| **Relationships** | No relationships shown | Some lines drawn | Typed (◆◇→), multiplicity labeled |
| **Patterns** | No patterns mentioned | 1 pattern used | 2-3 patterns, justified choices |
| **Code Quality** | Pseudocode only | Working but messy | Clean, SOLID, compiles |
| **Concurrency** | Not mentioned | Mentioned briefly | Specific mechanisms + race conditions |
| **Edge Cases** | Not discussed | 1-2 mentioned | 5+ with handling strategy |
| **Communication** | Silent coding | Some narration | Continuous explanation of decisions |

**Target: 30+ out of 40** — you're interview-ready.

<br>

---

## Practice Problems (Easy → Hard)

### Warm-up (20 min each)
1. Design a Stack with getMin() in O(1)
2. Design a Logger with rate limiting
3. Design a URL Shortener (just the classes)

### Medium (35 min each)
4. Design a Parking Lot
5. Design a Library Management System
6. Design Tic-Tac-Toe
7. Design a Vending Machine

### Hard (45 min each)
8. Design a Movie Ticket Booking System (with concurrency)
9. Design a Rate Limiter (Token Bucket + Sliding Window)
10. Design an Uber Driver Dispatch System
11. Design a Cache System (LRU + LFU)
12. Design a Chess Game

<br>

---

## The 5-Problem Rule

> **Practice 5 full problems end-to-end with timer, and you'll be ready for any LLD interview.**

Why 5 is enough:
- After 2 problems: You have the framework down
- After 3 problems: You spot patterns across problems
- After 5 problems: You're fast enough for 45-minute constraint

<br>

---

## Common Time Traps

| Trap | Time Wasted | Fix |
|------|------------|-----|
| **Over-clarifying requirements** | 10+ min | Cap at 5 min, start designing |
| **Perfect class diagram** | 15+ min | Sketch quickly, refine during coding |
| **Implementing everything** | Run out of time | Implement core, mention extensions |
| **Debating pattern choice** | 5+ min | Pick one, justify, move on |
| **Not talking** | — | Interviewer can't evaluate silent work |

<br>

---

## The Talk-While-You-Work Script

Practice saying these out loud while designing:

1. **Starting:** "Let me start by clarifying the requirements..."
2. **Entities:** "The core entities I see are... because..."
3. **Diagram:** "ParkingLot HAS many Floors, each Floor HAS many Spots..."
4. **Pattern choice:** "I'm using Strategy here because the pricing logic varies by vehicle type..."
5. **Code:** "Let me implement the core parking flow first..."
6. **Trade-off:** "I'm trading O(N) memory for O(1) lookups because..."
7. **Extension:** "If we needed X in the future, I'd add Y interface..."

<br>

---

## Key Takeaways

1. **Time yourself** — every practice session should be timed
2. **Use the 45-minute template** religiously until it's automatic
3. **Score yourself** with the rubric after each practice
4. **5 full problems** makes you interview-ready
5. **Talk constantly** — narrate every decision, it's 50% of the evaluation
6. **Record yourself** (video) — watch back to find improvement areas
