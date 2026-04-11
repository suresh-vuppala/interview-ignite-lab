## Sorting Algorithms Space Complexity

| Algorithm | Space Complexity | In-place? |
|-----------|-----------------|-----------|
| Merge Sort | O(n) | No |
| Quick Sort | O(log n) | Yes |
| Heap Sort | O(1) | Yes |
| Bubble Sort | O(1) | Yes |
| Insertion Sort | O(1) | Yes |
| Selection Sort | O(1) | Yes |

## Key Points
- **Merge Sort**: Requires O(n) auxiliary space for merging
- **Quick Sort**: O(log n) for recursion stack
- **Heap Sort**: O(1) auxiliary space, in-place

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
