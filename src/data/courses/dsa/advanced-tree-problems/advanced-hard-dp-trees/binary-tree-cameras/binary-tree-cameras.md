Place minimum cameras on tree nodes to monitor all nodes. A camera monitors parent, itself, and children.

<br>

> [0,0,null,0,0] → 1 camera at root covers all
>
> **Key insight:** Greedy postorder: states 0=not covered, 1=has camera, 2=covered. If child not covered → parent MUST have camera.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: DFS try all placements

### Time Complexity: O(2^N)

> **Drawback:**
> Exponential.

> **Key Insight for Improvement:**
> Postorder greedy: process leaves first. Leaf's parent gets camera (covers 3 levels). Skip covered nodes.

<br>

---

## Solution 2: Postorder Greedy (Optimal)

**Intuition:** Greedy postorder: states 0=not covered, 1=has camera, 2=covered. If child not covered → parent MUST have camera.

**Algorithm:**
1. DFS postorder. Each node returns state:
   - 0: not monitored
   - 1: has camera
   - 2: monitored (no camera)
2. If any child returns 0 → place camera here (return 1)
3. If any child returns 1 → I'm monitored (return 2)
4. Else → return 0 (not monitored, parent will handle)

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Leaf returns 0 → parent places camera (returns 1) → grandparent returns 2
```

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS try all placements | O(2^N) | Varies | Baseline |
| Postorder Greedy | O(N) | O(H) | Optimal |

**Recommended Solution:** Postorder Greedy

**Key Insights:**
1. **Greedy from leaves:** Most efficient camera placement
2. **Three states:** Not covered, has camera, covered
3. **Check root:** If root returns 0, add one more camera

<br><br>

---

```code```
