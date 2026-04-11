Given a non-negative integer represented as a string and an integer k, remove k digits from the number to get the smallest possible number.

<br>

> Input:
> num = "1432219", k = 3

> Output:
> "1219"

> Explanation:
> Remove digits to get smallest number:
> 
> Process with stack:
> - '1': stack = [1]
> - '4': 4 > 1, push → stack = [1, 4]
> - '3': 3 < 4, remove 4 (k=2) → stack = [1, 3]
> - '2': 2 < 3, remove 3 (k=1) → stack = [1, 2]
> - '2': 2 = 2, push → stack = [1, 2, 2]
> - '1': 1 < 2, but k=0, push → stack = [1, 2, 2, 1]
> - '9': 9 > 1, push → stack = [1, 2, 2, 1, 9]
> 
> Wait, let me recalculate:
> - Remove '4', '3', '2' → "1219" is smallest

<br>


---

## Constraints

- `1 ≤ k ≤ num.length ≤ 10⁵`
- `num consists of digits 0-9 only`
- `num does not have leading zeros`

<br>

---

## All Possible Edge Cases

1. **k = num.length:** Return '0'
2. **k = 0:** Return original
3. **Increasing digits:** Remove last k digits
4. **Decreasing digits:** Remove first k digits
5. **Leading zeros after removal:** '10200' k=1 → '200'
6. **Result is all zeros:** Return '0'
7. **All same digits:** Remove any k → remaining digits

<br>

---

## Solution: Greedy Stack Approach

Approach:
1. Use stack to build result
2. For each digit, remove larger digits from stack top (while k > 0)
3. Push current digit
4. If k remains, remove from end
5. Remove leading zeros

**Greedy choice:** Remove digit if next digit is smaller, to minimize number.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Iterate through n digits once
- For each digit:
  - While loop removes from stack: each digit pushed/popped at most once
  - Amortized O(1) per digit
- Total: O(n)

**Stack Operations:**
- Each digit is pushed exactly once: O(n)
- Each digit is popped at most once: O(n)
- Total operations: O(2n) = O(n)

**Post-processing: O(n)**
- Remove remaining k digits: O(k) ≤ O(n)
- Remove leading zeros: O(n)
- Build final string: O(n)

**Overall: O(n)**
- Linear in length of input string
- Each digit processed constant number of times

**Why this works:**
- Greedy choice: If current digit < top of stack, removing top makes number smaller
- Stack maintains increasing sequence when possible
- This ensures smallest lexicographic number

> **Time Complexity:** O(n) - single pass with amortized constant operations
> **Space Complexity:** O(n) - stack to store result digits

<br>
<br>

---
