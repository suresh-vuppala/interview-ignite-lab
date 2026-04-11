Given an integer array of length n where each element is in range [1, n] and appears once or twice, find all elements that appear twice. Solve in O(n) time and O(1) extra space using index marking (negate visited positions).

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `1 ≤ nums[i] ≤ n`
- `Each element appears once or twice`
- `Must solve in O(n) time, O(1) extra space`

<br>

---

## All Possible Edge Cases

1. **No duplicates:** Return []
2. **All duplicates:** [1,1,2,2,3,3] → [1,2,3]
3. **Single element:** Return []
4. **One duplicate:** Return [that element]
5. **Values equal indices:** nums[i] = i+1 pattern helps with index marking
6. **Already sorted:** Still need to detect duplicates

<br>

---

```code```
