## Overview
Partition list around value x: nodes < x before nodes >= x.

## Topics Covered
1. **Two Lists**: Separate into less and greater
2. **Maintain Order**: Preserve relative order
3. **Merge Lists**: Combine at end
4. **Dummy Nodes**: Simplify implementation

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `0 ≤ n ≤ 200`
- `-100 ≤ Node.val ≤ 100`
- `-200 ≤ x ≤ 200`

<br>

---

## All Possible Edge Cases

1. **All values < x:** List unchanged
2. **All values ≥ x:** List unchanged
3. **x smaller than all values:** List unchanged
4. **x larger than all values:** List unchanged
5. **Empty list:** Return null
6. **Single node:** Return as-is
7. **Preserve relative order:** Must maintain original order within each partition

<br>

---

```code```
