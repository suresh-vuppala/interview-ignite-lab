Hashing maps data to fixed-size values using a hash function. Used in hash tables, sets, and maps for O(1) average lookup.

## Key Concepts
- Hash function converts key to index
- Collision handling: chaining, open addressing
- Load factor affects performance

## Applications
- Fast lookup/insert/delete
- Caching, databases
- Cryptography

## Code


---

## Constraints

- `1 ≤ s.length ≤ 10⁵`
- `s consists of lowercase English letters (typically)`
- `Hash collisions must be handled`

<br>

---

## All Possible Edge Cases

1. **Empty string:** Return '' or 0
2. **Single character:** Trivial case
3. **All same characters:** Hash/pattern matching is straightforward
4. **No match found:** Return -1 or empty
5. **Multiple matches:** Return all or first depending on problem
6. **Very long string:** Need efficient O(n) algorithm

<br>

---

```code```
