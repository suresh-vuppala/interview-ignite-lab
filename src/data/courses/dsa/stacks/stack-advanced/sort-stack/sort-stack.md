Given a stack, sort it in ascending order. You can use additional data structures.

<br>

> Input:
> stack = [34, 3, 31, 98, 92, 23] (top = 23)

> Output:
> [3, 23, 31, 34, 92, 98] (top = 98)

> Explanation:
> The stack should be sorted such that the smallest element is at the bottom and the largest at the top.
> 
> **Key insight:** We need to maintain stack property (LIFO) while sorting elements.

<br>


---

## Constraints

- `1 ≤ stack.size ≤ 5000`
- `-10⁴ ≤ stack[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Already sorted:** Stack unchanged
2. **Reverse sorted:** Maximum work needed
3. **Single element:** Already sorted
4. **Two elements:** Swap if needed
5. **All same elements:** No swaps needed
6. **Negative values:** Sort works the same way

<br>

---

## Solution 1: Using Temporary Stack

**Intuition:**
Use an auxiliary stack to hold sorted elements. Pop elements from input stack and insert them in correct position in the temporary stack. Finally, transfer back to original stack.

**Algorithm:**
1. Create a temporary stack
2. While input stack is not empty:
   - Pop element from input stack
   - While temp stack is not empty AND top of temp > current element:
     - Pop from temp and push to input
   - Push current element to temp
3. Transfer all elements from temp back to input stack

### Time Complexity: O(n²)
**Why quadratic?**
- Outer loop: n iterations (one per element)
- Inner loop: worst case n comparisons per element
- Example: Sorted input [1,2,3,4,5] → each element needs to go through all previous
- Total operations: 1 + 2 + 3 + ... + n = n(n+1)/2 ≈ O(n²)

**Detailed breakdown:**
- First element: 0 comparisons
- Second element: up to 1 comparison
- Third element: up to 2 comparisons
- nth element: up to n-1 comparisons
- Total: O(n²)

### Space Complexity: O(n)
**Why?**
- Temporary stack: stores up to n elements → O(n)
- No recursion, just iterative approach
- Total: O(n)

**Problem:** Quadratic time makes it slow for large inputs.

> **Key Insight for Improvement:**
> Using recursion, we can leverage the call stack as implicit storage, eliminating the need for an explicit temporary stack.

<br>

---

## Solution 2: Recursive Approach

**Intuition:**
Use recursion to pop all elements, then insert each element back in sorted order. The recursion call stack acts as temporary storage.

**Recurrence Relation:**
```
sortStack(stack):
  if stack is empty: return
  temp = pop(stack)
  sortStack(stack)
  insertSorted(stack, temp)

insertSorted(stack, element):
  if stack is empty OR top(stack) <= element:
    push(stack, element)
  else:
    temp = pop(stack)
    insertSorted(stack, element)
    push(stack, temp)
