Design a stack that supports push, pop, top, and retrieving the minimum element, all in O(1) time.

<br>

> Input:
> push(-2), push(0), push(-3), getMin(), pop(), top(), getMin()

> Output:
> -3, 0, -2

> Explanation:
> After push -2,0,-3: min=-3. Pop removes -3. Top is 0. Min is now -2.
> 
> **Key insight:** Maintain a parallel stack that tracks the minimum at each level. When you push, also push min(newVal, currentMin) onto the min stack.

<br>



---

## Constraints

- `-2³¹ ≤ val ≤ 2³¹ - 1`
- pop, top, getMin always called on non-empty stack
- At most 3 × 10⁴ operations

<br>

---

## All Possible Edge Cases

1. **Duplicate minimums:** Push same minimum twice — both must be tracked
2. **Push then immediate pop:** Min reverts to previous
3. **All same values:** Min is always that value
4. **Descending order:** Each push updates the minimum

<br>

---

## Solution 1: Two Stacks — Main + Min Stack

**Intuition:**
Two stacks in sync. Main stack holds values. Min stack holds the current minimum at that "level" of the stack. Every push, the min stack gets min(val, currentMin). Every pop, both stacks pop.

**Algorithm:**
- push(val): main.push(val), minStack.push(min(val, minStack.top()))
- pop(): main.pop(), minStack.pop()
- top(): return main.top()
- getMin(): return minStack.top()

### Time Complexity: O(1) per operation
**Why?**
- push: Two push operations — O(1)
- pop: Two pop operations — O(1)
- top: O(1) — direct access
- getMin: O(1) — direct access to min stack top

**Detailed breakdown:**
- 30,000 operations → 60,000 stack operations total (2× overhead)

### Space Complexity: O(N)
**Why?**
- Two stacks of N elements each = 2N space

> **Drawback:**
> Stores a min value for EVERY element, even when the min doesn't change. If we push 1000 elements all greater than the current min, the min stack has 1000 copies of the same value.

> **Key Insight for Improvement:**
> Only push to the min stack when a NEW minimum (or equal) is found. Pop from min stack only when the popped main value equals the min stack top. Saves space when many pushes don't change the min.

<br>

---

## Solution 2: Optimized Min Stack — Push Min Only When Needed

**Intuition:**
Push to min stack only when val ≤ current min. Pop from min stack only when main stack's popped value == min stack top. This saves space but both approaches are O(1) per operation.

**Algorithm:**
- push(val): main.push(val). If val ≤ minStack.top() → minStack.push(val)
- pop(): val = main.pop(). If val == minStack.top() → minStack.pop()
- top(): return main.top()
- getMin(): return minStack.top()

### Time Complexity: O(1) per operation
### Space Complexity: O(N) worst case, but often less in practice

**Example walkthrough:**
```
push(-2): main=[-2], min=[-2]
push(0):  main=[-2,0], min=[-2] (0 > -2, don't push to min)
push(-3): main=[-2,0,-3], min=[-2,-3] (-3 ≤ -2, push to min)
getMin(): min.top() = -3 ✓
pop():    main pops -3, -3 == min.top() → min pops → min=[-2]
top():    main.top() = 0 ✓
getMin(): min.top() = -2 ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Stacks | O(1) all ops | O(2N) | Min value at every level |
| Optimized Min | O(1) all ops | O(N) avg | Only store when min changes |

**Recommended Solution:** Two Stacks (Solution 1) — simpler, always correct, same Big-O.

**Key Insights:**
1. **Parallel tracking:** Each stack level "remembers" its minimum
2. **Why not just scan for min?** Would make getMin O(N) — we need O(1)
3. **Pair encoding alternative:** Store (val, currentMin) pairs in a single stack


<br>
<br>

---

```code```
