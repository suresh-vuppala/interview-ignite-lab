Answer range sum queries [l,r] in O(1) after O(N) preprocessing.

<br>

> nums=[1,2,3,4,5], sumRange(1,3)=9
>
> **Key insight:** Build prefix sum array. sum(l,r) = prefix[r+1] - prefix[l]. O(N) preprocess, O(1) per query.

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

## Solution 1: Sum each query

### Time Complexity: O(N) per query

> **Drawback:**
> Recomputing sum for every query wastes work.

> **Key Insight for Improvement:**
> Prefix sum: prefix[i] = sum of nums[0..i-1]. Query = prefix[r+1] - prefix[l]. O(1) per query.

<br>

---

## Solution 2: Prefix Sum Array (Optimal)

**Intuition:** Build prefix sum array. sum(l,r) = prefix[r+1] - prefix[l]. O(N) preprocess, O(1) per query.

**Algorithm:**
1. Build: prefix[0]=0, prefix[i]=prefix[i-1]+nums[i-1]
2. Query: sumRange(l,r) = prefix[r+1] - prefix[l]

### Time Complexity: O(1) per query, O(N) build
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
nums=[1,2,3,4,5] → prefix=[0,1,3,6,10,15]
sumRange(1,3) = prefix[4]-prefix[1] = 10-1 = 9 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sum each query | O(N) per query | Varies | Baseline |
| Prefix Sum Array | O(1) per query, O(N) build | O(N) | Optimal approach |

**Recommended Solution:** Prefix Sum Array — O(1) per query, O(N) build time.

**Key Insights:**
1. **Prefix[r+1]-prefix[l]:** Cancels out elements before l
2. **One-indexed prefix:** prefix[0]=0 handles l=0 cleanly
3. **Foundation:** Used in subarray sum = K, 2D prefix, and many more

<br><br>

---

```code```
