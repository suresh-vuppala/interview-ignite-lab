Given unsorted array, find length of longest consecutive elements sequence in O(n).

<br>

> Input: [100,4,200,1,3,2] → Output: 4 (sequence [1,2,3,4])

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return 0
2. **Duplicates:** [1,2,2,3] → length 3
3. **All same:** Return 1

<br>

---

## Solution 1: Sort + Scan

**Intuition:** Sort, then scan for consecutive runs.

### Time Complexity: O(n log n)
### Space Complexity: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Sorting takes O(n log n) — the problem asks for O(n). Also, we need to handle duplicates carefully after sorting.
>
> **Insight:** Put all numbers in a HashSet for O(1) lookups. Only start counting from numbers that are sequence BEGINNINGS (num-1 not in set). This ensures each element is visited at most twice — O(n) total.

<br>

---

## Solution 2: Hash Set — Only Count from Beginnings (Optimal)

**Intuition:** For each number where num-1 is NOT in set (= sequence start), count consecutive elements forward.

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Scan | O(n log n) | O(1) | Sort then scan |
| Hash Set | O(n) | O(n) | Only count from sequence beginnings |

<br>
<br>
