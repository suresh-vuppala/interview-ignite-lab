## Internal Sorting
Data fits entirely in main memory (RAM).

**Examples**: Quick Sort, Merge Sort, Heap Sort  
**Characteristics**: Fast, random access

## External Sorting
Data too large for memory, stored on disk.

**Examples**: External Merge Sort, Polyphase Merge  
**Characteristics**: Sequential access, I/O optimization

## Key Differences
- **Internal**: All data in RAM
- **External**: Data on disk, chunks in RAM
- **Performance**: Internal faster, External handles large data

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
