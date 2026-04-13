Count subarrays with sum divisible by K.

<br>

> nums=[4,5,0,-2,-3,1], k=5 → 7
>
> **Key insight:** Prefix sum mod K. Count pairs with same remainder. Answer = sum of C(count,2) for each remainder.

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

## Solution 1: Check all subarrays

### Time Complexity: O(N²)

> **Drawback:**
> Quadratic.

> **Key Insight for Improvement:**
> Prefix mod K: same remainder means difference divisible by K. Count pairs with same remainder.

<br>

---

## Solution 2: Prefix Mod + Count Pairs (Optimal)

**Intuition:** Prefix sum mod K. Count pairs with same remainder. Answer = sum of C(count,2) for each remainder.

**Algorithm:**
1. prefix=0, count_map={0:1}
2. For each num: prefix = ((prefix+num)%K+K)%K (handle negative)
3. count_map[prefix]++
4. Answer = sum(c*(c-1)/2 for c in count_map.values())

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[4,5,0,-2,-3,1] k=5: prefix%5: 4,4,4,2,4,0
counts: {0:2,4:4,2:1} → C(2,2)+C(4,2)+C(1,2)=1+6+0=7 ✓
```

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all subarrays | O(N²) | Varies | Baseline |
| Prefix Mod + Count Pairs | O(N) | O(K) | Optimal approach |

**Recommended Solution:** Prefix Mod + Count Pairs — O(N) time.

**Key Insights:**
1. **Same remainder = divisible difference:** (p[j]-p[i])%K==0 iff p[j]%K==p[i]%K
2. **Handle negative mod:** ((prefix%K)+K)%K ensures positive
3. **Count pairs:** C(n,2) = n*(n-1)/2 for each remainder group

<br><br>

---

```code```
