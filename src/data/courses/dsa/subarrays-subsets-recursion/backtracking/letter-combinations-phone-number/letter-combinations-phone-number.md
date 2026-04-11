Generate all possible letter combinations from a phone number's digit sequence.

<br>

> Input:
> digits = "23"

> Output:
> ["ad","ae","af","bd","be","bf","cd","ce","cf"]

> Explanation:
> Digit 2 maps to "abc", digit 3 maps to "def"
> All combinations: a+d, a+e, a+f, b+d, b+e, b+f, c+d, c+e, c+f
> 
> **Key insight:** Backtracking - for each digit, try all its letters, recurse for remaining digits.

<br>


---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

---

## Solution: Backtracking with Digit Mapping

**Intuition:**
Build combinations character by character.
For each digit, try all possible letters it maps to.
Recurse to next digit after adding each letter.
When all digits processed, add combination to result.

**Phone Keypad Mapping:**
```
2 → "abc"
3 → "def"
4 → "ghi"
5 → "jkl"
6 → "mno"
7 → "pqrs"
8 → "tuv"
9 → "wxyz"
```

**Algorithm:**
1. Create digit-to-letters mapping
2. Start with index=0, current=""
3. Base case: if index == digits.length, add current to result
4. Get letters for current digit
5. For each letter:
   - Append letter to current
   - Recurse for next digit (index+1)
   - Remove letter (backtrack)

**Example Walkthrough:**
```
digits = "23"
mapping: 2→"abc", 3→"def"

backtrack(0, ""):
  Digit '2' → letters "abc"
  
  Try 'a': current="a"
    backtrack(1, "a"):
      Digit '3' → letters "def"
      
      Try 'd': current="ad"
        backtrack(2, "ad"):
          index==2, add "ad" ✓
      
      Try 'e': current="ae"
        backtrack(2, "ae"):
          index==2, add "ae" ✓
      
      Try 'f': current="af"
        backtrack(2, "af"):
          index==2, add "af" ✓
  
  Try 'b': current="b"
    backtrack(1, "b"):
      Digit '3' → letters "def"
      
      Try 'd': current="bd"
        backtrack(2, "bd"):
          index==2, add "bd" ✓
      
      Try 'e': current="be"
        backtrack(2, "be"):
          index==2, add "be" ✓
      
      Try 'f': current="bf"
        backtrack(2, "bf"):
          index==2, add "bf" ✓
  
  Try 'c': current="c"
    backtrack(1, "c"):
      Digit '3' → letters "def"
      
      Try 'd': current="cd"
        backtrack(2, "cd"):
          index==2, add "cd" ✓
      
      Try 'e': current="ce"
        backtrack(2, "ce"):
          index==2, add "ce" ✓
      
      Try 'f': current="cf"
        backtrack(2, "cf"):
          index==2, add "cf" ✓

Result: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Recursion Tree:**
```
                    ""
            /       |       \
          "a"      "b"      "c"
        / | \    / | \    / | \
      ad ae af  bd be bf  cd ce cf
```

**Visual Representation:**
```
Digit:  2        3
        ↓        ↓
       abc      def

Combinations:
a → d, e, f  →  ad, ae, af
b → d, e, f  →  bd, be, bf
c → d, e, f  →  cd, ce, cf
```

### Time Complexity: O(4^N × N)
**Why?**
- N = number of digits
- Each digit: 3-4 letters (7 and 9 have 4)
- Worst case: 4^N combinations
- Each combination: O(N) to build string
- Total: O(4^N × N)

**Detailed breakdown:**
- Digit 2-6,8: 3 letters each
- Digit 7,9: 4 letters each
- Example "23": 3 × 3 = 9 combinations
- Example "79": 4 × 4 = 16 combinations
- Example "2379": 3 × 3 × 4 × 4 = 144 combinations

### Space Complexity: O(N)
**Why?**
- Recursion stack: O(N) for N digits
- Current string: O(N)
- Mapping array: O(1) constant size
- Total: O(N)

<br>

---

## Implementation Approaches

**Approach 1: String Concatenation**
```cpp
void backtrack(digits, index, current, result, mapping) {
    if (index == digits.length()) {
        result.add(current)
        return
    }
    
    string letters = mapping[digits[index]]
    for (char c : letters) {
        backtrack(digits, index+1, current+c, result, mapping)
    }
}
```

**Approach 2: StringBuilder (More Efficient)**
```cpp
void backtrack(digits, index, current, result, mapping) {
    if (index == digits.length()) {
        result.add(current.toString())
        return
    }
    
    string letters = mapping[digits[index]]
    for (char c : letters) {
        current.append(c)
        backtrack(digits, index+1, current, result, mapping)
        current.deleteCharAt(current.length()-1)  // Backtrack
    }
}
```

**Approach 3: Iterative (BFS-style)**
```cpp
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {}
    
    vector<string> result = {""}
    
    for (char digit : digits) {
        vector<string> temp
        string letters = mapping[digit]
        
        for (string combination : result) {
            for (char letter : letters) {
                temp.push_back(combination + letter)
            }
        }
        result = temp
    }
    
    return result
}
```

<br>

---

## Key Insights

1. **Cartesian Product:** Essentially computing cartesian product of letter sets
2. **Fixed Depth:** Recursion depth equals number of digits
3. **No Pruning:** All combinations valid, no early termination
4. **Order Matters:** Different from combinations (order significant)

**Common Mistakes:**
- Forgetting to handle empty input (return [])
- Not backtracking when using StringBuilder
- Wrong mapping (0 and 1 have no letters)
- Not handling digits "0" or "1" properly

<br>

---

## Edge Cases

1. **Empty string:** "" → []
2. **Single digit:** "2" → ["a","b","c"]
3. **With 7 or 9:** "7" → ["p","q","r","s"] (4 letters)
4. **Long input:** "2345" → 3×3×3×3 = 81 combinations
5. **Invalid digits:** "01" → handle or ignore

<br>

---

## Comparison: Recursive vs Iterative

| Aspect | Recursive | Iterative |
|--------|-----------|-----------|
| Code | More intuitive | More complex |
| Space | O(N) stack | O(4^N) intermediate |
| Time | O(4^N × N) | O(4^N × N) |
| Readability | Better | Harder to understand |

<br>

---

## Optimization: Early Return

```cpp
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};  // Early return
    
    vector<string> result;
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", 
                        "mno", "pqrs", "tuv", "wxyz"};
    
    backtrack(digits, 0, "", result, mapping);
    return result;
}
```

<br>

---

## Real-World Variations

**1. T9 Predictive Text:**
Filter combinations by dictionary words.
**Time:** O(4^N × N × D) where D = dictionary lookup

**2. Generate N Combinations:**
Stop after generating N combinations.
**Time:** O(N × M) where M = avg string length

**3. Lexicographic Order:**
Already achieved by iterating letters in order.

**4. With Wildcards:**
Some digits can be any letter.
Increases branching factor.

<br>

---

## Applications

1. **Phone Keypad:** T9 predictive text input
2. **Password Generation:** Combinations from patterns
3. **Cryptography:** Brute force key generation
4. **Testing:** Generate test cases from patterns
5. **Game Development:** Word puzzles, anagram games

<br>
<br>

---

```code```
