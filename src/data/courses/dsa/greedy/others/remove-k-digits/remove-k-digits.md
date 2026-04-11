Remove k digits from a number string to make it the smallest possible.

<br>

> Input: num = "1432219", k = 3
> Output: "1219"

<br>

---

## Constraints

- `1 ≤ k ≤ num.length ≤ 10⁵`
- `num consists of digits 0-9`

<br>

---

## All Possible Edge Cases

1. **k = num.length:** Return "0"
2. **k = 0:** Return original
3. **Increasing digits:** Remove last k
4. **Decreasing digits:** Remove first k
5. **Leading zeros:** "10200" k=1 → "200"

<br>

---

## Solution 1: Try All Combinations

**Intuition:** Remove all C(n,k) combinations, find minimum.

### Time Complexity: O(C(n,k) × n)
### Space Complexity: O(n)

<br>

---

## Solution 2: Monotonic Stack / Greedy (Optimal)

**Intuition:**
Process left to right. If current digit is smaller than the previous (stack top), remove the larger previous digit (greedy: leftmost large digit has most impact). Use a stack to maintain increasing order.

**Algorithm:**
1. For each digit:
   - While k > 0 AND stack not empty AND stack.top() > digit:
     - Pop stack, k--
   - Push digit
2. If k > 0, remove last k digits (all increasing)
3. Remove leading zeros
4. Return "0" if empty

### Time Complexity: O(n) — each digit pushed/popped once
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| All Combinations | O(C(n,k)×n) | O(n) | Exponential |
| Monotonic Stack | O(n) | O(n) | Greedy: remove leftmost larger digit |

<br>
<br>

---

```code```
