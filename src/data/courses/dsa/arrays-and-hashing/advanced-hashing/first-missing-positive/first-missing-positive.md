Find the smallest missing positive integer. O(n) time, O(1) extra space.

<br>

> Input: [3,4,-1,1] → Output: 2
> Input: [1,2,0] → Output: 3

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **[1,2,3]:** Return 4
2. **All negative:** Return 1
3. **[7,8,9]:** Return 1

<br>

---

## Solution 1: Hash Set

**Intuition:** Put all positives in a set. Check 1, 2, 3... until missing.

### Time Complexity: O(n)
### Space Complexity: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Uses O(n) extra space for the hash set. The problem requires O(1) extra space.
>
> **Insight:** Since answer is in [1, n+1], use the array ITSELF as a hash map. Place each value at its "correct" index: nums[i] should hold value i+1. After this cyclic sort, the first index where nums[i] ≠ i+1 is the answer.

<br>

---

## Solution 2: Cyclic Sort (Optimal)

**Intuition:** Place each number at index num-1. First mismatch = answer.

### Time Complexity: O(n) — each element swapped at most once
### Space Complexity: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n) | O(n) | Check 1,2,3... in set |
| Cyclic Sort | O(n) | O(1) | Array itself as hash map |

<br>
<br>
