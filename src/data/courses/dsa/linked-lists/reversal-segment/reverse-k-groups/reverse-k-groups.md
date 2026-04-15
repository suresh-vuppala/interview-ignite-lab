Reverse nodes in k-group segments. If remaining nodes < k, leave them as-is.

<br>

> Input: head = [1,2,3,4,5], k=2
> Output: [2,1,4,3,5]
> **Key insight:** For each group of k nodes: check if k nodes exist, reverse them, connect to previous group. Repeat. The last group with < k nodes stays unchanged.

<br>

---

## Constraints
- `1 ≤ k ≤ N ≤ 5000`

<br>

---

## All Possible Edge Cases
1. **K = 1:** no change
2. **K = N:** single full reverse
3. **Last group smaller than K:** leave as-is
4. **K > N:** no reversal**

<br>

---

## Solution 1: Recursive with array copy per group

**Intuition:**
The most straightforward approach — array-based reversal per group adds unnecessary space overhead.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(K) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Array-based reversal per group adds unnecessary space overhead.

> **Key Insight for Improvement:**
> Use Iterative Group Reversal (Optimal) for O(N) time.

<br>

---

## Solution 2: Iterative Group Reversal (Optimal)

**Algorithm:**
1. Dummy node. groupPrev = dummy.
2. While there are k nodes ahead: find kth node, save next group start, reverse the group, reconnect (groupPrev.next = reversed head, old head.next = next group). Update groupPrev.

### Time Complexity: O(N)
**Why?** Each node reversed at most once. Counting k nodes: amortized O(N) total.

**Detailed breakdown:** N = 5000 → 5000 pointer operations

### Space Complexity: O(1)

> **Drawback:** Complex pointer management — easy to make off-by-one errors.

> **Key Insight for Improvement:** Helper function to count k nodes ahead simplifies the logic. Recursive version is cleaner but uses O(N/k) stack space.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Iterative | O(N) | O(1) |
| Recursive | O(N) | O(N/k) |

**Key Insights:**
1. **Check k nodes exist first:** Don't reverse partial group at the end
2. **Reconnection:** groupPrev → reversed head, old head → next group start
3. **FAANG hard:** Tests precise pointer manipulation under pressure

<br><br>

---

```code```
