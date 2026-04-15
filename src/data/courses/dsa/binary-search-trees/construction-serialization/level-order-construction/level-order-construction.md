Construct a binary tree from level-order traversal (with nulls marking missing children).

<br>

> Input: [3,9,20,null,null,15,7]
> Output: tree with root=3
> **Key insight:** BFS construction. Queue of parent nodes. For each parent, next two values are left and right children. Null means no child.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **Single node**
2. **Complete tree**
3. **Null markers for missing children**

<br>

---

## Solution 1: Recursive construction

**Intuition:**
The most straightforward approach — bfs queue-based construction is more natural for level-order input.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> BFS queue-based construction is more natural for level-order input.

> **Key Insight for Improvement:**
> Use BFS Queue Construction (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS Queue Construction (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** This is how LeetCode represents trees. Understanding this construction is essential for testing/debugging tree solutions.

<br>

---

**Key Insights:**
1. **Queue-based:** Process parents in order, assign children from array
2. **Null = no child:** Skip and move to next value
3. **LeetCode format:** Standard tree serialization

<br><br>

---

```code```
