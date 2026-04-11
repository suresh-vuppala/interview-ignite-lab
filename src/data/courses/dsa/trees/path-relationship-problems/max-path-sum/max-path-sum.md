Find the maximum path sum in a binary tree. Path can start and end at any node.

<br>

> Input: [-10,9,20,null,null,15,7]
> Output: 42 (path: 15→20→7)

<br>

---

## Constraints

- `1 ≤ n ≤ 3 × 10⁴`
- `-1000 ≤ Node.val ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **All negative:** Pick least negative single node
2. **Single node:** Return its value
3. **Path doesn't pass root:** Entirely in one subtree

<br>

---

## Solution 1: Brute Force — All Paths Between All Pairs

### Time: O(n³) | Space: O(n)

<br>

---

## Solution 2: DFS with Global Max (Optimal)

**Intuition:** At each node, compute max "one-sided" path (node + best child). Track global max including "two-sided" path (left + node + right).

**Algorithm:**
```
maxSum = -∞
int maxGain(node):
    if null: return 0
    left = max(maxGain(node.left), 0)   // Ignore negative paths
    right = max(maxGain(node.right), 0)
    
    // Path through this node (possibly using both sides)
    maxSum = max(maxSum, left + node.val + right)
    
    // Return one-sided max to parent
    return node.val + max(left, right)
```

**Key:** Return one-sided path to parent (can only go one direction), but track two-sided path globally.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| All Pairs | O(n³) | O(n) | Check all possible paths |
| DFS + Global Max | O(n) | O(h) | One-sided vs two-sided path tracking |

<br>
<br>

---

```code```
