Find the kth smallest and kth largest element in a BST.

<br>

> Input: BST = [3,1,4,null,2], k=1
> Output: kth smallest=1, kth largest=4
> **Key insight:** Inorder traversal gives sorted order. Kth smallest = kth element in inorder. Kth largest = kth element in reverse inorder (right→root→left).

<br>

---

## Constraints
- `1 ≤ k ≤ N ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **K = 1:** smallest or largest
2. **K = N:** largest or smallest
3. **K > N:** invalid
4. **BST with only left/right children**

<br>

---

## Solution 1: Inorder to Array — O(N) time, O(N) space

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

## Solution 2: Inorder with Early Termination (Optimal)

**Algorithm:** Inorder DFS with a counter. Decrement k at each node visit. When k == 0 → found the kth smallest.

### Time Complexity: O(H + k)
**Why?** Traverse H nodes to reach leftmost, then visit k nodes.

**Detailed breakdown:** H=20, k=5 → 25 operations (not full N traversal!)

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Full inorder | O(N) | O(N) | Collect all, index k |
| Early termination | O(H+k) | O(H) | Stop after k visits |

**Key Insights:**
1. **Inorder = sorted:** BST's defining useful property
2. **Early stop saves time:** Don't traverse entire tree for small k
3. **Kth largest = reverse inorder:** Right→Root→Left traversal

<br><br>

---

```code```
