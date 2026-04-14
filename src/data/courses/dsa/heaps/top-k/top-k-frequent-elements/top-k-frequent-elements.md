Return the K most frequent elements in an array.

<br>

> nums=[1,1,1,2,2,3], k=2 → [1,2]
>
> **Key insight:** Count frequencies with hash map. Then: min-heap of size K, or bucket sort by frequency for O(N).

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Sort by frequency

**Intuition:**
The most straightforward approach. Sorting all elements by frequency when we only need top K is wasteful.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N log N)
**Why?**
Sorting or divide-and-conquer requires O(N log N).
Each of log N levels processes N elements.

**Detailed breakdown:**
For N=100,000: ~1.7 million operations — efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Sorting all elements by frequency when we only need top K is wasteful.

> **Key Insight for Improvement:**
> Bucket sort: create buckets indexed by frequency. Bucket[f] = elements with frequency f. Scan from highest bucket. O(N) total.

<br>

---

## Solution 2: HashMap + Bucket Sort (Optimal)

**Intuition:** Count frequencies with hash map. Then: min-heap of size K, or bucket sort by frequency for O(N).

**Algorithm:**
1. Count frequencies: HashMap → O(N)
2. Create frequency buckets: bucket[freq] = [elements]
3. Scan buckets from highest frequency down
4. Collect K elements

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
nums=[1,1,1,2,2,3] → freq: {1:3, 2:2, 3:1}
Buckets: [3]→[1], [2]→[2], [1]→[3]
Scan from top: bucket[3]=[1] (take 1), bucket[2]=[2] (take 2)
Result: [1,2] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort by frequency | O(N log N) | Varies | Baseline |
| HashMap + Bucket Sort | O(N) | O(N) | Bucket sort: create buckets indexed by frequency. Bucket[f]  |

**Recommended Solution:** HashMap + Bucket Sort — O(N) time, O(N) space.

**Key Insights:**
1. **Bucket sort = O(N):** Better than heap's O(N log K) when K is large
2. **Max frequency ≤ N:** So bucket array size is bounded by N
3. **Heap alternative:** O(N log K) — better when K << N
4. **FAANG classic:** Tests multiple approaches — bucket sort is the optimal trick

<br>
<br>

---

```code```
