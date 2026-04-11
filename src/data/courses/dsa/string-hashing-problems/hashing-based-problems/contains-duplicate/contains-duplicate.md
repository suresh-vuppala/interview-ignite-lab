Given an integer array, return true if any value appears at least twice.

<br>

> Input: [1, 2, 3, 1] → Output: true
> Input: [1, 2, 3, 4] → Output: false

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **All unique:** Return false
2. **All same:** Return true
3. **Single element:** Return false

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:** Compare every pair. If any match, duplicate found.

### Time Complexity: O(n²)
### Space Complexity: O(1)

```code```

> **Key Insight for Improvement:**
> 
> **Drawback of current approach:** We compare every pair of elements — n(n-1)/2 comparisons. This brute force doesn't leverage any structure in the data. For n = 100,000, that's ~5 billion comparisons.
> 
> **Insight:** If we sort the array first, duplicate elements become adjacent. We only need to compare each element with its neighbor — reducing from O(n²) comparisons to O(n) comparisons (after O(n log n) sort).

<br>

---

## Solution 2: Sort + Scan

**Intuition:** Sort the array. Duplicates become adjacent. Single pass to check.

### Time Complexity: O(n log n)
### Space Complexity: O(1) or O(n) depending on sort

```code```

> **Key Insight for Improvement:**
> 
> **Drawback of current approach:** Sorting takes O(n log n) time and may modify the original array. We're doing more work than necessary — we don't need elements in sorted order, we just need to know if we've seen a value before.
> 
> **Insight:** A HashSet provides O(1) insert and O(1) lookup. We can check "have I seen this number before?" in constant time — no sorting needed. This brings the total time from O(n log n) down to O(n).

<br>

---

## Solution 3: Hash Set (Optimal)

**Intuition:** Insert each element into a HashSet. If the element is already present, we've found a duplicate.

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Sort + Scan | O(n log n) | O(1) | Duplicates become adjacent |
| Hash Set | O(n) | O(n) | O(1) existence check per element |

**Key Insights:**
1. **Brute → Sort:** Sorting brings duplicates together — O(n²) → O(n log n)
2. **Sort → Hash Set:** We don't need order, just existence check — O(n log n) → O(n)
3. **Space-Time Tradeoff:** Each improvement trades space for time

<br>
<br>
