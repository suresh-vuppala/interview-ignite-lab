## Overview
Group all odd-indexed nodes together followed by even-indexed nodes.

## Topics Covered
1. **Two Pointers**: Track odd and even nodes
2. **Rearrange Links**: Connect odd and even chains
3. **Preserve Order**: Maintain relative order
4. **In-place Operation**: No extra space

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `-10⁶ ≤ Node.val ≤ 10⁶`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **Single node:** Return as-is
3. **Two nodes:** First is odd, second is even — link odd→even
4. **All odds only (1 node):** Even list is empty
5. **Even number of nodes:** Both lists same length
6. **Odd number of nodes:** Odd list has one extra

<br>

---

```code```
