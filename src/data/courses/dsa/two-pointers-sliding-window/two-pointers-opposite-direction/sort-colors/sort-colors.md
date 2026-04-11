Given an array with n objects colored red (0), white (1), or blue (2), sort them in-place so that objects of the same color are adjacent in order red, white, blue.

<br>

> Input:
> nums = [2, 0, 2, 1, 1, 0]

> Output:
> [0, 0, 1, 1, 2, 2]

> Explanation:
> After sorting: all 0s first, then 1s, then 2s.
> 
> **Key insight:** Dutch National Flag — three pointers partition the array into three regions in a single pass: [0..lo-1]=0s, [lo..mid-1]=1s, [hi+1..n-1]=2s, [mid..hi]=unknown.

<br>



---

## Constraints

- `1 ≤ n ≤ 300`
- `nums[i]` is 0, 1, or 2

<br>

---

## All Possible Edge Cases

1. **Already sorted:** [0,0,1,1,2,2] → unchanged
2. **Reverse sorted:** [2,2,1,1,0,0]
3. **All same:** [1,1,1] → unchanged
4. **Only two colors:** [0,2,0,2]
5. **Single element:** [1]

<br>

---

## Solution 1: Counting Sort — Two Pass

**Intuition:**
Count occurrences of 0s, 1s, 2s. Overwrite the array in order.

**Algorithm:**
1. Count: c0, c1, c2
2. Fill nums[0..c0-1] with 0
3. Fill nums[c0..c0+c1-1] with 1
4. Fill remaining with 2

### Time Complexity: O(N)
**Why?**
- Count pass: O(N)
- Fill pass: O(N)
- Total: 2N = O(N) but requires two passes

**Detailed breakdown:**
- N = 300 → 600 operations (two passes)

### Space Complexity: O(1)
**Why?**
- Only 3 count variables

> **Drawback:**
> Requires two passes over the array. The first pass only counts, then the second rebuilds. Can we sort in a single pass?

> **Key Insight for Improvement:**
> Dutch National Flag algorithm: three pointers (lo, mid, hi) partition in one pass. When mid sees 0 → swap to lo, when mid sees 2 → swap to hi, when mid sees 1 → skip. Each element examined exactly once.

<br>

---

## Solution 2: Dutch National Flag — Single Pass (Optimal)

**Intuition:**
Three pointers maintain three regions:
- [0..lo-1] = all 0s
- [lo..mid-1] = all 1s
- [mid..hi] = unprocessed
- [hi+1..n-1] = all 2s

**Algorithm:**
1. lo = 0, mid = 0, hi = n-1
2. While mid ≤ hi:
   - If nums[mid] == 0 → swap(lo, mid), lo++, mid++
   - If nums[mid] == 1 → mid++ (already in correct zone)
   - If nums[mid] == 2 → swap(mid, hi), hi-- (DON'T advance mid — swapped element is unknown)

### Time Complexity: O(N)
**Why?**
- Each iteration: either mid++ or hi--
- Total: at most N iterations (mid and hi meet)
- Single pass

**Detailed breakdown:**
- N = 300 → at most 300 iterations with at most 300 swaps

**Example walkthrough:**
```
nums = [2, 0, 2, 1, 1, 0]
lo=0, mid=0, hi=5

mid=0: nums[0]=2 → swap(0,5) → [0,0,2,1,1,2], hi=4
mid=0: nums[0]=0 → swap(0,0) → [0,0,2,1,1,2], lo=1, mid=1
mid=1: nums[1]=0 → swap(1,1) → [0,0,2,1,1,2], lo=2, mid=2
mid=2: nums[2]=2 → swap(2,4) → [0,0,1,1,2,2], hi=3
mid=2: nums[2]=1 → mid=3
mid=3: nums[3]=1 → mid=4
mid=4 > hi=3 → stop

Result: [0, 0, 1, 1, 2, 2] ✓
```

**Why not advance mid after swap with hi?**
- The element swapped FROM hi is unknown (could be 0, 1, or 2)
- Must examine it in the next iteration
- After swap with lo, the element coming from lo is always ≤ 1 (already processed), so safe to advance

### Space Complexity: O(1)
**Why?**
- Only three pointer variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Counting Sort | O(N) | O(1) | Two passes: count + fill |
| Dutch National Flag | O(N) | O(1) | Single pass, three-way partition |

**Recommended Solution:** Dutch National Flag (Solution 2) — O(N) single pass, O(1) space.

**Key Insights:**
1. **Three regions:** lo/mid/hi partition into 0s/1s/unknown/2s
2. **Don't advance mid after hi swap:** The swapped element is unknown
3. **Generalization:** This technique works for any 3-way partition problem


<br>
<br>

---

```code```
