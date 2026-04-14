Reverse a string using a stack.

<br>

> Input:
> s = "hello"

> Output:
> "olleh"

> Explanation:
> Push each character: h→e→l→l→o. Pop each: o→l→l→e→h. Reversed!
> 
> **Key insight:** Stack's LIFO property naturally reverses order. Push all characters, then pop all.

<br>



---

## Constraints

- `1 ≤ s.length ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Single character:** Returns itself
2. **Palindrome:** Returns the same string
3. **Empty string:** Returns empty

<br>

---

## Solution 1: Two-Pointer Swap (No Stack)

**Intuition:**
The most straightforward approach. While optimal, this doesn't demonstrate stack usage.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> While optimal, this doesn't demonstrate stack usage. The problem specifically asks for a stack-based solution.

> **Key Insight for Improvement:**
> Push all characters onto a stack, then pop all. LIFO order gives us the reverse. O(N) time, O(N) space — but demonstrates the stack reversal pattern.

<br>

---

## Solution 2: Stack — Push All, Pop All

**Intuition:**
Push every character onto the stack. Pop them all off — LIFO gives reversed order.

**Algorithm:**
1. For each char c in s: stack.push(c)
2. result = ""
3. While stack not empty: result += stack.pop()
4. Return result

### Time Complexity: O(N)
**Why?**
- Push N characters: O(N)
- Pop N characters: O(N)
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 100,000 → 200,000 stack operations

**Example walkthrough:**
```
s = "hello"

Push: stack = [h, e, l, l, o] (o on top)
Pop:  o → l → l → e → h
Result: "olleh" ✓
```

### Space Complexity: O(N)
**Why?**
- Stack stores all N characters

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two-Pointer | O(N) | O(1) | In-place swaps |
| Stack | O(N) | O(N) | LIFO reversal pattern |

**Recommended Solution:** Stack (Solution 2) for learning; Two-Pointer for production.

**Key Insights:**
1. **LIFO = Reversal:** Stacks naturally reverse order
2. **Pattern:** Push-all-then-pop-all is the fundamental stack reversal
3. **Applications:** Reversing linked lists, expression evaluation, undo operations


<br>
<br>

---

```code```
