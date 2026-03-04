Find the maximum sum of any contiguous subarray of size k.

<br>

> Input:
> arr = [2, 1, 5, 1, 3, 2], k = 3

> Output:
> 9

> Explanation:
> All subarrays of size 3:
> - [2, 1, 5]: sum = 8
> - [1, 5, 1]: sum = 7
> - [5, 1, 3]: sum = 9 (maximum)
> - [1, 3, 2]: sum = 6
> 
> Sliding window process:
> - Window [2,1,5]: sum = 8, max = 8
> - Slide: remove 2, add 1 → [1,5,1]: sum = 8-2+1 = 7, max = 8
> - Slide: remove 1, add 3 → [5,1,3]: sum = 7-1+3 = 9, max = 9
> - Slide: remove 5, add 2 → [1,3,2]: sum = 9-5+2 = 6, max = 9

<br>

---

## Solution: Fixed-Size Sliding Window

Use sliding window to avoid recalculating sum:
1. **Initialize**: Calculate sum of first k elements
2. **Slide window**: 
   - Remove leftmost element from sum
   - Add new rightmost element to sum
   - Update maximum
3. Repeat for all windows

**Key insight:** Reuse previous sum instead of recalculating from scratch.

```code```

<br>

### Time Complexity Analysis

**Sliding Window: O(n)**
- Calculate first window sum: O(k)
- Slide window (n-k) times:
  - Remove left element: O(1)
  - Add right element: O(1)
  - Update max: O(1)
- Total: O(k) + (n-k) × O(1) = O(n)

**Why not O(n × k)?**
- Brute force: For each of (n-k+1) windows, calculate sum in O(k) = O(n × k)
- Sliding window: Calculate once, then update in O(1) = O(n)
- Example: n=1000, k=100 → Brute: 100,000 ops vs Sliding: 1,000 ops

**Space Complexity: O(1)**
- Only store: current sum, max sum, loop variables
- No extra arrays or data structures
- In-place algorithm

**Sliding window technique:**
- Fixed size window moves through array
- Maintain window state (sum) incrementally
- Remove outgoing element, add incoming element
- Avoids redundant recalculation

**When to use sliding window?**
- Fixed-size subarray problems
- Need to process all windows
- Can update state incrementally (sum, product, etc.)
- Optimization from O(n × k) to O(n)

**Comparison:**
- Brute force: Recalculate sum for each window
- Sliding window: Update sum incrementally
- Prefix sum: Can answer queries but needs O(n) space
- Sliding window: Best for this problem

> **Time Complexity:** O(n) - single pass with sliding window
> **Space Complexity:** O(1) - only a few variables

<br>
<br>

---