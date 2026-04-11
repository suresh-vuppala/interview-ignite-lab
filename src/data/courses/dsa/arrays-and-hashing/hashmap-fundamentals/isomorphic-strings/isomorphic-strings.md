Given two strings s and t, determine if they are isomorphic. Two strings are isomorphic if the characters in s can be replaced to get t, with a consistent one-to-one mapping that preserves order.

<br>

> Input:
> s = "egg", t = "add"

> Output:
> true

> Explanation:
> e→a, g→d. Each character in s maps to exactly one character in t, and no two characters map to the same character. Mapping is bijective.
> 
> **Key insight:** Both s→t and t→s mappings must be consistent. A single map only catches one direction — "badc"→"baba" would pass with one map but fail with two.

<br>



---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`
- `t.length == s.length`
- `s and t consist of any valid ASCII character`

<br>

---

## All Possible Edge Cases

1. **Same string:** Always isomorphic (identity mapping)
2. **Single character:** Always isomorphic
3. **One-direction conflict:** "ab"→"aa" — a→a, b→a — fails because two chars map to same target
4. **Reverse conflict:** "aa"→"ab" — a maps to both a and b — fails

<br>

---

## Solution 1: Two Hash Maps (Bidirectional)

**Intuition:**
Maintain two mappings: s→t and t→s. At each position, both must be consistent. If s[i] already maps to something other than t[i], OR t[i] already maps to something other than s[i], return false.

**Algorithm:**
1. Create two maps: mapST (s→t) and mapTS (t→s)
2. For each index i:
   - If s[i] in mapST and mapST[s[i]] ≠ t[i] → false
   - If t[i] in mapTS and mapTS[t[i]] ≠ s[i] → false
   - Set mapST[s[i]] = t[i] and mapTS[t[i]] = s[i]
3. All consistent → true

### Time Complexity: O(N)
**Why?**
- Single pass through both strings: N iterations
- Hash map operations: O(1) average each
- Total: O(N)

**Detailed breakdown:**
- String length 50,000 → ~100,000 map operations (2 per position)
- O(N) is optimal — must check every character

### Space Complexity: O(1)
**Why?**
- Maps hold at most 256 entries (ASCII characters)
- Does not grow with input size — bounded by alphabet

**Example walkthrough:**
```
s = "egg", t = "add"

i=0: s='e', t='a' → mapST={e:a}, mapTS={a:e} ✓
i=1: s='g', t='d' → mapST={e:a, g:d}, mapTS={a:e, d:g} ✓
i=2: s='g', t='d' → mapST[g]=d == d ✓, mapTS[d]=g == g ✓
All consistent → true ✓
```

> **Drawback:**
> Requires maintaining two separate hash maps and checking both at every position. While correct and optimal, the code is slightly verbose with two parallel lookups.

> **Key Insight for Improvement:**
> Encode each string by the index of each character's first occurrence. "egg"→[0,1,1], "add"→[0,1,1]. If patterns match → isomorphic. Single transformation, one comparison — no maps needed.

<br>

---

## Solution 2: First Occurrence Pattern Encoding

**Intuition:**
Replace each character with the index of its FIRST occurrence in the string. Two strings are isomorphic if and only if their encoded patterns are identical.

**Algorithm:**
1. Encode s: for each char, store index of first occurrence → pattern_s
2. Encode t: same process → pattern_t
3. Return pattern_s == pattern_t

### Time Complexity: O(N)
**Why?**
- Two encoding passes: O(N) each
- Comparison: O(N)
- Total: O(N)

**Detailed breakdown:**
- String length 50,000 → ~150,000 operations
- Same asymptotic as Solution 1

**Example walkthrough:**
```
s = "egg" → e first at 0, g first at 1 → [0, 1, 1]
t = "add" → a first at 0, d first at 1 → [0, 1, 1]
[0,1,1] == [0,1,1] → true ✓

s = "foo" → f=0, o=1 → [0, 1, 1]
t = "bar" → b=0, a=1, r=2 → [0, 1, 2]
[0,1,1] ≠ [0,1,2] → false ✓
```

### Space Complexity: O(N)
**Why?**
- Storing two encoded pattern arrays of size N

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Hash Maps | O(N) | O(1) | Bidirectional mapping check |
| Pattern Encoding | O(N) | O(N) | Transform to canonical form |

**Recommended Solution:** Two Hash Maps (Solution 1) — O(N) time, O(1) space.

**Key Insights:**
1. **Bidirectional check:** One map catches s→t conflicts; need t→s for reverse conflicts
2. **Pattern encoding:** Alternative view — isomorphic = same structural pattern
3. **Follow-up:** For large alphabets, pattern encoding may be cleaner code


<br>
<br>

---

```code```
