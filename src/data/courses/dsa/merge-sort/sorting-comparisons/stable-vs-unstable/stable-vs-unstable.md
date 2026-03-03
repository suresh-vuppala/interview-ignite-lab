# Stable vs Unstable Sorting

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
```code```