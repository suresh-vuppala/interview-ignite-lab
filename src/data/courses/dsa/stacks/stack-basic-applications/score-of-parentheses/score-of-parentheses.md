Given a balanced parentheses string `s`, return the score of the string.

The score of a balanced parentheses string is based on the following rules:

- `"()"` has score `1`
- `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings
- `(A)` has score `2 * A`, where `A` is a balanced parentheses string

<br>

> Input:
> s = "(()(()))"

> Output:
> 6

> Explanation:
> - Inner "()" = 1
> - "(())" = 2 * 1 = 2
> - Outer layer wraps "() + (())" = 1 + 2 = 3
> - Final wrapping: 2 * 3 = 6
>
> **Key insight:** Use a stack to track scores at each depth level. When we see '(', push current score and reset. When we see ')', calculate score based on nesting.

<br>

---

## Constraints

- `2 ≤ s.length ≤ 50`
- `s` consists of only `'('` and `')'`
- `s` is a balanced parentheses string

<br>

---

## All Possible Edge Cases

1. **Simple pair:** `"()"` → 1
2. **Nested:** `"(())"` → 2
3. **Adjacent:** `"()()"` → 2
4. **Deep nesting:** `"(((())))"` → 8
5. **Mixed:** `"(()(()))"` → 6

<br>

---

## Solution 1: Stack with Score Tracking

**Intuition:**
Use a stack to track scores at each nesting level. When we encounter '(', we start a new frame. When we encounter ')', we compute the value of the current frame and either add it to the parent frame or to the final result if there's no parent.

**Algorithm:**
1. Initialize empty stack and total = 0
2. For each character:
   - If '(': Push 0 to stack (new frame)
   - If ')': 
     - Pop current frame's score (inside)
     - If inside is 0, it means "()" → value = 1
     - Otherwise, it's "(A)" → value = 2 * inside
     - If stack is empty: add value to total (no parent)
     - Otherwise: add value to parent frame's score
3. Return total

**Example walkthrough:**
```
s = "(()(()))"

Stack: []
'(' → Stack: [0]
'(' → Stack: [0, 0]
')' → inside=0, value=1, parent exists → Stack: [1]
'(' → Stack: [1, 0]
'(' → Stack: [1, 0, 0]
')' → inside=0, value=1, parent exists → Stack: [1, 1]
')' → inside=1, value=2*1=2, parent exists → Stack: [3]
')' → inside=3, value=2*3=6, no parent → total=6, Stack: []

Result: 6
```

**Key insight:** The stack tracks unfinished frames. When a frame closes, its value flows either to its parent (if nested) or to the final result (if outermost).

### Time Complexity: O(N)
**Why?**
- Single pass through string
- Each character processed once

### Space Complexity: O(N)
**Why?**
- Stack can grow up to N/2 in worst case (all opening brackets)

<br>

---

## Solution 2: Stack with Depth Tracking

**Intuition:**
Track the depth of nesting. Each "()" at depth d contributes 2^d to the score.

**Algorithm:**
1. Use stack to track depth
2. For each character:
   - If '(': Increment depth
   - If ')': 
     - Check if previous was '(' (means "()")
     - If yes, add 2^depth to score
     - Decrement depth
3. Return total score

### Time Complexity: O(N)
**Why?**
- Single pass through string

### Space Complexity: O(1)
**Why?**
- Only tracking depth and score

<br>

---

## Solution 3: Divide and Conquer (Recursive)

**Intuition:**
Split the string into balanced parts and recursively calculate scores.

**Algorithm:**
1. If string is "(A)", return 2 * score(A)
2. Otherwise, split into balanced parts and sum their scores
3. Base case: "()" returns 1

### Time Complexity: O(N²)
**Why?**
- Need to find balanced splits
- Recursive calls on substrings

### Space Complexity: O(N)
**Why?**
- Recursion stack depth

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|-----------------|
| Stack with Score | O(N) | O(N) | Track scores at each level |
| Stack with Depth | O(N) | O(1) | Use depth to calculate contribution |
| Divide & Conquer | O(N²) | O(N) | Recursive approach |

**Recommended Solution:** Stack with Score Tracking (Solution 1) — O(N) time, clear logic.

**Key Insights:**
1. **Stack pattern:** Perfect for nested structures
2. **Score accumulation:** Each level contributes to parent
3. **Base case:** "()" always contributes 1 at its depth
4. **Doubling rule:** Each wrapping layer doubles the inner score

<br>

---

```code```
