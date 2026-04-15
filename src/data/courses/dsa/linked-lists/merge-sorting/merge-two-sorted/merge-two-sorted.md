Merge two sorted linked lists into one sorted list.

<br>

> Input: l1 = [1,2,4], l2 = [1,3,4]
> Output: [1,1,2,3,4,4]
> **Key insight:** Two pointers on both lists. Compare heads, append smaller to result. When one exhausts, append the remainder of the other.

<br>

---

## Constraints
- `0 ≤ N, M ≤ 50`

<br>

---

## All Possible Edge Cases
1. **One or both empty**
2. **No interleaving needed (one entirely before other)**
3. **All same values**
4. **Very different lengths**

<br>

---

## Solution 1: Copy to array, sort, rebuild

**Intuition:**
The most straightforward approach — loses the sorted structure.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N log N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Loses the sorted structure. Merging directly is O(N) and uses existing nodes.

> **Key Insight for Improvement:**
> Use Merge with Dummy Node (Optimal) for O(N + M) time.

<br>

---

## Solution 2: Merge with Dummy Node (Optimal)

**Algorithm:** Dummy node. Compare l1.val vs l2.val. Append smaller. Advance that pointer. After loop, append remaining.

### Time Complexity: O(N + M)
**Why?** Each node processed exactly once.

### Space Complexity: O(1) — reuse existing nodes

> **Drawback:** None — O(N+M) is optimal.

> **Key Insight for Improvement:** Foundation for merge-k-sorted (merge pairs iteratively or use heap) and merge sort on linked list.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Iterative merge | O(N+M) | O(1) |
| Recursive | O(N+M) | O(N+M) stack |

**Key Insights:**
1. **Dummy node:** Avoids special case for first element
2. **Append remainder:** When one list exhausts, tail.next = other list
3. **Stable sort property:** Equal elements maintain original order

<br><br>

---

```code```
