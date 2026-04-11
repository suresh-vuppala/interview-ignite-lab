For each element in an array, find the next greater element to its right. If none exists, return -1.

<br>

> Input: [4, 5, 2, 25]
> Output: [5, 25, 25, -1]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Strictly decreasing:** All -1
2. **Strictly increasing:** Each element's NGE is the next one
3. **Single element:** [-1]
4. **All same:** All -1

<br>

---

## Solution 1: Brute Force

**Intuition:** For each element, scan right for a greater one.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Monotonic Stack — Right to Left (Optimal)

**Intuition:**
Process from right. Maintain increasing stack (from top). For each element, pop smaller/equal elements (they can't be NGE for anyone). Stack top is the NGE.

**Algorithm:**
1. Process from right to left
2. While stack not empty AND stack.top() ≤ nums[i] → pop
3. result[i] = stack empty ? -1 : stack.top()
4. Push nums[i]

### Time Complexity: O(n) — each element pushed/popped once
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Scan right for each |
| Monotonic Stack | O(n) | O(n) | Stack maintains potential NGEs |

<br>
<br>

---

```code```
