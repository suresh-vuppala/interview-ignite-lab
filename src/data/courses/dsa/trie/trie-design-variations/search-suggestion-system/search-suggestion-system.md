As user types each character, suggest top-3 lexicographically matching products.

<br>

> products=['mobile','mouse','moneypot'], searchWord='mouse' → [['mobile','moneypot','mouse'],['mobile','moneypot','mouse'],['mouse','mousepad'],...]
>
> **Key insight:** Build trie from sorted products. For each prefix, DFS from prefix node collecting up to 3 words.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Sort + binary search per prefix

### Time Complexity: O(M × N log N)

> **Drawback:**
> Binary search per prefix keystroke.

> **Key Insight for Improvement:**
> Trie + DFS: sort products first, insert into trie. For each prefix, DFS collects words in sorted order (due to sorted insertion).

<br>

---

## Solution 2: Sorted Trie + DFS (Optimal)

**Intuition:** Build trie from sorted products. For each prefix, DFS from prefix node collecting up to 3 words.

**Algorithm:**
1. Sort products
2. Insert all into trie
3. For each prefix (each keystroke): navigate to prefix node → DFS collecting ≤3 words

### Time Complexity: O(N×L + M×3)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
products sorted. Type 'm': DFS from 'm' node → first 3 alphabetically
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + binary search per prefix | O(M × N log N) | Varies | Baseline |
| Sorted Trie + DFS | O(N×L + M×3) | O(N×L) | Optimal |

**Recommended Solution:** Sorted Trie + DFS

**Key Insights:**
1. **Sort first:** DFS naturally returns sorted results
2. **Limit 3:** Stop DFS after 3 results collected
3. **LeetCode 1268:** Clean trie + DFS problem

<br><br>

---

```code```
