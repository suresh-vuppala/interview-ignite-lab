Check if string is palindrome considering only alphanumeric, ignoring case.

<br>

> Input: "A man, a plan, a canal: Panama" → Output: true

<br>

---

## Constraints

- `1 ≤ s.length ≤ 2 × 10⁵`

<br>

---

## Solution 1: Filter + Reverse

**Intuition:** Clean string (lowercase, alphanumeric only), compare with reverse.

### Time: O(n) | Space: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Creates a new cleaned string — O(n) extra space. We don't need to build the cleaned string at all.
>
> **Insight:** Two pointers from both ends. Skip non-alphanumeric characters. Compare lowercase characters in-place. No extra string needed.

<br>

---

## Solution 2: Two Pointers In-Place (Optimal)

**Intuition:** Left and right pointers. Skip junk. Compare toLower characters.

### Time: O(n) | Space: O(1)

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Filter + Reverse | O(n) | O(n) | Build clean string |
| Two Pointers | O(n) | O(1) | Skip junk in-place |

<br>
<br>
