Introduction to string hashing concepts and applications.

<br>

> Hash functions map strings to integers for O(1) comparison
>
> **Key insight:** Rolling hash: h = (h × base + char) % mod. Enables O(1) hash update when sliding window moves.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Direct string comparison

### Time Complexity: O(L) per comparison

> **Drawback:**
> Comparing strings character by character.

> **Key Insight for Improvement:**
> Hash comparison: O(1) after O(L) preprocessing. But handle collisions (false positives).

<br>

---

## Solution 2: Rolling Hash (Optimal)

**Intuition:** Rolling hash: h = (h × base + char) % mod. Enables O(1) hash update when sliding window moves.

**Algorithm:**
hash(s) = sum(s[i] × base^(L-1-i)) % mod
Sliding: remove leftmost char contribution, add new rightmost char

### Time Complexity: O(L) build, O(1) update
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
hash('abc') = a×26² + b×26 + c (mod large prime)
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Direct string comparison | O(L) per comparison | Varies | Baseline |
| Rolling Hash | O(L) build, O(1) update | O(1) | Optimal |

**Recommended Solution:** Rolling Hash

**Key Insights:**
1. **O(1) comparison:** Hash equality → likely string equality
2. **Collision handling:** Double hash or verify on match
3. **Applications:** Rabin-Karp, duplicate detection, rolling comparisons

<br><br>

---

```code```
