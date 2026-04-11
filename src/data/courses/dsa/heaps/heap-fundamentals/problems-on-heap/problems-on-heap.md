## Common Heap Problems

### Top K Elements
- Use min/max heap of size k
- Maintain k largest or smallest elements

### Merge K Sorted Arrays
- Use min heap with one element from each array
- Extract min and add next from same array

### Running Median
- Two heaps: max heap for lower half, min heap for upper half
- Balance heaps to find median

## Problem Patterns

1. **Top K Pattern**: Min heap of size k for k largest, max heap for k smallest
2. **Merge Pattern**: Min heap to merge sorted sequences
3. **Two Heap Pattern**: Balance two heaps for median/percentile


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

## Complexity Analysis

Most heap problems: O(n log k) time, O(k) space

## Code

```code```
