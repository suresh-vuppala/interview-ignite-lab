Reverse a doubly linked list.

<br>

> Example: 1↔2↔3↔4 → 4↔3↔2↔1
> **Key insight:** Swap prev and next pointers for every node. The last node processed becomes the new head.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## All Possible Edge Cases
1. **Empty / single node**
2. **Two nodes: swap**
3. **Verify both prev and next after reverse**

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Swap Prev/Next (Optimal) for O(N) time.

<br>

---

## Solution 2: Swap Prev/Next (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None — O(N) is optimal.

> **Key Insight for Improvement:** Unlike singly LL reversal (3 pointers), DLL reversal just swaps each node's prev and next. Simpler!

<br>

---

**Key Insights:**
1. **Swap prev↔next for each node:** That's the entire algorithm
2. **Move direction flips:** After swapping, "next" is the old "prev"
3. **Track new head:** Last processed node = new head

<br><br>

---

```code```
