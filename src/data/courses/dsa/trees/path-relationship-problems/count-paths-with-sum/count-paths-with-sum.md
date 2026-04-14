Count paths that sum to a target value. Paths don't need to start at root or end at leaf, but must go downward (parent to child).

<br>

> Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], target = 8
> Output: 3 (paths: 5→3, 5→2→1, -3→11)
> **Key insight:** Use prefix sums + hash map (like subarray sum equals K). For each node, check if (currentSum - target) exists in prefix sum map.

<br>

---

## Constraints
- `0 ≤ N ≤ 1000`, `-10⁹ ≤ Node.val ≤ 10⁹`

<br>

---

## Solution 1: Brute Force — Start DFS from Every Node

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

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
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Prefix Sum + Hash Map (Optimal)

**Algorithm:**
1. DFS with running prefix sum. Map stores prefix_sum → count.
2. At each node: count += map[currentSum - target]
3. Add currentSum to map before recursing children
4. Remove currentSum from map after recursing (backtrack)

### Time Complexity: O(N)
**Why?** Visit each node once. Map operations O(1).

**Detailed breakdown:** N = 1000 → 1000 operations

### Space Complexity: O(H) for map + recursion

> **Drawback:** None — O(N) is optimal.

> **Key Insight for Improvement:** Initialize map with {0: 1} to handle paths starting from root.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(H) | DFS from every node |
| Prefix Sum + Map | O(N) | O(H) | Same trick as subarray sum = K |

**Key Insights:**
1. **Prefix sum on paths:** currentSum - target = prefixSum at path start
2. **Backtrack the map:** Remove currentSum after recursing children
3. **Initialize {0: 1}:** Handles paths starting at root

<br><br>

---

```code```
