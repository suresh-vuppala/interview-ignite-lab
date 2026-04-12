Check if a linked list is a palindrome.

<br>

> Input: head = [1,2,2,1]
> Output: true
> **Key insight:** Find middle → reverse second half → compare with first half. O(1) space (modifies list but can restore).

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## Solution 1: Copy to Array + Two Pointers — O(N) space

> **Drawback:** O(N) extra space for the array copy.

> **Key Insight for Improvement:** Find middle (slow/fast), reverse second half in-place, compare halves. O(1) extra space.

<br>

---

## Solution 2: Reverse Second Half (Optimal)

**Algorithm:**
1. Find middle using slow/fast
2. Reverse the second half
3. Compare first half with reversed second half
4. (Optional: restore the list by re-reversing)

### Time Complexity: O(N)
**Why?** Finding middle: O(N). Reverse: O(N/2). Compare: O(N/2). Total: O(N).

**Detailed breakdown:** N = 100,000 → ~200,000 operations

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array copy | O(N) | O(N) | Copy to array, two pointers |
| Reverse half | O(N) | O(1) | In-place comparison |

**Key Insights:**
1. **Three techniques combined:** Slow/fast (middle) + reverse (second half) + compare
2. **Odd length handled:** Middle node doesn't need comparison
3. **Restore optional:** If list must remain unmodified, re-reverse after comparison

<br><br>

---

```code```
