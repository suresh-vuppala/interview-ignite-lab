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

## All Possible Edge Cases
1. **Single node:** palindrome
2. **Two nodes same value:** palindrome
3. **Two nodes different:** not palindrome
4. **Odd vs even length palindromes**

<br>

---

## Solution 1: Copy to Array + Two Pointers — O(N) space

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
