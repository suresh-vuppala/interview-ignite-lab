Given a string containing only '(', ')', '{', '}', '[', ']', determine if the input string is valid. Open brackets must be closed by the same type and in correct order.

<br>

> Input:
> s = "()[]{}"

> Output:
> true

> Explanation:
> Each opening bracket has a matching closing bracket in the correct order.
> 
> **Key insight:** Push opening brackets onto a stack. When a closing bracket appears, the top of the stack must be its matching opening bracket. If not → invalid. Stack must be empty at the end.

<br>



---

## Constraints

- `1 ≤ s.length ≤ 10⁴`
- `s consists of parentheses only: '(){}[]'`

<br>

---

## All Possible Edge Cases

1. **Single character:** Always invalid (no pair)
2. **Nested correctly:** "({[]})" → true
3. **Wrong order:** "([)]" → false (interleaved)
4. **Extra opening:** "((" → false (stack not empty at end)
5. **Extra closing:** "))" → false (stack empty when closing found)
6. **Empty string:** true (vacuously valid)

<br>

---

## Solution 1: Brute Force — Repeatedly Remove Pairs

**Intuition:**
Repeatedly find and remove adjacent matching pairs "()", "[]", "{}". If the string becomes empty → valid.

**Algorithm:**
1. While string contains "()" or "[]" or "{}":
   - Replace all occurrences with ""
2. If string is empty → true, else false

### Time Complexity: O(N²)
**Why?**
- Each replacement pass: O(N) to scan and replace
- Up to N/2 passes (each removes at least one pair)
- Total: O(N²)

**Detailed breakdown:**
- N = 10,000 → up to 5,000 passes × 10,000 = 50,000,000 operations

### Space Complexity: O(N)
**Why?**
- String operations create copies

> **Drawback:**
> Multiple passes over the string. We're rescanning the entire string after each removal. A stack processes each character exactly once.

> **Key Insight for Improvement:**
> Process left to right. Opening brackets: push to stack. Closing brackets: check if stack top matches. If match → pop, if not → invalid. Single pass, O(N).

<br>

---

## Solution 2: Stack — Single Pass (Optimal)

**Intuition:**
Opening brackets are "pending" — push them on the stack. When a closing bracket arrives, the most recent pending opening bracket (stack top) must match it. If not → invalid.

**Algorithm:**
1. Create map: ')' → '(', ']' → '[', '}' → '{'
2. For each char c:
   - If c is opening bracket → push to stack
   - If c is closing bracket:
     - If stack empty → false (no matching opener)
     - If stack.top() ≠ matching opener → false (wrong type)
     - Else → pop (matched pair)
3. Return stack.isEmpty() (any unmatched openers?)

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Each push/pop: O(1)
- Total: O(N)

**Detailed breakdown:**
- N = 10,000 → 10,000 operations

**Example walkthrough:**
```
s = "({[]})"

'(' → push → stack=['(']
'{' → push → stack=['(', '{']
'[' → push → stack=['(', '{', '[']
']' → top='[' matches ']' → pop → stack=['(', '{']
'}' → top='{' matches '}' → pop → stack=['(']
')' → top='(' matches ')' → pop → stack=[]

Stack empty → true ✓

s = "([)]"
'(' → push → ['(']
'[' → push → ['(', '[']
')' → top='[' ≠ '(' → false ✗
```

### Space Complexity: O(N)
**Why?**
- Stack stores at most N/2 opening brackets (worst case: all openers)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Repeated Removal | O(N²) | O(N) | Remove pairs iteratively |
| Stack | O(N) | O(N) | Single pass, match top-of-stack |

**Recommended Solution:** Stack (Solution 2) — O(N) time, O(N) space.

**Key Insights:**
1. **Stack models nesting:** Most recent opener is on top — matches next closer
2. **Three checks:** Stack empty when closing? Top matches? Stack empty at end?
3. **Classic interview question:** Tests stack fundamentals and edge case handling


<br>
<br>

---

```code```
