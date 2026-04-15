Given a BST and a target sum, find if there exist two nodes whose values add up to the target.

<br>

> Input: root = [5,3,6,2,4,null,7], k=9
> Output: true (2+7=9)
> **Key insight:** BST iterator approach: one iterator from smallest (inorder), one from largest (reverse inorder). Two-pointer technique on sorted sequence without materializing the array.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **No pair sums to target**
2. **Same node used twice (not allowed)**
3. **Negative values in BST**
4. **Target = 2 × root value**

<br>

---

## Solution 1: Inorder to Array + Two Pointers — O(N) time, O(N) space

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Hash Set During Traversal (Simple Optimal)

**Algorithm:** DFS. For each node, check if (target - node.val) is in the set. Add node.val to set. If found → true.

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** O(N) space for hash set. BST iterator approach uses O(H).

> **Key Insight for Improvement:** Two BST iterators: one scanning left→right (smallest up), one right→left (largest down). Same as two-pointer on sorted array but O(H) space.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Array + Two Ptr | O(N) | O(N) |
| Hash Set | O(N) | O(N) |
| Two BST Iterators | O(N) | O(H) |

**Key Insights:**
1. **BST = sorted:** Two-pointer technique applies
2. **Hash set is simpler:** O(N) space but easy to implement
3. **Iterator approach is optimal space:** O(H) using two stacks

<br><br>

---

```code```
