For each element in an array, find the next greater element to its right. If no greater element exists, return -1.

<br>

> Input:
> arr = [4, 5, 2, 10, 8]

> Output:
> [5, 10, 10, -1, -1]

> Explanation:
> - arr[0]=4: Next greater is 5 (at index 1)
> - arr[1]=5: Next greater is 10 (at index 3)
> - arr[2]=2: Next greater is 10 (at index 3)
> - arr[3]=10: No greater element, return -1
> - arr[4]=8: No greater element, return -1
> 
> Stack process (traverse right to left):
> - i=4: stack=[], result[4]=-1, push 8 → stack=[8]
> - i=3: stack=[8], 10>8 pop, stack=[], result[3]=-1, push 10 → stack=[10]
> - i=2: stack=[10], 2<10, result[2]=10, push 2 → stack=[10,2]
> - i=1: stack=[10,2], 5>2 pop, 5<10, result[1]=10, push 5 → stack=[10,5]
> - i=0: stack=[10,5], 4<5, result[0]=5, push 4 → stack=[10,5,4]

<br>


---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Strictly decreasing:** All answers are -1
2. **Strictly increasing:** Each element's NGE is the next element, last is -1
3. **Single element:** [-1]
4. **All same:** [5,5,5] → [-1,-1,-1]
5. **Two elements:** [1,2] → [2,-1]
6. **Negative numbers:** NGE still works by value comparison

<br>

---

## Solution: Monotonic Stack

Use a monotonic decreasing stack (traverse right to left):
1. Traverse array from right to left
2. Pop elements from stack that are ≤ current element
3. Top of stack is next greater element (or -1 if empty)
4. Push current element to stack

**Key insight:** Stack maintains elements in decreasing order from bottom to top.



<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Traverse array once: n iterations
- Each element:
  - Pushed to stack exactly once: O(1)
  - Popped from stack at most once: O(1)
- Total push operations: n
- Total pop operations: at most n
- Overall: O(n + n) = O(2n) = O(n)

**Amortized Analysis:**
- While loop may seem like O(n) per element
- But each element is popped at most once across all iterations
- Amortized O(1) per element

**Why monotonic stack?**
- Maintains useful elements (potential next greater)
- Discards useless elements (smaller than current)
- Avoids nested loops: O(n) instead of O(n²)

**Comparison with brute force:**
- Brute force: O(n²) - for each element, scan right
- Monotonic stack: O(n) - single pass with stack

> **Time Complexity:** O(n) - each element pushed and popped at most once
> **Space Complexity:** O(n) - stack can hold all elements in worst case

<br>
<br>

---

---

```code```
