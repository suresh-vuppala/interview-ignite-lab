Count paths summing to target. Path can start at any node but must go downward.

<br>

---

## Solution 1: Brute Force — DFS from Every Node

For each node, count paths starting from it with target sum.

### Time: O(n²) — DFS from each node
### Space: O(h)

<br>

---

## Solution 2: Prefix Sum + Hash Map (Optimal)

**Intuition:** Like subarray sum = k. Track prefix sum from root. If prefixSum - target exists in map, there's a valid path.

**Algorithm:**
1. DFS tracking running prefix sum
2. HashMap: prefixSum → count of nodes with that sum
3. At each node: count += map[prefixSum - target]
4. Add current prefixSum to map, recurse, then remove (backtrack)

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS from every node | O(n²) | O(h) | Check all starting points |
| Prefix Sum + Map | O(n) | O(h) | Subarray sum technique on tree |

<br>
<br>

---

```code```
