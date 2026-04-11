Merge accounts sharing common emails using Union-Find.

<br>

---

## Solution 1: DFS/BFS on Email Graph

Build graph: emails are nodes, edges between emails in same account. DFS/BFS to find connected components.

### Time: O(N × L) where N = accounts, L = avg emails | Space: O(N × L)

<br>

---

## Solution 2: Union-Find (Optimal)

Map each email to an account ID. For each account, union all its emails together. Group by root.

### Time: O(N × L × α(N)) ≈ O(N × L) | Space: O(N × L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Email Graph DFS | O(NL) | O(NL) | Graph of emails |
| Union-Find | O(NL) | O(NL) | Union emails per account |

<br>
<br>

---

```code```
