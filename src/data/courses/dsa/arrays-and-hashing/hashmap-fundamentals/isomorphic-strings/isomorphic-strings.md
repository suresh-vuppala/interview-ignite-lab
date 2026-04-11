Given two strings s and t, determine if they are isomorphic (bijective character mapping preserving order).

<br>

> Input: s = "egg", t = "add" → Output: true (e→a, g→d)
> Input: s = "foo", t = "bar" → Output: false

<br>

---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`, `t.length == s.length`

<br>

---

## All Possible Edge Cases

1. **Same string:** Always isomorphic
2. **Reverse mapping conflict:** 'badc'→'baba' — false

<br>

---

## Solution 1: Two Hash Maps (Bidirectional)

**Intuition:**
Maintain s→t and t→s mappings. Both must be consistent at every position.

### Time Complexity: O(n)
### Space Complexity: O(1) — at most 256 mappings

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Two hash maps require managing two separate data structures and checking both directions. This is correct but slightly verbose.
>
> **Insight:** Encode each string by replacing characters with the index of their first occurrence. "egg"→[0,1,1], "add"→[0,1,1]. If patterns match, strings are isomorphic — single comparison, no maps needed.

<br>

---

## Solution 2: Pattern Encoding

**Intuition:**
Transform each string into a canonical pattern. Compare patterns.

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Maps | O(n) | O(1) | Bidirectional consistency |
| Pattern Encode | O(n) | O(n) | Transform to canonical form |

<br>
<br>
