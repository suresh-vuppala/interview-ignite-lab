Find the diameter of a binary tree — the length of the longest path between any two nodes (measured in edges).

<br>

> Input: root = [1,2,3,4,5]
> Output: 3

> Explanation: Longest path: 4→2→1→3 or 5→2→1→3. Length = 3 edges.
> 
> **Key insight:** The diameter through a node = leftHeight + rightHeight. Compute height bottom-up, updating a global max(leftH + rightH) at each node.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: For Each Node, Compute Left+Right Height

### Time Complexity: O(N²) — recomputes heights

> **Drawback:** Same as balanced tree — recomputing heights. Bottom-up resolves this.

> **Key Insight for Improvement:** During height computation, diameter through current node = leftH + rightH. Track max across all nodes. Single pass → O(N).

<br>

---

## Solution 2: Bottom-Up Height + Diameter Tracking (Optimal)

**Algorithm:**
1. diameter = 0
2. Helper returns height of subtree
3. At each node: diameter = max(diameter, leftH + rightH)
4. Return height = 1 + max(leftH, rightH)

### Time Complexity: O(N)
**Why?** Each node visited once during height computation.

**Detailed breakdown:** N = 10,000 → 10,000 operations

**Example walkthrough:**
```
Tree: [1, 2, 3, 4, 5]

height(4)=1, height(5)=1
At node 2: leftH=1, rightH=1, diameter=max(0, 1+1)=2
height(3)=1
At node 1: leftH=2, rightH=1, diameter=max(2, 2+1)=3 ★

Diameter = 3 ✓
```

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Per-node height | O(N²) | O(H) | Recompute heights |
| Bottom-up | O(N) | O(H) | Track diameter during height computation |

**Key Insights:**
1. **Diameter through node = leftH + rightH** (in edges)
2. **Global max:** Diameter may NOT pass through root — track max across all nodes
3. **Same pattern as balanced:** Bottom-up height with extra bookkeeping

<br><br>

---

```code```
