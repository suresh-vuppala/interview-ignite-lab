## Overview
Rotate linked list to the right by k places.

## Topics Covered
1. **Find Length**: Count total nodes
2. **Normalize K**: Handle k > length
3. **Find New Tail**: Locate rotation point
4. **Reconnect**: Adjust pointers

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `0 ≤ n ≤ 500`
- `-100 ≤ Node.val ≤ 100`
- `0 ≤ k ≤ 2 × 10⁹`

<br>

---

## All Possible Edge Cases

1. **k = 0:** No rotation
2. **k = n:** Full rotation — same as original
3. **k > n:** k = k % n (effective rotation)
4. **k = 1:** Last node becomes head
5. **Single node:** No change regardless of k
6. **Empty list:** Return null

<br>

---

```code```
