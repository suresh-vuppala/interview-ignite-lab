Count distinct substrings using Trie.

<br>

---

## Solution 1: HashSet — Store all substrings O(n³ space)
## Solution 2: Trie Insertion — Insert all suffixes, count trie nodes

### Time: O(n²) | Space: O(n²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| HashSet | O(n³) | O(n³) | Store all substrings |
| Trie | O(n²) | O(n²) | Shared prefixes save space |

<br>
<br>

---

```code```
