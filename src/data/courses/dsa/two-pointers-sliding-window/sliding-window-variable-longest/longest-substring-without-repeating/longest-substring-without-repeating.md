Find length of longest substring without repeating characters.

<br>

> Input: "abcabcbb" → Output: 3 ("abc")

<br>

---

## Constraints

- `0 ≤ s.length ≤ 5 × 10⁴`

<br>

---

## Solution 1: Brute Force — Check All Substrings

### Time: O(n³) | Space: O(min(n,m))

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Checking all O(n²) substrings, and for each checking O(n) uniqueness = O(n³). Enormous redundancy — when we find a repeat, we start over from next position.
>
> **Insight:** Sliding window with a set. Expand right until repeat found. On repeat, shrink from left until the duplicate is removed. Each character is added/removed at most once.

<br>

---

## Solution 2: Sliding Window + Set

### Time: O(n) | Space: O(min(n,m))

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** When we find a repeat of char c, we shrink left one step at a time until c is removed. This can be slow if the duplicate is far from left.
>
> **Insight:** Use a hash map storing last index of each char. On repeat, JUMP left pointer directly past the previous occurrence. No incremental shrinking needed.

<br>

---

## Solution 3: Sliding Window + HashMap (Optimal)

**Intuition:** Map stores last index of each char. On repeat, jump left past previous occurrence.

### Time: O(n) | Space: O(min(n,m))

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n³) | O(n) | All substrings + uniqueness check |
| Set Window | O(n) | O(n) | Expand/shrink with set |
| Map Window | O(n) | O(n) | Jump left past duplicate |

<br>
<br>
