Count the number of subarrays with exactly k different integers.

<br>

> Input: nums = [1,2,1,2,3], k = 2
> Output: 7

> **Key insight:** exactly(k) = atMost(k) - atMost(k-1)

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 2 × 10⁴`
- `1 ≤ nums[i], k ≤ nums.length`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Subarrays with 1 distinct element
2. **k > distinct count:** Return 0
3. **All same elements:** Every subarray has 1 distinct

<br>

---

## Solution 1: Brute Force

**Intuition:** Check all subarrays, count distinct elements in each.

### Time Complexity: O(n³) or O(n²) with hash set
### Space Complexity: O(n)

<br>

---

## Solution 2: Sliding Window + atMost Trick (Optimal)

**Intuition:**
Counting "exactly k" directly is hard with sliding window. But "at most k" is easy! Use: exactly(k) = atMost(k) - atMost(k-1).

**atMost(k) algorithm:**
1. Sliding window with frequency map
2. Shrink when distinct > k
3. For each right position: count += (right - left + 1) — all subarrays ending at right

**Algorithm:**
1. Return atMost(k) - atMost(k-1)

### Time Complexity: O(n) — two sliding window passes
### Space Complexity: O(n) — frequency map

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(n) | Check all subarrays |
| atMost Trick | O(n) | O(n) | exactly(k) = atMost(k) - atMost(k-1) |

**Key Pattern:** The "atMost" trick works for any "exactly K" sliding window problem.

<br>
<br>

---

```code```
