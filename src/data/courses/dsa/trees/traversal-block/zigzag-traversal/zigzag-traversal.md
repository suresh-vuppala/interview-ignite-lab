Zigzag level order: left-to-right, then right-to-left, alternating.

<br>

> Input: [3,9,20,null,null,15,7]
> Output: [[3],[20,9],[15,7]]

<br>

---

## Solution 1: BFS + Reverse Alternate Levels

Standard level order, reverse every odd level.

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: BFS with Deque

Use deque: even levels add to back, odd levels add to front. No reversal needed.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + Reverse | O(n) | O(n) | Reverse alternate levels |
| BFS + Deque | O(n) | O(n) | Deque avoids reversal |

<br>
<br>

---

```code```
