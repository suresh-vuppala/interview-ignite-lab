Find the maximum path sum in a binary tree. A path can start and end at ANY node (not necessarily root-to-leaf).

<br>

> Input: root = [-10,9,20,null,null,15,7]
> Output: 42 (path: 15→20→7)

> Explanation: The path doesn't need to pass through root. Max = 15 + 20 + 7 = 42.
> 
> **Key insight:** For each node, the max path THROUGH it = node.val + max(0, leftGain) + max(0, rightGain). Track global max. Return node.val + max(0, max(leftGain, rightGain)) to parent (can only extend one side).

<br>

---

## Constraints
- `1 ≤ N ≤ 3 × 10⁴`, `-1000 ≤ Node.val ≤ 1000`

<br>

---

## All Possible Edge Cases
1. **All negative:** pick single max node
2. **Path doesn't need to include root**
3. **Single node**
4. **Path can go left→node→right**

<br>

---

## Solution 1: Check all paths between all pairs

**Intuition:**
The most straightforward approach — checking every pair of nodes is quadratic.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Checking every pair of nodes is quadratic. Single DFS postorder is O(N).

> **Key Insight for Improvement:**
> Use DFS — Track Global Max While Computing Gains (Optimal) for O(N) time.

<br>

---

## Solution 2: DFS — Track Global Max While Computing Gains (Optimal)

**Algorithm:**
1. Helper returns max gain from this node downward (single path)
2. At each node: maxGainLeft = max(0, helper(left)), maxGainRight = max(0, helper(right))
3. pathThroughNode = val + maxGainLeft + maxGainRight → update global max
4. Return val + max(maxGainLeft, maxGainRight) to parent (can only pick one side)

### Time Complexity: O(N)
**Why?** Each node visited once during DFS.

**Detailed breakdown:** N = 30,000 → 30,000 operations

### Space Complexity: O(H)

**Example walkthrough:**
```
     -10
    /    \
   9     20
        /  \
       15   7

helper(9) = 9 (leaf). pathThrough = 9. Return 9.
helper(15) = 15. helper(7) = 7.
helper(20) = 20+max(0,15)+max(0,7) → pathThrough = 42 ★. Return 20+15 = 35.
helper(-10) = -10+max(0,9)+max(0,35) → pathThrough = -10+9+35 = 34. Return -10+35 = 25.

Global max = 42 ✓
```

> **Drawback:** None — this is optimal.

> **Key Insight for Improvement:** The max(0, ...) clipping is crucial — negative subtrees are ignored (we don't have to include them).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Global Max | O(N) | O(H) | Compute gain, track global max path |

**Key Insights:**
1. **Two different computations:** pathThrough uses both sides, return to parent uses one side
2. **max(0, gain):** Ignore negative branches — don't extend into them
3. **Global tracking:** Path may not pass through root — track max across ALL nodes
4. **FAANG critical:** Top-5 most asked tree problem at Google/Meta

<br><br>

---

```code```
