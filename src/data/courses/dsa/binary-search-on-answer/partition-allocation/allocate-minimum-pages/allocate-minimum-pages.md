Allocate N books to M students minimizing the maximum pages any student reads.
- Each student gets at least one book.
- Each book should be allocated to only one student.
- Book allocation should be in a contiguous manner.
<br>

> books=[12,34,67,90], students=2 → 113 (12+34+67=113, 90=90)

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

## Solution 1: Try all allocations

**Intuition:**
The most straightforward approach. Exponential — trying all possible allocations.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N^M)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential — trying all possible allocations.

> **Key Insight for Improvement:**
> Binary search on max pages: lo=max(books), hi=sum(books). For each mid, greedily assign books sequentially — count students needed. If students ≤ M → feasible.

<br>

---

## Solution 2: BS on Answer + Greedy Check (Optimal)

**Intuition:** Binary search on the answer (maximum pages). For each candidate max, greedily check if allocation is feasible with M students.

**Algorithm:**
1. lo=max(books), hi=sum(books)
2. While lo ≤ hi:
   - mid = lo+(hi-lo)/2
   - If canAllocate(mid, M): ans=mid, hi=mid-1
   - Else: lo=mid+1
3. canAllocate: greedily assign books until sum > limit, then new student





### Time Complexity: O(N log S)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
books=[12,34,67,90] M=2: lo=90, hi=203
mid=146: [12,34,67]=113≤146, [90]≤146 → 2 students OK → ans=146, hi=145
mid=117: [12,34,67]=113≤117, [90]≤117 → OK → ans=117
mid=103: [12,34,67]=113>103 → need split → >2 students → lo=104
...→ ans=113 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all allocations | O(N^M) | Varies | Baseline |
| BS on Answer + Greedy Check | O(N log S) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer + Greedy Check — O(N log S) time.

**Key Insights:**
1. **BS on answer pattern:** Search in value space, not index space
2. **Greedy feasibility check:** Assign sequentially, count groups
3. **Same pattern for:** Painters partition, split array, ship capacity

<br><br>

---

```code```
