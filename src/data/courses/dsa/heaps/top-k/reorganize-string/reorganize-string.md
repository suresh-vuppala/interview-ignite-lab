Rearrange string so no two adjacent characters are the same. Return empty if impossible.

<br>

> s='aab' → 'aba'
>
> **Key insight:** Impossible if any character's frequency > (N+1)/2. Greedy with max-heap: always place the most frequent character, then the second most, alternating.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Try all permutations

### Time Complexity: O(N!)

> **Drawback:**
> Brute-force permutation checking is exponential.

> **Key Insight for Improvement:**
> Max-heap by frequency. Pop most frequent, place it. Pop second most frequent, place it. Push both back with decremented counts. Ensures no adjacent duplicates.

<br>

---

## Solution 2: Max-Heap Greedy (Optimal)

**Intuition:** Impossible if any character's frequency > (N+1)/2. Greedy with max-heap: always place the most frequent character, then the second most, alternating.

**Algorithm:**
1. Count frequencies. If any freq > (N+1)/2 → impossible
2. Max-heap of (freq, char)
3. While heap has ≥ 2 elements:
   - Pop top two (most frequent)
   - Append both to result
   - Push back with freq-1 (if freq > 0)
4. If one element left, append it

### Time Complexity: O(N log 26) = O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
s='aaabb' → freq: a:3, b:2. (3+1)/2=2, 3>2? No, len=5, (5+1)/2=3. OK.
Heap: [(3,a),(2,b)]
Pop a(3),b(2)→result='ab', push a(2),b(1)
Pop a(2),b(1)→result='abab', push a(1)
Pop a(1)→result='ababa' ✓
```

### Space Complexity: O(26) = O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all permutations | O(N!) | Varies | Baseline |
| Max-Heap Greedy | O(N log 26) = O(N) | O(26) = O(1) | Max-heap by frequency. Pop most frequent, place it. Pop seco |

**Recommended Solution:** Max-Heap Greedy — O(N log 26) = O(N) time, O(26) = O(1) space.

**Key Insights:**
1. **Feasibility check:** maxFreq > (N+1)/2 → impossible
2. **Greedy: most frequent first:** Reduces the "pressure" of dominant character
3. **Two at a time:** Popping two ensures they're different

<br>
<br>

---

```code```
