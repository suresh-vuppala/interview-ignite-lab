Check if typed string could be long-pressed version of name.

<br>

> Input: name="alex", typed="aaleex" → true

<br>

---

## Solution 1: Two Pointers

**Intuition:** i for name, j for typed. If chars match, advance both. If typed[j] matches typed[j-1] (long press), advance j only. Otherwise false.

### Time: O(n+m) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Pointers | O(n+m) | O(1) | Match or long-press check |

<br>
<br>
