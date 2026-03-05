Design a stack that supports push, pop, top, and retrieving the maximum element in constant time.

Implement the MaxStack class:
- `push(x)`: Push element x onto stack
- `pop()`: Remove and return the top element
- `top()`: Get the top element
- `getMax()`: Retrieve the maximum element in O(1)

<br>

> Input:
> Operations: ["push", 5], ["push", 1], ["push", 5], ["getMax"], ["pop"], ["getMax"]

> Output:
> [null, null, null, 5, 5, 5]

> Explanation:
> - push(5): Stack = [5], Max = 5
> - push(1): Stack = [5, 1], Max = 5
> - push(5): Stack = [5, 1, 5], Max = 5
> - getMax(): Returns 5
> - pop(): Returns 5, Stack = [5, 1], Max = 5
> - getMax(): Returns 5
> 
> **Key insight:** Maintain a parallel max stack that tracks maximum at each level.

<br>

---

## Solution: Two Stack Approach

Use two stacks:
1. **Main stack:** Stores all elements
2. **Max stack:** Stores maximum element at each level

**Operations:**
- `push(x)`: Push x to main, push max(x, maxStack.top()) to max stack
- `pop()`: Pop from both stacks
- `top()`: Return main stack top
- `getMax()`: Return max stack top

**Key insight:** Track maximum at each stack level using auxiliary stack.

```code```

<br>

### Time Complexity Analysis

**All Operations: O(1)**
- Push: Two stack pushes → O(1) + O(1) = O(1)
- Pop: Two stack pops → O(1) + O(1) = O(1)
- Top: One stack peek → O(1)
- GetMax: One stack peek → O(1)

**Why O(1)?**
- No loops or iterations
- Direct stack operations only
- Max tracked incrementally, not computed

**Space Complexity: O(n)**
- Main stack: O(n) for n elements
- Max stack: O(n) for n elements
- Total: O(2n) = O(n)

**Comparison with Min Stack:**
- Same approach, just track max instead of min
- Both use two-stack technique
- Both achieve O(1) for all operations

> **Time Complexity:** O(1) for all operations
> **Space Complexity:** O(n) for two stacks

<br>
<br>

---
