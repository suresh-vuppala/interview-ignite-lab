## Overview
Merge K sorted linked lists into one sorted list.

## Topics Covered
1. **Min Heap Approach**: Use priority queue
2. **Divide and Conquer**: Merge pairs recursively
3. **Sequential Merging**: Merge one by one
4. **Optimization**: Choose best approach

## Complexity Analysis
### Time: O(N log k), Space: O(k) where N=total nodes

## Code


---

## Constraints

- `0 ≤ k ≤ 10⁴`
- `0 ≤ total nodes ≤ 10⁴`
- `Lists are sorted in ascending order`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Return null
2. **k = 1:** Return that single list
3. **All empty lists:** Return null
4. **One non-empty, rest empty:** Return the non-empty one
5. **All lists single node:** Merge into one sorted list
6. **Large k, small lists:** Min-heap approach efficient

<br>

---

```code```
