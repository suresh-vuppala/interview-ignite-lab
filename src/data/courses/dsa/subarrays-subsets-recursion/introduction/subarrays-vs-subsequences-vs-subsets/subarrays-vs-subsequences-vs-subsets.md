## Subarrays (Continuous)
- Contiguous elements: [1,2,3] → [1], [1,2], [1,2,3], [2], [2,3], [3]
- Count: O(n²)
- Generation: O(n²)

## Subsequences (Order Maintained)
- Non-contiguous, order preserved: [1,2,3] → [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
- Count: O(2^n)
- Generation: O(2^n)

## Subsets (No Order)
- Same as subsequences but unordered
- Count: O(2^n)
- Use recursion or bitmask

## Code


---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

---

```code```
