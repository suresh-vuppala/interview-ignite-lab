Find all elements appearing twice. Array of length n with values in [1,n]. O(n) time, O(1) space.

<br>

> Input: [4,3,2,7,8,2,3,1] → Output: [2,3]

<br>

---

## Constraints

- Each element appears once or twice, values in [1,n]

<br>

---

## Solution 1: Hash Set

**Intuition:** Track seen numbers. If seen again → duplicate.

### Time: O(n) | Space: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Uses O(n) extra space for the hash set, violating the O(1) space requirement.
>
> **Insight:** Since values are in [1,n], use each value as an index into the array itself. Mark visited by negating the value at that index. If already negative → it's a duplicate. The array becomes its own hash map.

<br>

---

## Solution 2: Index Marking — Negate to Mark (Optimal)

**Intuition:** For each num, check sign at index |num|-1. Negative = visited = duplicate.

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n) | O(n) | Track in set |
| Index Marking | O(n) | O(1) | Array itself as hash map |

<br>
<br>
