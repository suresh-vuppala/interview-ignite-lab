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
> Sorting groups duplicates together — adjacent elements can be compared in one pass.

<br>

---

## Solution 2: Sort + Scan

**Intuition:** Sort the array. Duplicates become adjacent. Single pass to check.

### Time Complexity: O(n log n)
### Space Complexity: O(1) or O(n) depending on sort

```code```

> **Key Insight for Improvement:**
> A HashSet gives O(1) lookups — no need to sort at all.

<br>

---

## Solution 3: Hash Set (Optimal)

**Intuition:** Insert each element. If already present, duplicate found.

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Sort + Scan | O(n log n) | O(1) | Adjacent duplicates |
| Hash Set | O(n) | O(n) | O(1) existence check |

<br>
<br>
