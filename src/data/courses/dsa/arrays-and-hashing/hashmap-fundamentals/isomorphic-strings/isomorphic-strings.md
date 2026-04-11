Given two strings s and t, determine if they are isomorphic. Two strings are isomorphic if characters in s can be replaced to get t, preserving order and bijective mapping.

<br>

> Input: s = "egg", t = "add"
> Output: true (e→a, g→d)

> Input: s = "foo", t = "bar"
> Output: false (o maps to both a and r)

<br>

---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`
- `t.length == s.length`

<br>

---

## All Possible Edge Cases

1. **Same string:** Always isomorphic
2. **Different lengths:** Immediately false
3. **Reverse mapping conflict:** 'badc' → 'baba' — d and c both map to a → false

<br>

---

## Solution 1: Two Hash Maps (Bidirectional Mapping)

**Intuition:**
Maintain two maps: s→t and t→s. For each position, both mappings must be consistent.

**Algorithm:**
1. Create maps s2t and t2s
2. For each position i:
   - If s[i] is mapped but to a different char than t[i] → false
   - If t[i] is mapped but to a different char than s[i] → false
   - Add both mappings
3. Return true

### Time Complexity: O(n)
### Space Complexity: O(1) — at most 256 character mappings

<br>

---

## Solution 2: Pattern Encoding

**Intuition:**
Encode each string by replacing characters with the index of their first occurrence. Isomorphic strings produce the same pattern.

**Algorithm:**
1. Encode s: "egg" → [0, 1, 1]
2. Encode t: "add" → [0, 1, 1]
3. Compare patterns

### Time Complexity: O(n)
### Space Complexity: O(n) for pattern arrays

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Hash Maps | O(n) | O(1) | Bidirectional consistency check |
| Pattern Encoding | O(n) | O(n) | Transform to canonical form |

**Recommended:** Two Hash Maps — simpler, O(1) space.

<br>
<br>

---

```code```
