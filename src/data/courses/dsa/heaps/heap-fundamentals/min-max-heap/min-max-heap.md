## Overview

Min heap maintains smallest element at root. Max heap maintains largest at root.

## Operations

- **Insert**: Add and bubble up - O(log n)
- **Extract**: Remove root and bubble down - O(log n)
- **Peek**: View root - O(1)

## Applications

- Priority queues
- Sorting algorithms
- Graph algorithms (Dijkstra, Prim)


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

### Time Complexity
- Insert: O(log n)
- Extract: O(log n)
- Peek: O(1)

### Space Complexity: O(n)

## Code

```code```
