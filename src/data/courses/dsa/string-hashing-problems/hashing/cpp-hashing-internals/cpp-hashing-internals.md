C++ uses `unordered_map` and `unordered_set` with hash tables.

## Hash Function
- `std::hash<T>` for built-in types
- Custom hash for user types

## Collision Resolution
- Separate chaining (linked lists)
- Rehashing when load factor exceeds threshold

## Complexity
- Average O(1) insert/search/delete
- Worst O(n) with many collisions

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
