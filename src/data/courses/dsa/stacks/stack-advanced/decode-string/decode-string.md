Given an encoded string, decode it according to the pattern `k[encoded_string]`, where the `encoded_string` inside brackets is repeated exactly `k` times.

<br>

> Input:
> s = "3[a2[c]]"

> Output:
> "accaccacc"

> Explanation:
> The encoded string is `"3[a2[c]]"`.
> - Inner bracket: `2[c]` = `"cc"`
> - Substitute: `3[acc]`
> - Outer bracket: `3[acc]` = `"accaccacc"`
> 
> **Key insight:** Process nested brackets from inside out using stacks.

<br>

> Input:
> s = "2[abc]3[cd]ef"

> Output:
> "abcabccdcdcdef"

> Explanation:
> - `2[abc]` = `"abcabc"`
> - `3[cd]` = `"cdcdcd"`
> - Concatenate with "ef": `"abcabccdcdcdef"`

<br>

---

## Solution: Two Stack Approach

Use two stacks:
1. **Count stack:** Store repeat counts
2. **String stack:** Store strings before brackets

**Algorithm:**
1. For each character:
   - **Digit:** Build number (can be multi-digit)
   - **`[`:** Push current count and string to stacks, reset both
   - **`]`:** Pop count and previous string, repeat current string count times, append to previous
   - **Letter:** Append to current string
2. Return final string

**Key insight:** Stacks handle nested brackets naturally.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(maxK × n)**
- Process each character once: O(n)
- For each `]`, repeat string: O(k × length)
- Worst case: Nested brackets multiply counts
- Example: "3[2[a]]" → "aaaaaa" (3 × 2 = 6 operations)

**Why two stacks?**
- Count stack: Track how many times to repeat
- String stack: Track what came before current bracket
- Together: Handle arbitrary nesting depth

**Space Complexity: O(n)**
- Two stacks hold at most n/2 elements each
- Current string and result string: O(n)
- Decoded output can be larger than input

**Handling multi-digit numbers:**
- "10[a]" → k = 10, not k = 1
- Build number: k = k × 10 + digit

> **Time Complexity:** O(maxK × n) - depends on repeat counts
> **Space Complexity:** O(n) - stack and string storage

<br>
<br>

---
