Given an array of non-negative integers where each element represents your maximum jump length at that position, determine if you can reach the last index.

<br>

> Input:
> nums = [2, 3, 1, 1, 4]

> Output:
> true

> Explanation:
> Starting at index 0:
> - Index 0: can jump 1 or 2 steps, max reach = 0 + 2 = 2
> - Index 1: can jump 1, 2, or 3 steps, max reach = 1 + 3 = 4
> - Index 2: can jump 1 step, max reach = max(4, 2+1) = 4
> - Index 3: can jump 1 step, max reach = max(4, 3+1) = 4
> - Index 4: reached! (4 ≥ 4)
> 
> Path: 0 → 1 → 4 (or other valid paths exist)

<br>

> Input:
> nums = [3, 2, 1, 0, 4]

> Output:
> false

> Explanation:
> - Index 0: max reach = 0 + 3 = 3
> - Index 1: max reach = max(3, 1+2) = 3
> - Index 2: max reach = max(3, 2+1) = 3
> - Index 3: max reach = max(3, 3+0) = 3 (stuck at index 3)
> - Cannot reach index 4

<br>


---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `0 ≤ nums[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Single element:** Already at end → true
2. **Zero at start:** [0,...] → false (stuck at start)
3. **All ones:** Always reachable
4. **Zero in middle but reachable by jumping over:** [2,0,1] → true
5. **All zeros except first:** [3,0,0,0] → depends on first element
6. **Large jumps:** Single jump covers entire array
7. **Last element is zero:** Doesn't matter — we just need to reach it

<br>

---

## Solution: Greedy Maximum Reach

Approach:
1. Track maximum reachable index while iterating
2. For each position, update max reach = max(current max, i + nums[i])
3. If current index > max reach, return false
4. If max reach ≥ last index, return true

**Greedy choice:** Always track furthest reachable position.



<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Iterate through array once
- For each index:
  - Check if reachable: O(1)
  - Update max reach: O(1)
  - Check if reached end: O(1)
- Total: n × O(1) = O(n)

**No backtracking or recursion:**
- Greedy approach processes each element once
- No need to explore all possible paths
- Simply track furthest reachable position

**Why this works:**
- If we can reach position i, we can reach all positions ≤ i
- From position i, we can reach any position up to i + nums[i]
- Maximum reach is monotonically non-decreasing
- If max reach ≥ last index at any point, we can reach the end

> **Time Complexity:** O(n) - single pass through array
> **Space Complexity:** O(1) - only one variable for max reach

<br>
<br>

---

---

```code```
