Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

<br>

> Input:
> Operations: ["push", 5], ["push", 2], ["push", 7], ["getMin"], ["pop"], ["getMin"]

> Output:
> [null, null, null, 2, 7, 2]

> Explanation:
> - push(5): stack=[5], minStack=[5]
> - push(2): stack=[5,2], minStack=[5,2] (2 is new min)
> - push(7): stack=[5,2,7], minStack=[5,2,2] (2 still min)
> - getMin(): returns 2
> - pop(): removes 7, stack=[5,2], minStack=[5,2]
> - getMin(): returns 2

<br>


---

## Constraints

- `-2³¹ ≤ val ≤ 2³¹ - 1`
- `Methods pop, top, getMin always called on non-empty stack`
- `At most 3 × 10⁴ calls total`

<br>

---

## All Possible Edge Cases

1. **Single element:** Min is that element
2. **Decreasing pushes:** Min updates on every push
3. **Push min, push larger, pop larger:** Min should still be the first pushed
4. **All same elements:** Min is always that value
5. **Pop the minimum element:** Min must update to next minimum
6. **Large negative values:** Min can be INT_MIN

<br>

---

## Solution: Two Stack Approach

Maintain two stacks:
1. Main stack: stores all elements
2. Min stack: stores minimum at each level
3. Push: add to both stacks (min stack gets min(val, current_min))
4. Pop: remove from both stacks
5. GetMin: return top of min stack

**Key insight:** Track minimum at each stack level using auxiliary stack.



<br>

### Time Complexity Analysis

**All Operations: O(1)**
- Push: Two stack pushes → O(1) + O(1) = O(1)
- Pop: Two stack pops → O(1) + O(1) = O(1)
- Top: One stack top → O(1)
- GetMin: One stack top → O(1)

**Why O(1)?**
- No loops or iterations
- Direct stack operations only
- Min tracked incrementally, not computed

**Space Complexity: O(n)**
- Main stack: O(n) for n elements
- Min stack: O(n) for n elements
- Total: O(2n) = O(n)

**Space optimization:**
- Only push to min stack when new minimum found
- Reduces min stack size in practice
- Worst case still O(n) (decreasing sequence)

> **Time Complexity:** O(1) for all operations
> **Space Complexity:** O(n) for two stacks

<br>
<br>

---

---

```code```
