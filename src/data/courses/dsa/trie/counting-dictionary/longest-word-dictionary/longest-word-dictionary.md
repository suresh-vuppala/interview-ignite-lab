Find longest word buildable one character at a time.

<br>

---

## Solution 1: Sort + HashSet — Sort by length, check each prefix exists
## Solution 2: Trie + DFS — Insert all words, DFS for longest path where every prefix is a word

### Time: O(sum of word lengths) | Space: O(same)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Set | O(n log n + total) | O(total) | Check prefixes in set |
| Trie + DFS | O(total) | O(total) | DFS on trie structure |

<br>
<br>

---

```code```
