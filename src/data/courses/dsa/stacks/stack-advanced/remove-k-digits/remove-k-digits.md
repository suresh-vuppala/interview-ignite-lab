Remove k digits from number to make it smallest possible. Return result as string without leading zeros.

<br>

> Input:
> num = "1432219", k = 3

> Output:
> "1219"

> Explanation:
> Remove digits 4, 3, 2 to get smallest number.
> - Original: 1432219
> - Remove 4: 132219 (4 > 3, remove it)
> - Remove 3: 12219 (3 > 2, remove it)
> - Remove 2: 1219 (first 2 > 2, remove it)
> 
> **Key insight:** Remove larger digits that appear before smaller digits.

<br>

> Input:
> num = "10200", k = 1

> Output:
> "200"

> Explanation:
> Remove leading 1 to get smallest: 0200 → "200" (remove leading zeros)

<br>

---

## Solution: Monotonic Increasing Stack

Use monotonic increasing stack:
1. For each digit:
   - While stack top > current digit and k > 0: pop and decrement k
   - Push current digit
2. Remove remaining k digits from end
3. Remove leading zeros
4. Return result (or "0" if empty)

**Key insight:** Keep digits in increasing order to minimize number.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Iterate through n digits: O(n)
- Each digit:
  - Pushed once: O(1)
  - Popped at most once: O(1)
- Total operations: 2n (push + pop) = O(n)

**Why monotonic stack works?**
- Want smallest number → keep increasing sequence
- When see smaller digit, remove larger digits before it
- Greedy approach: Remove largest digits first

**Space Complexity: O(n)**
- Stack holds at most n digits
- Result string: O(n-k)

**Edge cases:**
- All digits removed: Return "0"
- Leading zeros: Must remove them
- k = 0: Return original number
- Increasing sequence: Remove from end

> **Time Complexity:** O(n) - single pass with stack
> **Space Complexity:** O(n) - stack storage

<br>
<br>

---