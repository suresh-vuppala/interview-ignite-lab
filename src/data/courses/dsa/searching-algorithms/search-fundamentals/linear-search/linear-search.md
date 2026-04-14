Search for an element by scanning array left to right.

<br>

> nums=[5,3,7,1,9], target=7 → index 2
>
> **Key insight:** Sequential scan — check each element until found or end reached.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: N/A

**Intuition:**
The most straightforward approach. Must check every element in worst case.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Must check every element in worst case. No way to skip.

> **Key Insight for Improvement:**
> If array is sorted, binary search eliminates half each step → O(log N).

<br>

---

## Solution 2: Linear Scan (Optimal)

**Intuition:** Sequential scan — check each element until found or end reached.

**Algorithm:**
1. For i = 0 to N-1: if arr[i] == target → return i
2. Return -1 (not found)

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[5,3,7,1,9] target=7: check 5≠7, 3≠7, 7==7 → return 2
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A | O(N) | Varies | Baseline |
| Linear Scan | O(N) | O(1) | Optimal approach |

**Recommended Solution:** Linear Scan — O(N) time.

**Key Insights:**
1. **Unsorted arrays only option:** No structure to exploit
2. **Best case O(1):** Target at first position
3. **Foundation:** Understand why sorted order enables binary search

<br><br>

---

```code```
