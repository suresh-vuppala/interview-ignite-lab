Count subarrays with sum equal to K.

<br>

> nums=[1,1,1], k=2 → 2
>
> **Key insight:** Prefix sum + hash map. If (prefixSum - K) exists in map with count C → C subarrays ending here sum to K.

<br>

---

## Constraints
- 1 ≤ N ≤ 2 × 10⁴
- -1000 ≤ nums[i] ≤ 1000
- -10⁷ ≤ K ≤ 10⁷

<br>

---

## All Possible Edge Cases
1. **K = 0:** count subarrays summing to zero
2. **Negative numbers:** sliding window won't work
3. **Single element equals K**
4. **All elements same**

<br>

---

## Solution 1: Check all subarrays

**Intuition:**
The most straightforward approach. Two nested loops to check all subarrays.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Two nested loops to check all subarrays.

> **Key Insight for Improvement:**
> Prefix sum + hash map: map stores prefix_sum → count. For each prefix, check if (prefix-K) is in map.

<br>

---

## Solution 2: Prefix Sum + HashMap (Optimal)

**Intuition:** Prefix sum + hash map. If (prefixSum - K) exists in map with count C → C subarrays ending here sum to K.

**Algorithm:**
1. map = {0: 1}, prefix = 0, count = 0
2. For each num:
   - prefix += num
   - count += map.get(prefix - K, 0)
   - map[prefix] = map.get(prefix, 0) + 1
3. Return count

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
nums=[1,1,1] k=2: prefix=0,map={0:1}
prefix=1: 1-2=-1 not in map. map={0:1,1:1}
prefix=2: 2-2=0 in map(1) → count=1. map={0:1,1:1,2:1}
prefix=3: 3-2=1 in map(1) → count=2 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all subarrays | O(N²) | Varies | Baseline |
| Prefix Sum + HashMap | O(N) | O(N) | Optimal approach |

**Recommended Solution:** Prefix Sum + HashMap — O(N) time.

**Key Insights:**
1. **prefix - K in map:** Means some earlier prefix + K = current prefix
2. **Initialize {0:1}:** Handles subarrays starting from index 0
3. **FAANG top-10:** Extremely common prefix sum problem

<br><br>

---

```code```
