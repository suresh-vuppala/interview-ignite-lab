## Overview
Learn to reverse linked list in groups of K nodes.

## Topics Covered
1. **Group Reversal**: Reverse every K nodes
2. **Handle Remaining**: Deal with nodes less than K at end
3. **Recursive Approach**: Break into subproblems
4. **Iterative Approach**: Use loops for reversal

## Problem Statement
Reverse nodes of a linked list K at a time. If remaining nodes < K, leave them as is.


---

## Constraints

- `1 ≤ n ≤ 5000`
- `1 ≤ k ≤ n`
- `-1000 ≤ Node.val ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **k = 1:** No reversal
2. **k = n:** Reverse entire list
3. **n not divisible by k:** Remaining < k nodes stay as-is
4. **k = 2:** Swap pairs
5. **Single node:** Return as-is
6. **k > n:** No reversal (group incomplete)

<br>

## Approach

### Reverse K Groups
- Count if K nodes available
- Reverse K nodes
- Recursively/iteratively process rest
- Time: O(n), Space: O(1) iterative, O(n/k) recursive

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1) iterative, O(n/k) recursive

## Code

```code```
