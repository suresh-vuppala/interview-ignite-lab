Find tree diameter (longest path between any two nodes) using DP.

<br>

> Tree with edges → diameter = longest path
>
> **Key insight:** For each node: diameter through it = two longest paths down to leaves. Track global max.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: BFS from every node

### Time Complexity: O(N²)

> **Drawback:**
> N BFS runs.

> **Key Insight for Improvement:**
> Single DFS: at each node, track two longest child depths. Diameter candidate = depth1 + depth2. Global max = answer.

<br>

---

## Solution 2: DFS Max Two Depths (Optimal)

**Intuition:** For each node: diameter through it = two longest paths down to leaves. Track global max.

**Algorithm:**
1. DFS returns max depth from node to leaf
2. At each node: collect child depths, take top 2
3. Candidate diameter = depth1 + depth2
4. Return max(depth1, depth2) + 1 to parent

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Node with children depths 3 and 2: diameter through this node = 3+2=5
Return max(3,2)+1=4 to parent
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS from every node | O(N²) | Varies | Baseline |
| DFS Max Two Depths | O(N) | O(N) | Optimal |

**Recommended Solution:** DFS Max Two Depths

**Key Insights:**
1. **Two longest child paths:** Their sum = diameter through this node
2. **Return only max:** Parent only needs the longest path downward
3. **Alternative:** Two BFS: first from any node, then from farthest found

<br><br>

---

```code```
