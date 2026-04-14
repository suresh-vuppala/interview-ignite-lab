Find the intersection node of two singly linked lists.

<br>

> Input: listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], intersection at node 8
> Output: node with value 8
> **Key insight:** Two pointers starting at each head. When one reaches end, redirect to other list's head. They meet at intersection (or both reach null if no intersection).

<br>

---

## Constraints
- `1 ≤ N, M ≤ 3 × 10⁴`

<br>

---

## Solution 1: Hash Set — O(N+M) time, O(N) space

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Initialize a hash set/map for tracking
2. Iterate through each element
3. Check against the hash set/map for the required condition
4. Update the hash set/map with the current element

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

## Solution 2: Two Pointers — Length Equalization (Optimal)

### Time Complexity: O(N + M)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** Math: pA travels lenA + lenB, pB travels lenB + lenA. Both travel the same total distance → meet at intersection.

<br>

---

**Key Insights:**
1. **Redirect trick:** Equalizes the distance both pointers travel
2. **No intersection:** Both reach null simultaneously
3. **O(1) space:** No hash set needed

<br><br>

---

```code```
