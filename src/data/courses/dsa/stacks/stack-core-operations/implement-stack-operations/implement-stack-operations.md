Implement a stack data structure with all core operations: push, pop, peek, isEmpty, and size.

<br>

> Input:
> Operations: ["push", 5], ["push", 10], ["peek"], ["pop"], ["peek"]

> Output:
> [null, null, 10, 10, 5]

> Explanation:
> - push(5): Stack = [5]
> - push(10): Stack = [5, 10]
> - peek(): Returns 10 (top element)
> - pop(): Removes and returns 10, Stack = [5]
> - peek(): Returns 5 (new top element)

<br>

---

## Solution: Array-Based Stack Implementation

Use array with top pointer to track last element:
1. Push: Add element at top+1, increment top
2. Pop: Return element at top, decrement top
3. Peek: Return element at top without removing
4. isEmpty: Check if top == -1
5. Size: Return top + 1

**Key insight:** Stack follows LIFO (Last In First Out) principle.

```code```

<br>

### Time Complexity Analysis

**All Operations: O(1)**
- Push: Direct array access at index top+1
- Pop: Direct array access at index top
- Peek: Direct array access at index top
- isEmpty: Simple comparison
- Size: Return stored value

**Why O(1)?**
- No loops or iterations needed
- Direct index-based access
- Constant time operations only

**Space Complexity: O(n)**
- Array of size n to store elements
- Additional O(1) for top pointer
- Total: O(n) for n elements

> **Time Complexity:** O(1) for all operations
> **Space Complexity:** O(n) for storing n elements

<br>
<br>

---