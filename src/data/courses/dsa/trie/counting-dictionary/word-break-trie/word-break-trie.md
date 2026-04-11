Check if string can be segmented into dictionary words (Trie-assisted).

<br>

---

## Solution 1: DP — dp[i] = can s[0..i-1] be segmented. Check all j < i.

### Time: O(n² × L) | Space: O(n)

<br>

---

## Solution 2: DP + Trie (Optimized)

Build trie from dictionary. For each position, traverse trie to find all matching words → faster than checking all substrings.

### Time: O(n × L) | Space: O(dictionary size)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DP | O(n²L) | O(n) | Check all splits |
| DP + Trie | O(nL) | O(dict) | Trie eliminates invalid prefix checks |

<br>
<br>

---

```code```
