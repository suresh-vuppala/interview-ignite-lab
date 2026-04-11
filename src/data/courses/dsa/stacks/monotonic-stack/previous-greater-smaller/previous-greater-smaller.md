Given an array, find the Previous Greater Element (PGE) and Previous Smaller Element (PSE) for each element.

<br>

> Input: nums = [4, 5, 2, 10, 8]
> PGE Output: [-1, -1, 5, -1, 10]
> PSE Output: [-1, 4, -1, 2, 2]

> Explanation: PGE of 8 is 10 (nearest greater to the left). PSE of 10 is 2 (nearest smaller to the left).
> 
> **Key insight:** Process LEFT to RIGHT. For PGE: monotonic decreasing stack — top is the answer. For PSE: monotonic increasing stack — top is the answer. The stack naturally maintains the "previous" elements in sorted order.

<br>

---

## Constraints
- `1 ≤ nums.length ≤ 10⁵`

<br>

---

## Solution 1: Brute Force — Scan Left

### Time Complexity: O(N²) for each (PGE and PSE)

> **Drawback:** Scanning left for each element.

> **Key Insight for Improvement:** Stack maintains elements in monotonic order. For PGE: decreasing stack — pop smaller elements, top = PGE. For PSE: increasing stack — pop larger, top = PSE.

<br>

---

## Solution 2: Monotonic Stack — Left to Right (Optimal)

**PGE Algorithm:**
1. stack = [], result = [-1]*N
2. For i = 0 to N-1:
   - While stack and nums[stack.top()] ≤ nums[i]: pop
   - If stack not empty: result[i] = nums[stack.top()]
   - push i

**PSE Algorithm:** Same but pop while ≥ instead of ≤.

### Time Complexity: O(N) each

**Detailed breakdown:** N = 100,000 → 200,000 operations per variant

**Example walkthrough (PGE):**
```
nums = [4, 5, 2, 10, 8]
Decreasing stack

i=0(4): stack empty → PGE=-1. push → [0]
i=1(5): pop 0 (4≤5). stack empty → PGE=-1. push → [1]
i=2(2): 2<5 → PGE=nums[1]=5. push → [1,2]
i=3(10): pop 2,1. stack empty → PGE=-1. push → [3]
i=4(8): 8<10 → PGE=nums[3]=10. push → [3,4]

PGE: [-1, -1, 5, -1, 10] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Scan left per element |
| Monotonic Stack | O(N) | O(N) | Stack maintains sorted previous elements |

**Key Insights:**
1. **Four variants:** NGE (decreasing, L→R), NSE (increasing, L→R), PGE (decreasing, L→R read top), PSE (increasing, L→R read top)
2. **Previous vs Next:** For "previous," the answer is stack.top() BEFORE pushing. For "next," the answer is the element that CAUSES the pop.
3. **Direction:** All can be done left-to-right with proper stack maintenance

<br><br>

---

```code```
