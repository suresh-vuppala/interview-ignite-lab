## Comparison-Based Sorting
Uses comparisons to determine order. Lower bound: O(n log n)

**Examples**: Merge Sort, Quick Sort, Heap Sort  
**Time**: O(n log n) minimum

## Non-Comparison Sorting
Uses properties of data (digits, range). Can be O(n)

**Examples**: Counting Sort, Radix Sort, Bucket Sort  
**Time**: O(n) or O(n + k)

## When to Use
- **Comparison**: General purpose, any data type
- **Non-comparison**: Integers with limited range

## Code


---

## Constraints

- `0 ≤ n ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** Still O(n log n) but no inversions
2. **Reverse sorted:** Maximum inversions
3. **Single element:** Already sorted
4. **Empty array:** Nothing to sort
5. **All same elements:** No swaps needed
6. **Two elements:** Single comparison

<br>

---

```code```
