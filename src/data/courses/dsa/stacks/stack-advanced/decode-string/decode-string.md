Decode string with pattern k[encoded]: repeat encoded k times.

<br>

> Input: "3[a2[c]]"
> Output: "accaccacc"

<br>

---

## Constraints

- `1 ≤ s.length ≤ 30`
- `1 ≤ k ≤ 300`
- `Nested brackets are valid`

<br>

---

## All Possible Edge Cases

1. **No encoding:** 'abc' → 'abc'
2. **Nested:** '2[a3[b]]' → 'abbbabbb'
3. **Adjacent:** '2[a]3[b]' → 'aabbb'
4. **k = 1:** '1[abc]' → 'abc'

<br>

---

## Solution 1: Stack

**Intuition:**
Use two stacks: one for counts, one for strings. On '[', push current string and count. On ']', pop and repeat.

**Algorithm:**
1. Iterate through characters:
   - Digit → build multi-digit number
   - '[' → push (currentString, count) to stacks, reset both
   - ']' → pop, currentString = poppedString + currentString × count
   - Letter → append to currentString

### Time Complexity: O(maxK × n) where n = output length
### Space Complexity: O(n)

<br>

---

## Solution 2: Recursion

**Intuition:**
Recursively process: when '[' is found, recurse to get inner string, multiply by k.

### Time Complexity: O(maxK × n)
### Space Complexity: O(depth) recursion stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(maxK × n) | O(n) | Iterative with two stacks |
| Recursion | O(maxK × n) | O(depth) | Natural for nested structure |

<br>
<br>

---

```code```
