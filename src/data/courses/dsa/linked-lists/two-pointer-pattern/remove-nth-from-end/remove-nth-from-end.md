Remove the nth node from the end of a linked list.

<br>

> Input: head = [1,2,3,4,5], n=2
> Output: [1,2,3,5]
> **Key insight:** Two pointers with n-gap. Advance fast n steps ahead. Then advance both until fast reaches end. Slow is at the node BEFORE the target.

<br>

---

## Constraints
- `1 ≤ N ≤ 30`, `1 ≤ n ≤ N`

<br>

---

## All Possible Edge Cases
1. **Remove head (N = length)**
2. **Remove tail (N = 1)**
3. **Single node, N = 1**
4. **N > length: invalid**

<br>

---

## Solution 1: Two-Pass — Count then traverse

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

## Solution 2: Two Pointers with N-Gap (Optimal)

**Algorithm:** Dummy node. fast = dummy, advance n+1 steps. slow = dummy. Advance both until fast = null. slow.next = slow.next.next (skip target).

### Time Complexity: O(N)
### Space Complexity: O(1)

**Example walkthrough:**
```
dummy → 1 → 2 → 3 → 4 → 5, n=2

fast advances 3 steps: dummy → 1 → 2 → 3
slow at dummy. Both advance:
  slow=1, fast=4
  slow=2, fast=5
  slow=3, fast=null → stop

slow.next = slow.next.next → skip 4
Result: 1 → 2 → 3 → 5 ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Passes |
|----------|------|-------|--------|
| Two-pass | O(N) | O(1) | 2 |
| Two-pointer gap | O(N) | O(1) | 1 |

**Key Insights:**
1. **N-gap technique:** Fast leads by n → when fast finishes, slow is at position N-n
2. **Dummy node:** Handles removing head (n=length) cleanly
3. **n+1 gap:** Slow ends one node BEFORE target for easy deletion

<br><br>

---

```code```
