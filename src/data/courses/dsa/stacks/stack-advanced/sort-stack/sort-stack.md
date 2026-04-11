Sort a stack such that the smallest elements are on the top. You can only use one additional stack.

<br>

> Input: stack = [5, 1, 3, 2, 4] (top=4)
> Output: stack = [5, 4, 3, 2, 1] (top=1)

> Explanation: Sort so smallest is on top, using only one extra stack.
> 
> **Key insight:** Use auxiliary stack as "sorted output." For each element from input, pop from aux and push back to input until the right position is found. Insertion sort using two stacks.

<br>

---

## Constraints
- Stack contains integers

<br>

---

## Solution 1: Auxiliary Stack — Insertion Sort (Optimal with constraint)

**Intuition:** Move elements to auxiliary stack in sorted order. For each element from input: while aux.top() > current, move back to input. Then push current to aux.

**Algorithm:**
1. While input not empty:
   - temp = input.pop()
   - While aux not empty and aux.top() > temp: input.push(aux.pop())
   - aux.push(temp)
2. Move all from aux back to input (or aux IS the result)

### Time Complexity: O(N²)
**Why?** Each element may cause up to N moves. Total: N × N = O(N²).

**Detailed breakdown:** N = 100 → up to 10,000 operations

### Space Complexity: O(N) — one auxiliary stack

> **Drawback:** O(N²) time. Without the constraint of "only one extra stack," we could sort in O(N log N).

> **Key Insight for Improvement:** With only one extra stack, O(N²) is the best possible (equivalent to insertion sort). With recursion allowed, merge sort on stacks achieves O(N log N).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Aux Stack Sort | O(N²) | O(N) | Insertion sort with two stacks |

**Key Insights:**
1. **Insertion sort analogy:** Find correct position in sorted aux stack
2. **Move-back trick:** Temporarily move elements back to input to make room
3. **Constraint-driven:** One extra stack → O(N²) is optimal

<br><br>

---

```code```
