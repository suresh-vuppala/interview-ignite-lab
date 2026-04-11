Given an array of non-negative integers where each element represents your maximum jump length at that position, find the minimum number of jumps to reach the last index. You can assume you can always reach the last index.

<br>

> Input:
> nums = [2, 3, 1, 1, 4]

> Output:
> 2

> Explanation:
> Minimum jumps path: 0 → 1 → 4
> 
> Jump process:
> - Jump 1: From index 0 to index 1 (can reach up to index 2)
> - Jump 2: From index 1 to index 4 (can reach up to index 4)
> 
> Detailed analysis:
> - At index 0: can reach indices 1-2, choose to explore all
> - From indices 1-2: can reach up to index 4 (end)
> - Total jumps: 2

<br>


---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `0 ≤ nums[i] ≤ 1000`
- `Guaranteed to reach the last index`

<br>

---

## All Possible Edge Cases

1. **Single element:** 0 jumps needed
2. **Can reach end in one jump:** Return 1
3. **All ones:** Need n-1 jumps
4. **First element covers entire array:** Return 1
5. **Two elements:** Return 1
6. **Large first element:** Might reach end directly

<br>

---

## Solution: Greedy BFS-like Approach

Approach:
1. Track current jump's reach and next jump's reach
2. When reaching end of current jump range, increment jump count
3. Update current reach to next reach
4. Continue until reaching last index

**Think of it as BFS levels:** Each jump represents a level, find minimum levels to reach end.



<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Iterate through array once (up to second-to-last element)
- For each index:
  - Update next reach: O(1)
  - Check if reached current boundary: O(1)
  - Increment jump counter: O(1)
- Total: n × O(1) = O(n)

**BFS-like without queue:**
- Traditional BFS would use queue: O(n) space
- This approach simulates BFS levels with two pointers
- Each "level" represents positions reachable with same number of jumps

**Why this works:**
- Greedy choice: Always explore furthest reachable position in current jump
- When we exhaust current jump range, we must make another jump
- Next jump can reach anywhere within next reach range
- This guarantees minimum jumps

**Comparison with DP:**
- DP approach: O(n²) time, O(n) space
- Greedy approach: O(n) time, O(1) space
- Greedy is optimal because we only need minimum jumps, not all paths

> **Time Complexity:** O(n) - single pass through array
> **Space Complexity:** O(1) - only a few variables needed

<br>
<br>

---

---

```code```
