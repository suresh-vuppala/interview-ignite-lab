Can you reach the last index? Each element = maximum jump length from that position.

<br>

> nums=[2,3,1,1,4] → true
>
> **Key insight:** Track farthest reachable index. At each position, update max reach. If current position > max reach → unreachable.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Brute Force

### Time Complexity: O(N²)

> **Drawback:**
> Exploring all paths from each index is quadratic.

> **Key Insight for Improvement:**
> Greedy: maxReach = max(maxReach, i + nums[i]). If i > maxReach → false. If maxReach ≥ N-1 → true.

<br>

---

## Solution 2: Greedy Max Reach (Optimal)

**Intuition:** Track farthest reachable index. At each position, update max reach. If current position > max reach → unreachable.

**Algorithm:**
1. maxReach = 0
2. For i = 0 to N-1:
   - If i > maxReach → return false (can't reach here)
   - maxReach = max(maxReach, i + nums[i])
   - If maxReach ≥ N-1 → return true

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
nums=[2,3,1,1,4]
i=0: maxReach=max(0,0+2)=2
i=1: maxReach=max(2,1+3)=4 ≥ 4 → true ✓

nums=[3,2,1,0,4]
i=0: reach=3, i=1: reach=3, i=2: reach=3, i=3: reach=3
i=4: 4>3 → false ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | Varies | Baseline |
| Greedy Max Reach | O(N) | O(1) | Greedy: maxReach = max(maxReach, i + nums[i]). If i > maxRea |

**Recommended Solution:** Greedy Max Reach — O(N) time, O(1) space.

**Key Insights:**
1. **Single variable:** maxReach tracks the frontier
2. **i > maxReach = dead end:** Position unreachable
3. **FAANG classic:** Simple greedy with clean logic

<br>
<br>

---

```code```
