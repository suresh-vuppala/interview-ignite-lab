## Stacks — Last In, First Out (LIFO)

A stack is a linear data structure where elements are added and removed from the **same end** (the top). Think of a stack of plates — you always add and remove from the top.

<br>

## Why Stacks Matter in Interviews

Stacks appear in **~10% of FAANG interviews** across three major patterns:

1. **Parentheses matching** — Valid parentheses, remove invalid, make valid
2. **Monotonic stack** — Next greater element, daily temperatures, largest rectangle
3. **Expression evaluation** — Postfix, prefix, infix conversion and evaluation

<br>

## The Monotonic Stack Pattern

The most powerful stack pattern for interviews. Maintains elements in **increasing or decreasing order**:

- **Next Greater Element:** Maintain decreasing stack, pop when current > top
- **Largest Rectangle in Histogram:** Find left/right boundaries using stack
- **Daily Temperatures:** How many days until warmer? → decreasing stack

**Time Complexity:** O(n) — each element pushed and popped at most once.

<br>

## Key Problems by Difficulty

| Easy | Medium | Hard |
|------|--------|------|
| Valid Parentheses | Daily Temperatures | Largest Rectangle Histogram |
| Min Stack | Decode String | Maximal Rectangle |
| | Remove K Digits | Trapping Rain Water (stack approach) |

<br>

---

```code```
