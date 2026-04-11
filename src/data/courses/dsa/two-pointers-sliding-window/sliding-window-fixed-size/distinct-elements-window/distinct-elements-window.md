Given an array of integers and a window size k, find the count of distinct elements in every window of size k.

<br>

> Input:
> arr = [1, 2, 1, 3, 4, 2, 3], k = 4

> Output:
> [3, 4, 4, 3]

> Explanation:
> Window [1,2,1,3] → 3 distinct elements (1,2,3)
> Window [2,1,3,4] → 4 distinct elements (1,2,3,4)
> Window [1,3,4,2] → 4 distinct elements (1,2,3,4)
> Window [3,4,2,3] → 3 distinct elements (2,3,4)
> 
> **Key insight:** Use HashMap to track frequency of elements in current window, count keys with frequency > 0.

<br>



---

## Constraints

- `1 ≤ k ≤ nums.length ≤ 10⁵`
- `1 ≤ nums[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Each window has exactly 1 distinct element
2. **k = n:** Count distinct in entire array
3. **All same elements:** Every window has 1 distinct element
4. **All unique elements:** Every window of size k has k distinct elements
5. **Single element array, k=1:** Return [1]
6. **Large k with repeats:** Frequency map must track add/remove correctly

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each window of size k, create a set and count distinct elements by adding all elements to the set.

**Algorithm:**
1. For each starting index i (0 to n-k):
   - Create empty set
   - For j from i to i+k-1:
     - Add arr[j] to set
   - Add set size to result
2. Return result array

### Time Complexity: O(N × K)
**Why?**
- Outer loop: (N - K + 1) windows ≈ N iterations
- Inner loop: K elements per window
- Set operations: O(1) average
- Total: N × K

**Detailed breakdown:**
- Number of windows: N - K + 1
- Each window: process K elements
- Total: (N - K + 1) × K ≈ N × K
- Example: Array size 1000, K=100 → 100,000 operations

### Space Complexity: O(K)
**Why?**
- Set stores at most K elements per window
- Result array: O(N - K + 1) ≈ O(N)
- Total: O(K + N) ≈ O(N)

> **Key Insight for Improvement:**
> We're rebuilding the set for each window from scratch. Can we reuse information from previous window? Yes! Use sliding window - remove leftmost element, add new rightmost element.

<br>

---

## Solution 2: Sliding Window with HashMap

**Intuition:**
Maintain a HashMap with element frequencies in current window. When sliding, remove one element from left and add one from right. Count of keys in map = distinct elements.

**Algorithm:**
1. Create HashMap and result array
2. Build first window (0 to k-1):
   - Add each element to map with frequency
3. Add map size to result
4. For i from k to n-1:
   - Remove arr[i-k] from window (decrease frequency, remove if 0)
   - Add arr[i] to window (increase frequency)
   - Add map size to result
5. Return result

### Time Complexity: O(N)
**Why?**
- Build first window: O(K)
- Slide window: (N - K) iterations
- Each iteration: O(1) map operations
- Total: K + (N - K) = O(N)

**Detailed breakdown:**
- First window: K operations
- Remaining windows: N - K operations
- Each operation: O(1) average
- Total: N operations
- Example: Array size 1000 → 1000 operations

**Improvement:** From O(N × K) to O(N)
- Example: Array size 1000, K=100
- Brute force: 100,000 operations
- Sliding window: 1000 operations (100× faster!)

### Space Complexity: O(K)
**Why?**
- HashMap stores at most K distinct elements
- Result array: O(N - K + 1) ≈ O(N)
- Total: O(K + N) ≈ O(N)

**Why this works:**
- Map always represents current window
- Map size = number of distinct elements
- Sliding maintains this invariant efficiently

> **Key Insight for Improvement:**
> For very large K or when K ≈ N, we can optimize space slightly, but O(N) time is optimal since we must process each element at least once.

<br>

---

## Solution 3: Optimized Sliding Window

**Intuition:**
Same as Solution 2 but with cleaner code structure and edge case handling.

**Algorithm:**
1. Handle edge cases (k > n, k <= 0)
2. Use HashMap to track frequencies
3. Process first window
4. Slide window and update counts
5. Return result

### Time Complexity: O(N)
**Why?**
- Same as Solution 2
- Single pass through array
- Constant time operations per element

### Space Complexity: O(K)
**Why?**
- HashMap: at most K distinct elements
- Result array: O(N)
- Total: O(N + K) ≈ O(N)

**Why this is optimal:**
- Must process each element: O(N) time minimum
- Must store result: O(N) space minimum
- Cannot do better than O(N) time

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×K) | O(N) | Baseline - rebuild set each window |
| Sliding Window | O(N) | O(N) | Reuse previous window - add/remove one element |
| Optimized | O(N) | O(N) | Clean code with edge cases |

**Recommended Solution:** Sliding Window with HashMap (Solution 2) - O(N) time, O(N) space.

**Key Insights:**
1. **Brute → Sliding Window:** Reuse previous window → avoid rebuilding
2. **HashMap frequency tracking:** Efficient add/remove with O(1) operations
3. **Map size = distinct count:** Direct way to count distinct elements


<br>
<br>

---

```code```
