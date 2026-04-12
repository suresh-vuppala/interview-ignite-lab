Reverse a doubly linked list.

<br>

> Example: 1↔2↔3↔4 → 4↔3↔2↔1
> **Key insight:** Swap prev and next pointers for every node. The last node processed becomes the new head.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## Solution: Swap Prev/Next (Optimal)

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
