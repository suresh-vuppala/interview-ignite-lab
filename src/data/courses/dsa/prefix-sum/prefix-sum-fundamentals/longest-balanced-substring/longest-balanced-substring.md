Find longest substring with equal number of 0s and 1s.

<br>

> nums=[0,1,0] → 2 ([0,1])
>
> **Key insight:** Map 0→-1. Find longest subarray with sum 0 using prefix sum + hash map (first occurrence).

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

## Solution 1: Check all substrings

### Time Complexity: O(N²)

> **Drawback:**
> Quadratic.

> **Key Insight for Improvement:**
> 0→-1 transform: equal 0s and 1s = sum 0. Longest zero-sum subarray via prefix + first occurrence map.

<br>

---

## Solution 2: Prefix Sum + HashMap (Optimal)

**Intuition:** Map 0→-1. Find longest subarray with sum 0 using prefix sum + hash map (first occurrence).

**Algorithm:**
1. Replace 0 with -1
2. prefix=0, map={0:-1}
3. For each i: prefix+=nums[i]
   - If prefix in map: length = i - map[prefix] → track max
   - Else: map[prefix] = i

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[0,1,0]→[-1,1,-1]: prefix: -1,0,-1
i=0: -1→map={0:-1,-1:0}
i=1: 0 in map(-1)→len=1-(-1)=2 ✓
i=2: -1 in map(0)→len=2-0=2
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all substrings | O(N²) | Varies | Baseline |
| Prefix Sum + HashMap | O(N) | O(N) | Optimal approach |

**Recommended Solution:** Prefix Sum + HashMap — O(N) time.

**Key Insights:**
1. **0→-1 transform:** Equal 0s and 1s becomes sum=0
2. **Same prefix = zero-sum between:** map stores first occurrence
3. **Initialize {0:-1}:** Handles subarrays starting at index 0

<br><br>

---

```code```
