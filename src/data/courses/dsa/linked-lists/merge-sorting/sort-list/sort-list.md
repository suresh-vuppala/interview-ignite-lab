## Overview
Sort a linked list using merge sort algorithm.

## Topics Covered
1. **Merge Sort**: Divide and conquer approach
2. **Find Middle**: Split list into halves
3. **Recursive Sorting**: Sort each half
4. **Merge Sorted Halves**: Combine results

## Complexity Analysis
### Time: O(n log n), Space: O(log n) recursion

## Code


---

## Constraints

- `0 ≤ n ≤ 5 × 10⁴`
- `-10⁵ ≤ Node.val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **Single node:** Already sorted
3. **Already sorted:** Should still work in O(n log n)
4. **Reverse sorted:** Worst case input
5. **All same values:** No swaps needed
6. **Two nodes:** Simple comparison and swap

<br>

---

```code```
