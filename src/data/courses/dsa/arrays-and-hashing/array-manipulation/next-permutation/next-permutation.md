Rearrange numbers into the lexicographically next greater permutation.

<br>

> Input: [1,2,3] → [1,3,2]
> Input: [3,2,1] → [1,2,3] (wrap)

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 100`

<br>

---

## Solution 1: Three-Step Algorithm (Optimal)

**Intuition:**
Find rightmost "dip" (ascending pair). Swap with smallest-larger element to its right. Reverse suffix.

**Algorithm:**
1. Find largest i where nums[i] < nums[i+1] (rightmost ascent/dip)
2. Find largest j > i where nums[j] > nums[i]
3. Swap nums[i] and nums[j]
4. Reverse suffix nums[i+1..end]
5. If no dip → reverse entire array (wrap to smallest)

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| All Permutations | O(n!) | O(n!) | Generate all, find next |
| Three-Step | O(n) | O(1) | Find dip, swap, reverse |

**Note:** This problem has one standard O(n) approach — the three-step algorithm is already optimal.

<br>
<br>
