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

## Constraints

- `-10⁷ ≤ val ≤ 10⁷`
- `At most 2 × 10⁴ calls to push, pop, top, peekMax, popMax`

<br>

---

## All Possible Edge Cases

1. **Single element:** Max is that element
2. **All same elements:** popMax removes one, max stays same
3. **Strictly increasing pushes:** Max is always top
4. **Strictly decreasing pushes:** popMax removes bottom-most
5. **popMax then push:** Max may change after popMax
6. **Multiple popMax calls:** Max decreases progressively

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

---

```code```
