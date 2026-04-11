## Overview
Find the node where two linked lists intersect.

## Topics Covered
1. **Length Difference**: Calculate and align
2. **Two Pointers**: Traverse both lists
3. **Cycle Through**: Switch heads when reaching end
4. **Detect Intersection**: Find common node

## Complexity Analysis
### Time: O(m+n), Space: O(1)

## Code


---

## Constraints

- `0 ≤ n, m ≤ 3 × 10⁴`
- `1 ≤ Node.val ≤ 10⁵`
- `Lists are guaranteed to not have cycles`

<br>

---

## All Possible Edge Cases

1. **No intersection:** Return null
2. **Intersection at head:** Same first node
3. **Intersection at tail:** Only last node shared
4. **Different lengths before intersection:** Align pointers by length difference
5. **Same list:** Intersection at head
6. **One list empty:** No intersection

<br>

---

```code```
