Split array into K subarrays minimizing the maximum subarray sum.

<br>

> nums=[7,2,5,10,8], K=2 → 18 ([7,2,5] sum=14, [10,8] sum=18)
>
> **Key insight:** Binary search on maximum sum. Greedy: assign elements until sum exceeds limit, start new subarray.

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

## Solution 1: Try all K-1 split points

### Time Complexity: O(C(N,K))

> **Drawback:**
> Combinatorial — infeasible for large N.

> **Key Insight for Improvement:**
> BS on max sum: lo=max(nums), hi=sum(nums). Greedy count of subarrays within limit.

<br>

---

## Solution 2: BS on Answer (Optimal)

**Intuition:** Binary search on maximum sum. Greedy: assign elements until sum exceeds limit, start new subarray.

**Algorithm:**
1. lo=max(nums), hi=sum(nums)
2. Binary search: canSplit(mid,K) → greedily count subarrays ≤ mid
3. If count ≤ K → feasible, try smaller
4. Else → infeasible, try larger

### Time Complexity: O(N log S)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[7,2,5,10,8] K=2: lo=10, hi=32
mid=21: [7,2,5,10]=24>21→split → [7,2,5]=14,[10,8]=18 → 2 groups OK
mid=15: [7,2,5]=14,[10]=10,[8]=8 → 3 groups > 2 → too small
→ ans=18
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all K-1 split points | O(C(N,K)) | Varies | Baseline |
| BS on Answer | O(N log S) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer — O(N log S) time.

**Key Insights:**
1. **Same BS-on-answer family:** All minimize-the-maximum problems
2. **Greedy assigns greedily:** Fill current subarray until limit exceeded
3. **LeetCode 410:** Hard — but with the pattern, straightforward

<br><br>

---

```code```
