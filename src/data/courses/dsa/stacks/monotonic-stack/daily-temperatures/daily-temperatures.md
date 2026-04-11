Given daily temperatures, return array where each element is the number of days until a warmer temperature. If no warmer day, return 0.

<br>

> Input: [73, 74, 75, 71, 69, 72, 76, 73]
> Output: [1, 1, 4, 2, 1, 1, 0, 0]

<br>

---

## Constraints

- `1 ≤ temperatures.length ≤ 10⁵`
- `30 ≤ temperatures[i] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Strictly increasing:** [1,1,1,...,0]
2. **Strictly decreasing:** All zeros
3. **All same:** All zeros
4. **Single element:** [0]

<br>

---

## Solution 1: Brute Force

**Intuition:** For each day, scan forward until a warmer day.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Monotonic Stack (Optimal)

**Intuition:**
Maintain a decreasing stack of indices. When current temp is warmer than stack top, pop and record the difference.

**Algorithm:**
1. Stack stores indices (not values)
2. For each i:
   - While stack not empty AND temp[i] > temp[stack.top()]:
     - j = stack.pop()
     - result[j] = i - j
   - Push i onto stack
3. Remaining stack elements → result stays 0

**Why O(n)?** Each index pushed once, popped at most once → 2n operations total.

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Scan forward for each |
| Monotonic Stack | O(n) | O(n) | Decreasing stack resolves on warmer day |

<br>
<br>

---

```code```
