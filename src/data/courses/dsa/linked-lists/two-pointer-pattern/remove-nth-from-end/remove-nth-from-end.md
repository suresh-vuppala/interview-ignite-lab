## Overview
Remove the nth node from end using two-pointer technique.

## Topics Covered
1. **Find and Remove**: Locate then delete node
2. **Dummy Node Technique**: Handle edge cases
3. **One-Pass Solution**: Efficient removal
4. **Handle Head Removal**: When n equals length

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `1 ≤ n ≤ size of list`
- `1 ≤ size ≤ 30`
- `0 ≤ Node.val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Remove head (n = size):** Return head.next
2. **Remove tail (n = 1):** Traverse to second-last
3. **Single node, n = 1:** Return null
4. **n = size:** Remove first node — use dummy head
5. **Two nodes, remove first:** Return second node

<br>

---

```code```
