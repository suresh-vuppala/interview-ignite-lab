Compare two strings where '#' means backspace.

<br>

> Input: s="ab#c", t="ad#c" → true (both become "ac")

<br>

---

## Solution 1: Stack — Build Processed Strings

### Time: O(n+m) | Space: O(n+m)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** O(n+m) space for stacks/strings. We're materializing the final strings unnecessarily.
>
> **Insight:** Process from RIGHT to LEFT. Count '#' characters to know how many to skip. Compare final characters without building strings.

<br>

---

## Solution 2: Two Pointers from End (Optimal)

**Intuition:** Scan both strings from right. Count backspaces. Skip that many chars. Compare.

### Time: O(n+m) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(n+m) | O(n+m) | Build processed strings |
| Two Ptr RTL | O(n+m) | O(1) | Count and skip from right |

<br>
<br>
