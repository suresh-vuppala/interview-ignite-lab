## Overview
Learn to reverse a segment of linked list between two positions.

## Topics Covered
1. **Segment Reversal**: Reverse nodes from position m to n
2. **Maintain Connections**: Keep links before and after segment
3. **One-Pass Solution**: Reverse in single traversal
4. **Handle Edge Cases**: Positions at boundaries

## Problem Statement
Reverse nodes from position m to n (1-indexed) in a linked list.


---

## Constraints

- `1 ≤ n ≤ 500`
- `1 ≤ left ≤ right ≤ n`
- `-500 ≤ Node.val ≤ 500`

<br>

---

## All Possible Edge Cases

1. **left == right:** No reversal needed
2. **left = 1:** Reverse from head — head changes
3. **right = n:** Reverse to end
4. **left = 1, right = n:** Reverse entire list
5. **Single node:** Return as-is

<br>

## Approach

### Reverse Between m and n
- Traverse to position m-1
- Reverse nodes from m to n
- Connect reversed segment to rest
- Time: O(n), Space: O(1)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1)

## Code

```code```
