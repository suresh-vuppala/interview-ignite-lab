Given an encoded string like "3[a2[c]]", decode it. The pattern is k[encoded_string] where the encoded_string is repeated k times.

<br>

> Input: s = "3[a2[c]]"
> Output: "accaccacc"

> Explanation: 2[c] = "cc". a + "cc" = "acc". 3["acc"] = "accaccacc".
> 
> **Key insight:** Use a stack. Push current string and count when hitting '['. Pop and repeat when hitting ']'. The stack handles nesting naturally.

<br>

---

## Constraints
- `1 ≤ s.length ≤ 30`
- Digits are for repeat counts only

<br>

---

## Solution 1: Stack (Optimal)

**Intuition:** Build current string. When '[' encountered: save current state (string + count) on stack, reset. When ']': pop previous state, multiply current string by count, append to previous string.

**Algorithm:**
1. stack = [], currentStr = "", currentNum = 0
2. For each char:
   - Digit: currentNum = currentNum * 10 + digit
   - '[': push (currentStr, currentNum), reset both
   - ']': pop (prevStr, count), currentStr = prevStr + currentStr × count
   - Letter: currentStr += char
3. Return currentStr

### Time Complexity: O(N × maxK)
**Why?** Each character processed once. String repetition depends on the repeat factor.

**Detailed breakdown:** Output length can be up to ~10⁵ with nesting.

**Example walkthrough:**
```
s = "3[a2[c]]"

'3' → num=3
'[' → push("", 3), reset → str="", num=0
'a' → str="a"
'2' → num=2
'[' → push("a", 2), reset → str="", num=0
'c' → str="c"
']' → pop("a", 2), str = "a" + "c"×2 = "acc"
']' → pop("", 3), str = "" + "acc"×3 = "accaccacc"

Result: "accaccacc" ✓
```

### Space Complexity: O(N) for stack depth

> **Drawback:**
> Recursive approach without explicit stack can be harder to manage with deeply nested brackets and tricky edge cases.

> **Key Insight for Improvement:**
> Stack-based iteration: push current string and multiplier on '[', pop and build on ']'. Clean O(N) with explicit state management.


<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(output length) | O(N) | Stack handles nesting naturally |

**Key Insights:**
1. **Stack saves context:** '[' pushes current state, ']' restores it
2. **Nesting handled naturally:** Inner brackets resolve first, outer uses the result
3. **Alternative: Recursion:** Same logic but uses call stack instead of explicit stack

<br><br>

---

```code```
