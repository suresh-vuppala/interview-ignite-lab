String matching and duplicate substring problems using rolling hash.

<br>

> Find pattern in text, longest duplicate substring
>
> **Key insight:** Rabin-Karp: rolling hash for O(1) hash update as window slides. Compare hashes, verify on match.

<br>

---

## Constraints
- 1 ≤ text.length ≤ 10⁵
- 1 ≤ pattern.length ≤ text.length

<br>

---

## Solution 1: Brute force matching

**Intuition:**
The most straightforward approach. Compare pattern at every position.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N×M)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Compare pattern at every position.

> **Key Insight for Improvement:**
> Rolling hash: hash(s[i+1..i+M]) from hash(s[i..i+M-1]) in O(1). Match hash → verify string.

<br>

---

## Solution 2: Rabin-Karp Rolling Hash (Optimal)

**Intuition:** Rabin-Karp: rolling hash for O(1) hash update as window slides. Compare hashes, verify on match.

**Algorithm:**
1. Compute hash of pattern
2. Compute hash of first window in text
3. Slide window: remove leftmost char, add rightmost char → O(1)
4. On hash match: verify actual strings (avoid false positive)

### Time Complexity: O(N+M) average
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
text='aabcabc' pattern='abc': hash('aab')≠hash('abc'), slide→hash('abc')==hash('abc')→verify→match!
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute force matching | O(N×M) | Varies | Baseline |
| Rabin-Karp Rolling Hash | O(N+M) average | O(1) | Optimal |

**Recommended Solution:** Rabin-Karp Rolling Hash

**Key Insights:**
1. **O(1) window update:** Remove old × base^(L-1), shift, add new
2. **Double hash:** Two different (base,mod) pairs reduce false positives
3. **Applications:** Pattern matching, longest repeated substring, plagiarism detection

<br><br>

---

```code```
