Check if subarray of length ≥ 2 exists with sum divisible by K.

<br>

> nums=[23,2,4,6,7], k=6 → true (subarray [2,4]→sum=6)
>
> **Key insight:** Prefix sum mod K + hash map. If same remainder seen before with gap ≥ 2 → true.

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
> Quadratic pair checking.

> **Key Insight for Improvement:**
> Prefix mod K: if prefix[i]%K == prefix[j]%K and j-i ≥ 2 → subarray sum divisible by K.

<br>

---

## Solution 2: Prefix Mod + HashMap (Optimal)

**Intuition:** Prefix sum mod K + hash map. If same remainder seen before with gap ≥ 2 → true.

**Algorithm:**
1. map = {0: -1}, prefix = 0
2. For each i:
   - prefix = (prefix + nums[i]) % K
   - If prefix in map and i - map[prefix] ≥ 2 → true
   - Else if prefix not in map: map[prefix] = i

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[23,2,4,6,7] k=6: prefix%6: 5,1,5,5,0
i=0: 5→map={0:-1,5:0}
i=1: 1→map[1]=1
i=2: 5 in map, 2-0=2≥2 → true ✓ (subarray [2,4]=6)
```

### Space Complexity: O(min(N,K))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all subarrays | O(N²) | Varies | Baseline |
| Prefix Mod + HashMap | O(N) | O(min(N,K)) | Optimal approach |

**Recommended Solution:** Prefix Mod + HashMap — O(N) time.

**Key Insights:**
1. **Same mod = divisible difference:** (prefix[j]-prefix[i]) % K == 0
2. **Gap ≥ 2:** Length constraint — store first occurrence only
3. **Initialize {0: -1}:** Handles subarrays starting at index 0

<br><br>

---

```code```
