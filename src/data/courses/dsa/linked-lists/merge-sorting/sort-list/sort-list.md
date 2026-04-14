Sort a linked list in O(N log N) time and O(1) space.

<br>

> Input: head = [4,2,1,3]
> Output: [1,2,3,4]
> **Key insight:** Merge sort on linked list. Find middle (slow/fast), split, recursively sort both halves, merge. O(N log N) time, O(log N) stack space (or O(1) with bottom-up).

<br>

---

## Constraints
- `0 ≤ N ≤ 5 × 10⁴`

<br>

---

## Solution 1: Copy to array, sort, rebuild

**Intuition:**
The most straightforward approach — extra o(n) space for array.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N log N) + O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Extra O(N) space for array. Merge sort on list uses O(log N) stack only.

> **Key Insight for Improvement:**
> Use Merge Sort (Optimal for linked list) for O(N log N) time.

<br>

---

## Solution 2: Merge Sort (Optimal for linked list)

**Algorithm:**
1. Base case: empty or single node → return
2. Find middle using slow/fast. Split into two halves.
3. Recursively sort both halves.
4. Merge two sorted halves.

### Time Complexity: O(N log N)
**Why?** log N levels of recursion, each level processes N nodes total.

**Detailed breakdown:** N = 50,000 → ~50,000 × 16 ≈ 800,000 comparisons

### Space Complexity: O(log N) recursion stack

> **Drawback:** O(log N) stack space from recursion. Bottom-up merge sort achieves O(1) space but is more complex.

> **Key Insight for Improvement:** Linked list merge sort is BETTER than array merge sort because merging is O(1) space (just rewire pointers, no auxiliary array needed).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Merge Sort (top-down) | O(N log N) | O(log N) | Split + merge |
| Merge Sort (bottom-up) | O(N log N) | O(1) | Iterative doubling |

**Key Insights:**
1. **Split at middle:** Use first-middle variant so left half is ≤ right half
2. **Merge reuses nodes:** No extra memory for merging (unlike array merge sort)
3. **Why not quicksort?** Random pivot selection on linked list is O(N), making quicksort O(N²) worst case

<br><br>

---

```code```
