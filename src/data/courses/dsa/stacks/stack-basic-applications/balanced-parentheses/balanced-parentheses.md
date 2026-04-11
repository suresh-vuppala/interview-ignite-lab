Check if a string containing parentheses '()', '{}', '[]' is balanced.

<br>

> Input: s = "({[]})"
> Output: true

> Input: s = "([)]"
> Output: false

<br>

---

## Constraints

- `1 ≤ s.length ≤ 10⁴`
- `s consists of '(', ')', '{', '}', '[', ']' only`

<br>

---

## All Possible Edge Cases

1. **Empty string:** Balanced
2. **Single character:** Unbalanced
3. **Correctly nested:** '({[]})' → true
4. **Wrong order:** '(]' → false
5. **Extra opening:** '(((' → false
6. **Interleaved:** '([)]' → false

<br>

---

## Solution 1: Brute Force — Repeated Removal

**Intuition:**
Repeatedly remove matching adjacent pairs "()", "{}", "[]" until no more can be removed. If string is empty, it was balanced.

### Time Complexity: O(n²) — each removal pass is O(n), up to n/2 passes
### Space Complexity: O(n) — string copy

<br>

---

## Solution 2: Stack (Optimal)

**Intuition:**
Push opening brackets onto stack. For closing brackets, check if stack top is the matching opener.

**Algorithm:**
1. For each char:
   - If opening bracket → push
   - If closing bracket → if stack empty or top doesn't match → false; else pop
2. Return stack is empty

### Time Complexity: O(n) — single pass
### Space Complexity: O(n) — stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Repeated Removal | O(n²) | O(n) | Remove pairs iteratively |
| Stack | O(n) | O(n) | Match with stack top — one pass |

<br>
<br>

---

```code```
