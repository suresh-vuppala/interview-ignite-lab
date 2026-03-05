Given a stack, sort it using recursion. You are not allowed to use any loop constructs or additional data structures.

<br>

> Input:
> stack = [34, 3, 31, 98, 92, 23] (top = 23)

> Output:
> [3, 23, 31, 34, 92, 98] (top = 98)

> Explanation:
> The input stack is `[34, 3, 31, 98, 92, 23]` (top = 23).
> - Pop all elements recursively until stack is empty
> - While returning, insert each element in sorted position
> - Insert operation also uses recursion
> 
> **Step-by-step:**
> - Pop 23, sort remaining, insert 23 in sorted position
> - Pop 92, sort remaining, insert 92 in sorted position
> - Continue until base case (empty stack)
> - Build sorted stack from bottom up

<br>

---

## Solution: Recursive Sort with Insertion

Use two recursive functions:

**sortStack(stack):**
1. Base case: If stack empty, return
2. Pop top element
3. Recursively sort remaining stack
4. Insert popped element in sorted position

**insertSorted(stack, element):**
1. Base case: If stack empty or top < element, push element
2. Pop top, recursively insert element
3. Push back the popped top

**Key insight:** Recursion call stack acts as temporary storage.

```code```

<br>

### Time Complexity Analysis

**Overall: O(n²)**

**Recursive Sort: O(n²)**
- sortStack called n times (once per element)
- Each call triggers insertSorted
- insertSorted worst case: O(n) comparisons
- Total: n × n = O(n²)

**Why O(n²)?**
- For each element, may need to traverse entire stack
- Example: Reverse sorted input requires max comparisons
- No loops allowed, so can't use O(n log n) algorithms

**Space Complexity: O(n)**
- Recursion call stack depth: O(n)
- sortStack: O(n) depth
- insertSorted: O(n) depth
- Total: O(n) (not O(n²) as calls don't overlap)

**Why recursion-only constraint matters:**
- With loops + extra stack: Could use O(n log n) merge sort
- Recursion-only: Limited to O(n²) insertion sort approach
- Trade-off: Simplicity vs efficiency

> **Time Complexity:** O(n²) - nested recursive calls
> **Space Complexity:** O(n) - recursion call stack

<br>
<br>

---
