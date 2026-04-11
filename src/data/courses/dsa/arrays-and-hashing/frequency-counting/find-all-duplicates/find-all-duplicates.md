Given an array of length n where each element is in range [1, n] and appears once or twice, find all elements that appear twice. Solve in O(n) time and O(1) extra space.

<br>

> Input: [4, 3, 2, 7, 8, 2, 3, 1]
> Output: [2, 3]

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

<br>

---

## Solution 1: Hash Set

**Intuition:**
Track seen numbers in a set. If already seen, it's a duplicate.

### Time Complexity: O(n)
### Space Complexity: O(n) — violates O(1) space requirement

> **Key Insight:** Since values are in [1, n], use the array itself as a hash map by negating values at index positions.

<br>

---

## Solution 2: Sort + Scan

**Intuition:**
Sort array, scan for adjacent duplicates.

### Time Complexity: O(n log n)
### Space Complexity: O(1) — but modifies input

<br>

---

## Solution 3: Index Marking (Optimal)

**Intuition:**
Since values are in [1, n], use each value as an index. Mark visited by negating the value at that index. If already negative when we visit, it's a duplicate.

**Algorithm:**
1. For each num in nums:
   - idx = |num| - 1 (map value to 0-indexed)
   - If nums[idx] < 0 → already visited → duplicate → add |num| to result
   - Else negate: nums[idx] = -nums[idx]

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) extra — uses input array as hash map

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n) | O(n) | Track seen in set |
| Sort + Scan | O(n log n) | O(1) | Adjacent duplicates |
| Index Marking | O(n) | O(1) | Values in [1,n] → use array as hash |

**Recommended:** Index Marking — O(n) time, O(1) space.

<br>
<br>

---

```code```
