Design a stack that supports push, pop, top, and retrieving the minimum element — all in O(1) time.

<br>

> MinStack minStack = new MinStack();
> minStack.push(-2); minStack.push(0); minStack.push(-3);
> minStack.getMin(); // returns -3
> minStack.pop();
> minStack.getMin(); // returns -2

<br>

---

## Constraints

- `-2³¹ ≤ val ≤ 2³¹ - 1`
- `At most 3 × 10⁴ calls total`

<br>

---

## All Possible Edge Cases

1. **Single element:** Min is that element
2. **Decreasing pushes:** Min updates every push
3. **Pop the minimum:** Min must update to next minimum

<br>

---

## Solution 1: Two Stacks

**Intuition:**
Main stack for values, auxiliary stack tracking minimum at each level.

**Algorithm:**
- Push: push to main; push min(val, minStack.top) to minStack
- Pop: pop both stacks
- GetMin: minStack.top()

### Time Complexity: O(1) all operations
### Space Complexity: O(n) — two stacks

<br>

---

## Solution 2: Single Stack with Pairs

**Intuition:**
Store (value, current_minimum) pairs. Each entry knows what the minimum was when it was pushed.

### Time Complexity: O(1) all operations
### Space Complexity: O(n)

<br>

---

## Solution 3: Single Stack + Encoding (Optimal Space)

**Intuition:**
Store the difference between value and current min. When popping, reconstruct the previous minimum.

- Push: if val < min, push (val - oldMin), update min = val
- Pop: if top < 0, previous min = min - top, update min
- GetMin: return min variable

### Time Complexity: O(1) all operations
### Space Complexity: O(n) but no auxiliary stack — slightly more space-efficient

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Stacks | O(1) | O(2n) | Auxiliary min stack |
| Pairs | O(1) | O(2n) | Store (val, min) tuples |
| Encoding | O(1) | O(n) | Encode min delta — no extra stack |

<br>
<br>

---

```code```
