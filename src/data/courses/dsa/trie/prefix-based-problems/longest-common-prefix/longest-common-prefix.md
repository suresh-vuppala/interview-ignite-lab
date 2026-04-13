Find the longest common prefix among all strings.

<br>

> strs=['flower','flow','flight'] → 'fl'
>
> **Key insight:** Insert all strings into trie. Walk from root while only one child exists and not isEnd. Path = common prefix.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Compare all pairs

### Time Complexity: O(N×M×N)

> **Drawback:**
> Comparing all pairs is cubic.

> **Key Insight for Improvement:**
> Trie: insert all strings. Traverse from root following single-child nodes until branch or end. O(N×M) total.

<br>

---

## Solution 2: Trie Single-Child Walk (Optimal)

**Intuition:** Insert all strings into trie. Walk from root while only one child exists and not isEnd. Path = common prefix.

**Algorithm:**
1. Insert all strings into trie
2. Start at root, prefix=''
3. While current has exactly 1 child and !isEnd:
   - Append child's char to prefix
   - Move to child
4. Return prefix

### Time Complexity: O(N×M)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Trie: f→l→(o→w→e→r, i→g→h→t)
Walk: f(1 child)→l(2 children: o,i)→stop. LCP='fl' ✓
```

### Space Complexity: O(N×M)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Compare all pairs | O(N×M×N) | Varies | Baseline |
| Trie Single-Child Walk | O(N×M) | O(N×M) | Optimal |

**Recommended Solution:** Trie Single-Child Walk

**Key Insights:**
1. **Trie branches at divergence:** Single-child path = common prefix
2. **Stop at isEnd too:** Shortest string could be the prefix
3. **Simpler alternative:** Sort + compare first and last string

<br><br>

---

```code```
