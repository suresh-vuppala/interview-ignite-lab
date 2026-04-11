## Problem Statement

Sort an array using heap sort algorithm.

## Approach

1. Build max heap from array - O(n)
2. Repeatedly extract max and place at end - O(n log n)
3. Reduce heap size and heapify

## Complexity Analysis

### Time Complexity: O(n log n)
- Build heap: O(n)
- Extract n times: O(n log n)

### Space Complexity: O(1)
- In-place sorting

## Code



---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single element:** It is both min and max
2. **All same elements:** Heap operations trivial
3. **Already a valid heap:** No restructuring needed
4. **k = 1:** Find min/max directly
5. **k = n:** Need to process entire heap
6. **Negative values:** Min heap with negatives

<br>

---

```code```
