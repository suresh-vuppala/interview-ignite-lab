Generate all letter combinations from phone number digit mapping.

<br>

> digits='23' → ['ad','ae','af','bd','be','bf','cd','ce','cf']
>
> **Key insight:** Backtracking: for each digit, try all mapped letters (2→abc, 3→def, etc.). Recurse to next digit.

<br>

---

## Constraints
- 0 ≤ digits.length ≤ 4
- digits[i] ∈ {'2'-'9'}

<br>

---

## Solution 1: Same — backtracking IS the approach

**Intuition:**
The most straightforward approach. Can't avoid — must generate all combinations.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(4^N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Can't avoid — must generate all combinations.

> **Key Insight for Improvement:**
> Backtracking: at each digit position, try all 3-4 mapped letters.

<br>

---

## Solution 2: Backtracking (Optimal)

**Intuition:** Backtracking: for each digit, try all mapped letters (2→abc, 3→def, etc.). Recurse to next digit.

**Algorithm:**
1. Map: 2→abc, 3→def, ..., 9→wxyz
2. backtrack(index, current):
3. If index == len(digits): add current
4. For each letter mapped to digits[index]:
   - Append letter, recurse(index+1), remove

### Time Complexity: O(4^N × N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
digits='23': digit 2→try a,b,c. For 'a'→digit 3→try d,e,f → 'ad','ae','af'
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same — backtracking IS the approach | O(4^N) | Varies | Baseline |
| Backtracking | O(4^N × N) | O(N) | Optimal |

**Recommended Solution:** Backtracking

**Key Insights:**
1. **3-4 branches per digit:** 7 and 9 have 4 letters, others have 3
2. **Total: 3^N to 4^N combinations**
3. **LeetCode 17:** Classic introductory backtracking

<br><br>

---

```code```
