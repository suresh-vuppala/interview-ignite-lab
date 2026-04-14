Add two numbers represented as linked lists (digits in reverse order).

<br>

> Input: l1 = [2,4,3], l2 = [5,6,4]
> Output: [7,0,8] (342 + 465 = 807)
> **Key insight:** Traverse both lists simultaneously, adding digits + carry. Create new nodes for result. Carry propagates like grade-school addition.

<br>

---

## Constraints
- `1 ≤ N, M ≤ 100`

<br>

---

## Solution 1: Convert to integers, add, convert back

**Intuition:**
The most straightforward approach — integer overflow for very long numbers.

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
> Integer overflow for very long numbers. Digit-by-digit addition handles any length.

> **Key Insight for Improvement:**
> Use Digit-by-Digit Addition with Carry (Optimal) for O(max(N, M)) time.

<br>

---

## Solution 2: Digit-by-Digit Addition with Carry (Optimal)

**Algorithm:** Traverse both lists. sum = l1.val + l2.val + carry. digit = sum%10, carry = sum/10. Create new node with digit.

### Time Complexity: O(max(N, M))
**Why?** Process each digit once. Result has at most max(N,M)+1 digits.

**Detailed breakdown:** N=M=100 → 101 iterations max

### Space Complexity: O(max(N, M)) for result

> **Drawback:** Creates new list. In-place modification possible but messier.

> **Key Insight for Improvement:** Don't forget the final carry! If carry > 0 after both lists exhausted, create one more node.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Digit-by-digit | O(max(N,M)) | O(max(N,M)) |

**Key Insights:**
1. **Reverse order = easy:** Least significant digit first — natural addition order
2. **Carry propagation:** carry = sum / 10, digit = sum % 10
3. **Handle unequal lengths:** Continue with the longer list + carry

<br><br>

---

```code```
