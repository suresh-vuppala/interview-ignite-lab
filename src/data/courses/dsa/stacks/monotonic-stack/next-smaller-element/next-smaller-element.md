For each element in array, find the next smaller element to its right. If no smaller element exists, return -1.

<br>

> Input:
> arr = [4, 8, 5, 2, 25]

> Output:
> [2, 5, 2, -1, -1]

> Explanation:
> - arr[0]=4: Next smaller is 2 (at index 3)
> - arr[1]=8: Next smaller is 5 (at index 2)
> - arr[2]=5: Next smaller is 2 (at index 3)
> - arr[3]=2: No smaller element → -1
> - arr[4]=25: No smaller element → -1

<br>


---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Strictly increasing:** All answers are -1
2. **Strictly decreasing:** Each element's NSE is the next element
3. **All same:** All answers are -1
4. **Single element:** [-1]
5. **Negative numbers:** Smaller can be more negative

<br>

---

## Solution: Monotonic Stack

Use monotonic increasing stack (traverse right to left):
1. Traverse array from right to left
2. Pop elements ≥ current element
3. Top of stack is next smaller (or -1 if empty)
4. Push current element

**Key insight:** Stack maintains increasing order from bottom to top.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Each element pushed once: n pushes
- Each element popped at most once: n pops
- Total: 2n = O(n)

**Space Complexity: O(n)**
- Stack can hold all elements in worst case
- Example: increasing sequence [1,2,3,4,5]

> **Time Complexity:** O(n)
> **Space Complexity:** O(n)

<br>
<br>

---
