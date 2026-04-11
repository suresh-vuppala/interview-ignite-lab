Given an array, find the next greater element for each element. The next greater element of x is the first element to its right that is larger than x. If none exists, output -1.

<br>

> Input:
> nums = [4, 5, 2, 25]

> Output:
> [5, 25, 25, -1]

> Explanation:
> 4→5 (next greater), 5→25, 2→25, 25→-1 (nothing greater to its right).
> 
> **Key insight:** Use a monotonic decreasing stack of indices. When a new element is larger than the stack top, it IS the next greater element for everything it "defeats." Pop all smaller elements and assign them.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Sorted ascending:** Each element's NGE is the next one; last is -1
2. **Sorted descending:** All are -1
3. **All same:** All are -1
4. **Single element:** -1

<br>

---

## Solution 1: Brute Force — Scan Right for Each

**Intuition:**
For each element, scan all elements to its right. Return the first one that's larger.

### Time Complexity: O(N²)
**Why?**
- For each of N elements, scan up to N elements right

**Detailed breakdown:**
- N = 10,000 → up to 50,000,000 comparisons

### Space Complexity: O(1) extra

> **Drawback:**
> For each element, we scan right from scratch. When we find that element X has NGE = Y, we discard the information about everything between X and Y. Elements between X and Y that are smaller than Y also have NGE = Y — but we'll rediscover this by scanning again.

> **Key Insight for Improvement:**
> Process right-to-left (or use a stack). Keep a monotonic decreasing stack. When a new element nums[i] is larger than the stack top, it's the NGE for the top. Pop all smaller elements (they've found their NGE). Push nums[i]. Each element pushed/popped at most once → O(N).

<br>

---

## Solution 2: Monotonic Decreasing Stack (Optimal)

**Intuition:**
Stack holds indices of elements waiting for their NGE. When a new element is larger than the stack top, it resolves the top's NGE. Pop and assign. Continue until stack top is larger or stack is empty. Then push the new element.

**Algorithm:**
1. Initialize stack, result array filled with -1
2. For i = 0 to n-1:
   - While stack not empty and nums[i] > nums[stack.top()]:
     - idx = stack.pop()
     - result[idx] = nums[i] (found NGE for idx)
   - stack.push(i)
3. Remaining stack elements have no NGE → already -1

### Time Complexity: O(N)
**Why?**
- Each element pushed exactly once, popped at most once
- Total: ≤ 2N operations

**Detailed breakdown:**
- N = 10,000 → at most 20,000 stack operations

**Example walkthrough:**
```
nums = [4, 5, 2, 25]
stack = [], result = [-1, -1, -1, -1]

i=0(4): stack empty → push 0 → stack=[0]
i=1(5): 5 > nums[0]=4 → pop 0, result[0]=5 → stack=[]
         push 1 → stack=[1]
i=2(2): 2 < nums[1]=5 → push 2 → stack=[1, 2]
i=3(25): 25 > nums[2]=2 → pop 2, result[2]=25
         25 > nums[1]=5 → pop 1, result[1]=25
         stack empty → push 3 → stack=[3]

Remaining: stack=[3] → result[3]=-1 (already set)
Result: [5, 25, 25, -1] ✓
```

### Space Complexity: O(N)
**Why?**
- Stack holds at most N elements

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Scan right for each element |
| Monotonic Stack | O(N) | O(N) | Each element pushed/popped once |

**Recommended Solution:** Monotonic Stack (Solution 2) — O(N) time.

**Key Insights:**
1. **Monotonic decreasing stack:** Stack maintains elements waiting for their NGE, in decreasing order
2. **New element resolves:** A larger incoming element is the NGE for all smaller stack elements
3. **Pattern family:** NGE, Next Smaller, Previous Greater, Previous Smaller — all use monotonic stacks


<br>
<br>

---

```code```
