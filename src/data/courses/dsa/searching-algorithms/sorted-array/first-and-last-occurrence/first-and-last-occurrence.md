Find first and last position of target in sorted array.

<br>

> nums=[5,7,7,8,8,10], target=8 → [3,4]
>
> **Key insight:** Two binary searches: one for first occurrence (leftmost), one for last (rightmost).

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

## Solution 1: Linear scan both directions

**Intuition:**
The most straightforward approach. Even after finding one occurrence, scanning for boundaries is O(N).

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

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
> Even after finding one occurrence, scanning for boundaries is O(N).

> **Key Insight for Improvement:**
> Two binary searches: first occurrence uses hi=mid-1 on match. Last occurrence uses lo=mid+1 on match.

<br>

---

## Solution 2: Two Binary Searches (Optimal)

**Intuition:** Two binary searches: one for first occurrence (leftmost), one for last (rightmost).

**Algorithm:**
1. findFirst: on match → ans=mid, hi=mid-1 (keep searching left)
2. findLast: on match → ans=mid, lo=mid+1 (keep searching right)
3. Return [first, last]

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[5,7,7,8,8,10] target=8:
First: mid=7→lo=3, mid=8→ans=3,hi=2→first=3
Last: mid=8→ans=4,lo=5, mid=10→hi=4→last=4
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan both directions | O(N) | Varies | Baseline |
| Two Binary Searches | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Two Binary Searches — O(log N) time.

**Key Insights:**
1. **Don't stop at first match:** Continue searching for boundary
2. **Two searches:** One for left boundary, one for right
3. **Count = last - first + 1:** Gives frequency of target

<br><br>

---

```code```
