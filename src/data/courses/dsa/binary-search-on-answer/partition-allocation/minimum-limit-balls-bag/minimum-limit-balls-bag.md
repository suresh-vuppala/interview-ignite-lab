Minimize the max balls in any bag after at most K operations (each splits one bag into two).

<br>

> nums=[9], maxOps=2 → 3 (split 9→[3,3,3] with 2 ops)
>
> **Key insight:** Binary search on max balls. For each candidate max, count operations needed: each bag needs ceil(balls/max)-1 splits.

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

## Solution 1: Try all values 1..max

### Time Complexity: O(max × N)

> **Drawback:**
> Linear search in value space is slow.

> **Key Insight for Improvement:**
> BS on answer: lo=1, hi=max(nums). Operations for bag = ceil(n/mid)-1. Total ops ≤ K → feasible.

<br>

---

## Solution 2: BS on Answer (Optimal)

**Intuition:** Binary search on max balls. For each candidate max, count operations needed: each bag needs ceil(balls/max)-1 splits.

**Algorithm:**
1. lo=1, hi=max(nums)
2. For each mid: ops = sum(ceil(n/mid)-1 for n in nums)
3. If ops ≤ K → ans=mid, hi=mid-1
4. Else → lo=mid+1

### Time Complexity: O(N log M)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
nums=[9] K=2: lo=1,hi=9
mid=5: ceil(9/5)-1=1 op ≤ 2 → ans=5, hi=4
mid=2: ceil(9/2)-1=4 ops > 2 → lo=3
mid=3: ceil(9/3)-1=2 ops ≤ 2 → ans=3 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all values 1..max | O(max × N) | Varies | Baseline |
| BS on Answer | O(N log M) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer — O(N log M) time.

**Key Insights:**
1. **ceil(n/mid)-1 = splits needed:** Key formula
2. **Binary search finds minimum feasible max**
3. **Monotonic:** Larger max → fewer ops needed

<br><br>

---

```code```
