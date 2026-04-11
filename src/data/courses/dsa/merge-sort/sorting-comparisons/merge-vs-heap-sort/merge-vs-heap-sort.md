## Comparison

| Aspect | Merge Sort | Heap Sort |
|--------|-----------|-----------|
| **Time (All)** | O(n log n) | O(n log n) |
| **Space** | O(n) | O(1) |
| **Stability** | Stable | Unstable |
| **In-place** | No | Yes |
| **Cache** | Better | Worse |

## When to Use
- **Merge Sort**: Need stability, external sorting
- **Heap Sort**: Memory constrained, guaranteed O(n log n)

## Code


---

## Constraints

- `0 ≤ n ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** Still O(n log n) but no inversions
2. **Reverse sorted:** Maximum inversions
3. **Single element:** Already sorted
4. **Empty array:** Nothing to sort
5. **All same elements:** No swaps needed
6. **Two elements:** Single comparison

<br>

---

```code```
