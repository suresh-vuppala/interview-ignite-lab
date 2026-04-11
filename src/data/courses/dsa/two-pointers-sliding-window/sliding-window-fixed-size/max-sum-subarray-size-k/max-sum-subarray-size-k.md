Find the maximum sum of any contiguous subarray of size k.

<br>

> Input:
> nums = [2, 1, 5, 1, 3, 2], k = 3

> Output:
> 9

> Explanation:
> Subarray [5, 1, 3] has sum = 9, which is the maximum among all windows of size 3.
> 
> **Key insight:** Same sliding window pattern — maintain running sum, track maximum across all windows.

<br>



---

## Constraints

- `1 ≤ k ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **k = n:** Only one window — return total sum
2. **All negative:** Maximum is the least negative window
3. **All same:** Every window has the same sum

<br>

---

## Solution 1: Brute Force — Sum Each Window

### Time Complexity: O(N × K)
### Space Complexity: O(1)

```code```

> **Drawback:**
> Recomputing K additions per window. Same redundancy as subarray sum — adjacent windows differ by only 2 elements.

> **Key Insight for Improvement:**
> Sliding window with running sum. Compute first window, then slide: sum += nums[i] - nums[i-k]. Track max across all windows.

<br>

---

## Solution 2: Sliding Window — Running Max (Optimal)

**Intuition:**
Same as fixed-size sum, but track the maximum sum seen across all windows.

**Algorithm:**
1. sum = sum of first K elements, maxSum = sum
2. For i = K to N-1: sum += nums[i] - nums[i-K], maxSum = max(maxSum, sum)
3. Return maxSum

### Time Complexity: O(N)
**Why?**
- Single pass after initial window
- O(1) per slide

**Detailed breakdown:**
- N = 100,000 → 100,000 operations vs brute's N×K

**Example walkthrough:**
```
nums = [2, 1, 5, 1, 3, 2], k = 3

Window [2,1,5]: sum=8, max=8
Slide: sum=8-2+1=7, max=8
Slide: sum=7-1+3=9, max=9
Slide: sum=9-5+2=6, max=9

Result: 9 ✓
```

### Space Complexity: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×K) | O(1) | Resum each window |
| Sliding Window | O(N) | O(1) | Running sum + max tracking |

**Recommended Solution:** Sliding Window — O(N) time, O(1) space.

**Key Insights:**
1. **Same pattern:** Fixed-size window with running sum
2. **Track max:** Update maximum after each slide
3. **Single pass:** Process all windows with one iteration


<br>
<br>

---

```code```
