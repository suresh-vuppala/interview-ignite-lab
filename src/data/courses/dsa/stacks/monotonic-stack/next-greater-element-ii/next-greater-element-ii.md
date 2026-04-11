Given a circular array, find the next greater element for each element. The array wraps around — after the last element, the search continues from the first.

<br>

> Input: nums = [1, 2, 1]
> Output: [2, -1, 2]

> Explanation: 1→2 (next greater). 2→-1 (no greater in circular). 1→2 (wraps around to index 1).
> 
> **Key insight:** Simulate circular by iterating through the array TWICE (indices 0 to 2N-1, using i % N). Same monotonic stack approach but with 2N iterations.

<br>

---

## Constraints
- `1 ≤ nums.length ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **All same:** All -1
2. **Single element:** -1
3. **Sorted ascending:** Each element's NGE is the next; last wraps to first if first is larger

<br>

---

## Solution 1: Brute Force — Circular Scan

### Time Complexity: O(N²)

> **Drawback:** Scanning right (with wrap) for each element.

> **Key Insight for Improvement:** Iterate 0 to 2N-1, using i % N for circular indexing. Same monotonic stack, but only assign results for i < N. Each element pushed/popped at most twice → O(N).

<br>

---

## Solution 2: Monotonic Stack + Double Pass (Optimal)

**Algorithm:**
1. result = [-1] * N, stack = []
2. For i = 0 to 2N-1:
   - While stack not empty and nums[i%N] > nums[stack.top()]:
     - result[stack.pop()] = nums[i%N]
   - If i < N: push i (only push in first pass)

### Time Complexity: O(N)
**Why?** 2N iterations, each element pushed once, popped at most once.

**Detailed breakdown:** N = 10,000 → 20,000 iterations

**Example walkthrough:**
```
nums = [1, 2, 1], N=3

i=0(1): push 0 → stack=[0]
i=1(2): 2>1 → pop 0, result[0]=2. push 1 → stack=[1]
i=2(1): 1<2 → push 2 → stack=[1,2]
i=3(1): 1<2 → no pop (second pass, don't push)
i=4(2): 2>1 → pop 2, result[2]=2. 2==2 → no pop.
i=5(1): no pop.

Result: [2, -1, 2] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Circular scan per element |
| Monotonic Stack 2× | O(N) | O(N) | Double iteration simulates circular |

**Key Insights:**
1. **Circular = 2× iteration:** i % N maps 2N indices back to N positions
2. **Only push in first pass:** Prevents infinite loop
3. **Same stack pattern:** Monotonic decreasing, pop when greater found

<br><br>

---

```code```
