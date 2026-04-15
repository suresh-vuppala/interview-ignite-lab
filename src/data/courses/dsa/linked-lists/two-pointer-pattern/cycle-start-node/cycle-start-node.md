Find the node where the cycle begins in a linked list.

<br>

> Input: head = [3,2,0,-4], tail connects to node index 1
> Output: node with value 2
> **Key insight:** After Floyd's detection (slow meets fast), move one pointer back to head. Advance both by 1 step. They meet at the cycle start. Mathematical proof: distance from head to cycle start = distance from meeting point to cycle start (going around).

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **No cycle:** return null
2. **Cycle starts at head**
3. **Long tail before cycle**
4. **Single node self-loop**

<br>

---

## Solution 1: Hash Set

**Intuition:**
The most straightforward approach — store all visited nodes in hash set.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Store all visited nodes in hash set. First revisited = cycle start. Uses O(N) extra space.

> **Key Insight for Improvement:**
> Use Floyd's + Phase 2 (Optimal) for O(N) time.

<br>

---

## Solution 2: Floyd's + Phase 2 (Optimal)

**Algorithm:**
1. Phase 1: Detect cycle using slow/fast. Find meeting point.
2. Phase 2: Move one pointer to head. Both advance 1 step. Meeting point = cycle start.

### Time Complexity: O(N)
### Space Complexity: O(1)

**Example walkthrough:**
```
3 → 2 → 0 → -4 → (back to 2)

Phase 1: slow/fast meet at some node inside cycle.
Phase 2: ptr1=head(3), ptr2=meeting point. Both advance 1 step.
They meet at node 2 = cycle start ✓
```

> **Drawback:** None — O(N) time, O(1) space is optimal.

> **Key Insight for Improvement:** Math proof: let a = distance from head to cycle start, b = distance from cycle start to meeting point, c = cycle length. At meeting: slow traveled a+b, fast traveled a+b+c. Since fast=2×slow: a+b+c=2(a+b) → c=a+b → a=c-b. So distance from head to cycle start = distance from meeting point to cycle start (around the cycle).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Hash Set | O(N) | O(N) |
| Floyd's Phase 2 | O(N) | O(1) |

**Key Insights:**
1. **Two phases:** Detect meeting → find start
2. **Mathematical guarantee:** a = c - b (provable)
3. **Both advance by 1:** After phase 1, slow pointer or fast pointer resets to head

<br><br>

---

```code```
