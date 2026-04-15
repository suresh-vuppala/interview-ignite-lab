Given a non-negative integer represented as a string, remove k digits to make the number as small as possible.

<br>

> Input: num = "1432219", k = 3
> Output: "1219"

> Explanation: Remove 4, 3, 2 → "1219". This is the smallest possible.
> 
> **Key insight:** Greedy with monotonic increasing stack. When the current digit is smaller than the top of the stack, pop the top (remove that larger digit). This is optimal because removing a larger digit earlier has more impact on the final number.

<br>

---

## Constraints
- `1 ≤ k ≤ num.length ≤ 10⁵`
- num consists of digits only and has no leading zeros (except "0")

<br>

---

## All Possible Edge Cases
1. **K = N: return "0"
2. **K = 0: unchanged
3. **Leading zeros after removal
4. **Already smallest possible (ascending)**

<br>

---

## Solution 1: Brute Force — Try All Combinations

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(C(N,K)) — exponential
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Monotonic Increasing Stack — Greedy (Optimal)

**Algorithm:**
1. stack = []
2. For each digit d in num:
   - While k > 0 and stack and stack.top() > d: stack.pop(), k--
   - Push d
3. While k > 0: stack.pop(), k-- (remove from end)
4. Build result, strip leading zeros
5. Return result or "0" if empty

### Time Complexity: O(N)
**Why?** Each digit pushed/popped at most once.

**Detailed breakdown:** N = 100,000 → at most 200,000 operations

**Example walkthrough:**
```
num = "1432219", k = 3

'1': stack=[1]
'4': 4>1 → push → [1,4]
'3': 3<4 → pop 4, k=2 → [1,3]
'2': 2<3 → pop 3, k=1 → [1,2]
'2': 2==2 → push → [1,2,2]
'1': 1<2 → pop 2, k=0 → [1,2,1]
'9': push → [1,2,1,9]

k=0, no more removals.
Result: "1219" ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(C(N,K)) | O(N) | Try all combinations |
| Monotonic Stack | O(N) | O(N) | Greedy: remove larger digits first |

**Key Insights:**
1. **Greedy principle:** Removing a larger digit at an earlier position has the most impact
2. **Monotonic increasing:** Stack maintains increasing order — pops create smaller numbers
3. **Edge cases:** Leading zeros, k ≥ num.length → "0"

<br><br>

---

```code```
