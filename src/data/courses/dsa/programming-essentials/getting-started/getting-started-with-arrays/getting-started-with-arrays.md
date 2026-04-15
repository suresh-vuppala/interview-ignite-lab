Introduction to arrays: creation, access, insertion, deletion, traversal.

<br>

> arr=[1,2,3,4,5], access arr[2]→3, insert at index 2→shift elements
>
> **Key insight:** Arrays store elements in contiguous memory. O(1) random access by index. O(N) insert/delete (shifting required).

<br>

---

## Constraints
- Fundamental array operations
- 0-indexed in most languages

<br>

---

## Solution 1: N/A — foundational

**Intuition:**
The most straightforward approach. Understanding tradeoffs is key.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: Varies
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Understanding tradeoffs is key.

> **Key Insight for Improvement:**
> Arrays: fast access O(1), slow insert/delete O(N). Dynamic arrays (vector/ArrayList) handle resizing.

<br>

---

## Solution 2: Array Fundamentals (Optimal)

**Intuition:** Arrays store elements in contiguous memory. O(1) random access by index. O(N) insert/delete (shifting required).

**Algorithm:**
Access: arr[i] — O(1)
Insert at i: shift [i..N-1] right — O(N)
Delete at i: shift [i+1..N-1] left — O(N)
Append: O(1) amortized (dynamic array)
Search: O(N) unsorted, O(log N) sorted

### Time Complexity: O(1) access
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
arr=[1,2,3,4,5]: arr[2]=3 (O(1))
Insert 99 at index 2: [1,2,99,3,4,5] — shifted 3 elements
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — foundational | Varies | Varies | Baseline |
| Array Fundamentals | O(1) access | O(N) | Optimal |

**Recommended Solution:** Array Fundamentals

**Key Insights:**
1. **Contiguous memory:** Cache-friendly, O(1) index access
2. **Fixed vs dynamic:** Static arrays vs vector/ArrayList
3. **Foundation:** Most data structures build on arrays

<br><br>

---

```code```
