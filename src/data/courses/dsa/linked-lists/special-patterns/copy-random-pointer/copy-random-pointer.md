## Overview
Deep copy a linked list where each node has a random pointer.

## Topics Covered
1. **Interweaving**: Insert copies between originals
2. **Copy Random Pointers**: Set random using interweaved structure
3. **Separate Lists**: Extract copied list
4. **HashMap Alternative**: Use map for node mapping

## Complexity Analysis
### Time: O(n), Space: O(1) or O(n) with map

## Code


---

## Constraints

- `0 ≤ n ≤ 1000`
- `-10⁴ ≤ Node.val ≤ 10⁴`
- `Random pointer is null or points to a node in the list`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **Single node, random = null:** Copy single node
3. **Single node, random = self:** Copy with self-reference
4. **All random pointers null:** Simple deep copy
5. **Random pointer to head:** Must map old→new nodes
6. **Random pointer to tail:** Same mapping logic

<br>

---

```code```
