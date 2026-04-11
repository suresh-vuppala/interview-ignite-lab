Find the celebrity (known by all, knows no one) in O(n) time.

<br>

---

## Solution 1: Brute Force — Check all pairs O(n²)
## Solution 2: Two-Pass Elimination (Optimal)

**Pass 1:** Eliminate non-celebrities by comparing pairs. If A knows B, A is not celebrity. If A doesn't know B, B is not celebrity. Reduces to one candidate.
**Pass 2:** Verify the candidate.

### Time Complexity: O(n)
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check knows() for all pairs |
| Elimination | O(n) | O(1) | Each comparison eliminates one |

<br>
<br>

---

```code```
