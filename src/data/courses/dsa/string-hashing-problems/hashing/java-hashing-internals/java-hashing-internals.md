Java uses `HashMap` and `HashSet` backed by hash tables.

## Hash Function
- `hashCode()` method
- Bucket index: `hash & (n-1)`

## Collision Resolution
- Chaining with linked lists
- Tree conversion (Java 8+) when bucket size > 8

## Complexity
- Average O(1) operations
- Worst O(log n) with tree conversion

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