```

**Algorithm:**
1. Base case: If stack empty, return
2. Pop top element and store it
3. Recursively sort remaining stack
4. Insert popped element in sorted position using insertSorted
5. insertSorted recursively finds correct position

### Time Complexity: O(n²)
**Why quadratic?**
- sortStack called n times (once per element)
- Each call triggers insertSorted
- insertSorted worst case: O(n) operations
- Total: n × n = O(n²)

**Detailed breakdown:**
- Sorting 1st element: 1 operation
- Sorting 2nd element: 2 operations
- Sorting nth element: n operations
- Total: 1 + 2 + 3 + ... + n = O(n²)

**Example trace for [3, 1, 2]:**
- Pop 2, sort [3,1], insert 2 → [1,2,3]
- Pop 1, sort [3], insert 1 → [1,3]
- Pop 3, sort [], insert 3 → [3]

### Space Complexity: O(n)
**Why?**
- Recursion call stack: O(n) depth for sortStack
- Recursion call stack: O(n) depth for insertSorted
- Maximum depth: O(n) (calls don't overlap completely)
- No additional data structures
- Total: O(n)

**Breakdown:**
- sortStack depth: n levels
- insertSorted depth: n levels (worst case)
- But they're nested, not additive
- Total stack frames at any time: O(n)

> **Key Insight for Improvement:**
> If we can use additional data structures like arrays, we can achieve O(n log n) time using efficient sorting algorithms.

<br>

---

## Solution 3: Using Array and Sorting

**Intuition:**
Transfer stack elements to an array, sort the array using an efficient algorithm (like quicksort or mergesort), then push back to stack in reverse order.

**Algorithm:**
1. Pop all elements from stack to array
2. Sort array using built-in sort (typically O(n log n))
3. Push elements back to stack in reverse order (largest first)

### Time Complexity: O(n log n)
**Why logarithmic factor?**
- Transfer to array: O(n)
- Sort array: O(n log n) (using efficient sorting)
- Transfer back: O(n)
- Total: O(n) + O(n log n) + O(n) = O(n log n)

**Detailed breakdown:**
- Pop n elements: n operations
- Sort using quicksort/mergesort: n log n comparisons
- Push n elements: n operations
- Dominant term: O(n log n)

**Improvement:**
- Before: O(n²)
- After: O(n log n)
- Example: n = 1000
  - O(n²): 1,000,000 operations
  - O(n log n): ~10,000 operations (100× faster!)

### Space Complexity: O(n)
**Why?**
- Array to store elements: O(n)
- Sorting space (depends on algorithm):
  - Quicksort: O(log n) average
  - Mergesort: O(n)
- Total: O(n)

**Breakdown:**
- Array storage: n elements
- Sorting auxiliary space: varies by algorithm
- No recursion stack for main function
- Total: O(n)

> **Key Insight for Improvement:**
> For very large datasets that don't fit in memory, we can use external sorting techniques or priority queues for streaming data.

<br>

---

## Solution 4: Using Priority Queue (Min Heap)

**Intuition:**
Use a min heap to automatically maintain sorted order. Pop all elements into heap, then pop from heap back to stack (heap gives smallest first, so push in reverse).

**Algorithm:**
1. Create a min heap (priority queue)
2. Pop all elements from stack and add to heap
3. Pop all elements from heap and push to temporary stack
4. Transfer from temporary stack to original stack

### Time Complexity: O(n log n)
**Why?**
- Insert n elements into heap: n × log n = O(n log n)
- Extract n elements from heap: n × log n = O(n log n)
- Transfer operations: O(n)
- Total: O(n log n) + O(n log n) + O(n) = O(n log n)

**Detailed breakdown:**
- Each heap insertion: O(log n) for heapify
- n insertions: n × log n
- Each heap extraction: O(log n) for heapify
- n extractions: n × log n
- Total: 2n log n ≈ O(n log n)

### Space Complexity: O(n)
**Why?**
- Heap storage: n elements → O(n)
- Temporary stack: n elements → O(n)
- Total: O(n) + O(n) = O(n)

**Breakdown:**
- Priority queue: stores all n elements
- Temporary stack: stores all n elements
- Both exist simultaneously
- Total: 2n ≈ O(n)

**Advantage:** Works well for streaming data where elements arrive over time.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Temporary Stack | O(n²) | O(n) | Baseline - simple but slow |
| Recursive | O(n²) | O(n) | No extra stack, uses call stack |
| Array + Sort | O(n log n) | O(n) | Efficient sorting - best for static data |
| Priority Queue | O(n log n) | O(n) | Heap-based - good for streaming |

**Key Insights:**
1. **Temporary Stack → Recursive:** Use call stack instead of explicit stack
2. **Recursive → Array Sort:** Allow extra structures for better time complexity
3. **Array Sort → Priority Queue:** Heap maintains order automatically

**When to use each:**
- **Temporary Stack:** Simple implementation, small datasets
- **Recursive:** When recursion is required, no extra structures allowed
- **Array + Sort:** Best general solution, allows efficient sorting
- **Priority Queue:** Streaming data, online sorting, need min/max access

> **Recommended Solution:** Array + Sort (O(n log n) time, O(n) space)

<br>
<br>

---

```code```
