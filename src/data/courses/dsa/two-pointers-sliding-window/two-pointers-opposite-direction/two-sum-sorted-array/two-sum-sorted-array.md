Find two numbers in a sorted array that add up to a target value. Return their indices.

<br>

> Input:
> numbers = [2, 7, 11, 15], target = 9

> Output:
> [0, 1]

> Explanation:
> Two pointer process:
> - left=0 (2), right=3 (15): sum = 2+15 = 17 > 9, move right left
> - left=0 (2), right=2 (11): sum = 2+11 = 13 > 9, move right left
> - left=0 (2), right=1 (7): sum = 2+7 = 9 = target ✓
> - Return [0, 1]

<br>

> Input:
> numbers = [1, 3, 4, 5, 7, 11], target = 9

> Output:
> [2, 3]

> Explanation:
> - left=0 (1), right=5 (11): sum = 12 > 9, right--
> - left=0 (1), right=4 (7): sum = 8 < 9, left++
> - left=1 (3), right=4 (7): sum = 10 > 9, right--
> - left=1 (3), right=3 (5): sum = 8 < 9, left++
> - left=2 (4), right=3 (5): sum = 9 = target ✓
> - Return [2, 3]

<br>

---

## Solution: Two Pointers (Opposite Direction)

Use two pointers starting from both ends:
1. **Initialize**: left = 0, right = n-1
2. **Calculate sum**: sum = arr[left] + arr[right]
3. **Decision**:
   - If sum == target: found, return indices
   - If sum < target: need larger sum, left++
   - If sum > target: need smaller sum, right--
4. Repeat until found or pointers meet

**Key insight:** Sorted array allows greedy pointer movement based on sum comparison.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Two pointers start at ends
- Each iteration moves one pointer: left++ or right--
- Maximum iterations = n (when pointers meet)
- Each iteration: O(1) operations (add, compare, move)
- Total: n × O(1) = O(n)

**Why not O(n²)?**
- Brute force: Check all pairs O(n²)
- Two pointers: Each element visited at most once O(n)
- Sorted property enables greedy decisions

**Space Complexity: O(1)**
- Only two pointer variables
- No extra data structures
- In-place algorithm

**Why does this work?**
- Array is sorted: arr[left] ≤ arr[right]
- If sum < target: arr[left] too small, must increase left
- If sum > target: arr[right] too large, must decrease right
- Greedy choice is always correct due to sorted property

**Comparison with hash map approach:**
- Hash map: O(n) time, O(n) space - works for unsorted
- Two pointers: O(n) time, O(1) space - requires sorted
- Two pointers better when array is sorted

**Why opposite direction?**
- Need to adjust sum up or down
- Left pointer increases sum (move to larger)
- Right pointer decreases sum (move to smaller)
- Same direction can't make both adjustments

> **Time Complexity:** O(n) - single pass with two pointers
> **Space Complexity:** O(1) - only pointer variables

<br>
<br>

---