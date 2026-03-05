A **Stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle. The element inserted last is the first one to be removed.

**Basic Operations:**
- `push(x)`: Add element to top - O(1)
- `pop()`: Remove and return top element - O(1)
- `peek()/top()`: View top element without removing - O(1)
- `isEmpty()`: Check if stack is empty - O(1)
- `size()`: Get number of elements - O(1)

## Input
```
Operations: push(5), push(10), push(15), pop(), peek()
```

## Output
```
Stack after operations: [5, 10]
Popped: 15
Top element: 10
```

## Explanation

**Step-by-step execution:**
1. `push(5)`: Stack = [5]
2. `push(10)`: Stack = [5, 10]
3. `push(15)`: Stack = [5, 10, 15]
4. `pop()`: Returns 15, Stack = [5, 10]
5. `peek()`: Returns 10, Stack = [5, 10] (unchanged)

## Implementation Approaches

**1. Array-based Stack:**
- Use array with top pointer
- Fixed or dynamic size
- O(1) operations

**2. Linked List-based Stack:**
- Use singly linked list
- Head is the top
- Dynamic size, O(1) operations

**3. Built-in Stack:**
- Java: `Stack<>` or `Deque<>`
- C++: `stack<>`
- Python: `list` (use append/pop)

## Time Complexity Analysis

**All Operations: O(1)**

**push(x):** O(1)
- Add to top/end of array or list head

**pop():** O(1)
- Remove from top/end of array or list head

**peek():** O(1)
- Access top element directly

**Space Complexity:** O(n)
- Store n elements

**Why O(1) is optimal:**
- Stack only accesses top element
- No traversal needed for any operation
