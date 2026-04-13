Find the maximum sum of any BST subtree in a binary tree.

<br>

> Track sum instead of size in postorder validation
>
> **Key insight:** Same postorder approach as largest-bst but track sum instead of size.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check every subtree

### Time Complexity: O(N²)

> **Drawback:**
> Same redundancy.

> **Key Insight for Improvement:**
> Same postorder, track sum instead of size.

<br>

---

## Solution 2: Postorder + Sum (Optimal)

**Intuition:** Same postorder approach as largest-bst but track sum instead of size.

**Algorithm:**
Same as largest-bst but return sum instead of size

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same bottom-up approach
```

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check every subtree | O(N²) | Varies | Baseline |
| Postorder + Sum | O(N) | O(H) | Optimal |

**Recommended Solution:** Postorder + Sum

**Key Insights:**
1. **Same algorithm, different metric:** Sum vs size
2. **Handle negative values:** BST with negative sum shouldn't override positive non-BST

<br><br>

---

```code```
