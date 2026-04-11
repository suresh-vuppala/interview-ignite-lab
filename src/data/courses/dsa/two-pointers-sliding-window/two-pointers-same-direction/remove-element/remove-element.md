Remove all occurrences of val in-place, return new length.

<br>

> Input: nums = [3,2,2,3], val = 3 → Output: 2, nums = [2,2,...]

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 100`

<br>

---

## Solution 1: Fast/Slow — Copy Non-Val Forward

**Intuition:** Scan with fast pointer. When element != val, copy to slow position.

### Time: O(n) | Space: O(1)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** When val is rare, we still copy every non-val element forward — many unnecessary writes.
>
> **Insight:** Swap matching elements with the last element and shrink array. Each element moves at most once.

<br>

---

## Solution 2: Swap with End — Fewer Writes (Optimal)

**Intuition:** When nums[i] == val, swap with last element, shrink n. Don't advance i (swapped element needs checking).

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Fast/Slow Copy | O(n) | O(1) | Copy non-val forward |
| Swap with End | O(n) | O(1) | Fewer writes when val is rare |

<br>
<br>
