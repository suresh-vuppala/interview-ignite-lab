## Stability Definition
A sorting algorithm is **stable** if equal elements maintain their relative order after sorting.

## Examples

**Stable**: Merge Sort, Insertion Sort, Bubble Sort  
**Unstable**: Quick Sort, Heap Sort, Selection Sort

## Importance
Stability matters when sorting by multiple keys (e.g., sort by name, then by age).

**Example**: [(Alice, 25), (Bob, 25), (Charlie, 30)]  
- Stable: Alice stays before Bob
- Unstable: Bob might come before Alice

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
