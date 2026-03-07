Find the smallest substring of s that contains all characters of t.

<br>

> Input:
> s = "ADOBECODEBANC", t = "ABC"

> Output:
> "BANC"

> Explanation:
> Substrings containing A, B, C:
> - "ADOBEC" (length 6)
> - "ODEBANC" (length 7)
> - "BANC" (length 4) ← minimum
> 
> **Key insight:** Sliding window with two pointers - expand right to find valid window, contract left to minimize.

<br>

---

## Solution 1: Brute Force (Check All Substrings)

**Intuition:**
Generate all possible substrings of s, check if each contains all characters of t.
Track the minimum length substring that satisfies the condition.

**Algorithm:**
1. For each starting position i in s (0 to n-1):
   - For each ending position j (i to n-1):
     - Extract substring s[i..j]
     - Check if it contains all characters of t
     - If yes and length < min_length: update result
2. Return minimum substring found

**Example:**
```
s = "ADOBECODEBANC", t = "ABC"

Check substrings:
"A" → missing B,C
"AD" → missing B,C
...
"ADOBEC" → has A,B,C ✓ (length 6)
"ADOBECO" → has A,B,C ✓ (length 7, worse)
...
"BANC" → has A,B,C ✓ (length 4, best!)
```

### Time Complexity: O(N² × (N + M))
**Why?**
- Generate all substrings: O(N²) substrings
- For each substring:
  - Extract substring: O(N) in worst case
  - Check if contains all chars of t: O(M) to count + O(N) to verify
  - Total per substring: O(N + M)
- Total: O(N²) × O(N + M) = O(N³ + N² × M)

**Detailed breakdown:**
- Outer loop (start): N iterations
- Inner loop (end): N iterations on average
- Character counting: O(M) for t, O(N) for substring
- Total: N × N × (N + M) = O(N³ + N² × M)

### Space Complexity: O(M)
**Why?**
- Store character counts for t: O(M)
- Store character counts for current substring: O(M)
- Few variables: O(1)
- Total: O(M)

**Problem:** Extremely slow for large strings - generates and checks too many invalid substrings.

> **Key Insight for Improvement:**
> We're recounting characters for every substring. Can we maintain counts incrementally? Yes - sliding window!

<br>

---

## Solution 2: Sliding Window (Two Pointers - Optimal)

**Intuition:**
Use two pointers (left and right) to maintain a window.
Expand right pointer to include more characters until window is valid.
Contract left pointer to minimize window while keeping it valid.
Track minimum valid window seen.

**Key Observations:**
1. **Expand Phase:** Move right pointer to find a valid window
2. **Contract Phase:** Move left pointer to minimize valid window
3. **Incremental Counting:** Update character counts as window changes
4. **Validity Check:** Window is valid when it contains all characters of t

**Algorithm:**
1. **Initialize:**
   - Count all characters in t (target counts)
   - Initialize window character counts
   - Set left = 0, right = 0
   - Track: required (unique chars needed), formed (unique chars satisfied)

2. **Expand window (move right):**
   - Add s[right] to window
   - Update window counts
   - If s[right] is in t and count matches: formed++

3. **Contract window (move left) while valid:**
   - Update minimum window if current is smaller
   - Remove s[left] from window
   - Update window counts
   - If s[left] is in t and count drops below target: formed--
   - Move left++

4. **Repeat until right reaches end**

5. Return minimum window

**Example Walkthrough:**
```
s = "ADOBECODEBANC", t = "ABC"
target = {A:1, B:1, C:1}, required = 3

Step 1: right=0, left=0
Window: [A]DOBECODEBANC
window = {A:1}, formed = 1
Not valid (formed < required)

Step 2: right=5, left=0
Window: [ADOBEC]ODEBANC
window = {A:1, D:1, O:1, B:1, E:1, C:1}, formed = 3
Valid! (formed == required)
Try to contract...

Step 3: left=1
Window: A[DOBEC]ODEBANC
window = {D:1, O:1, B:1, E:1, C:1}, formed = 2
Invalid (missing A), stop contracting

Step 4: right=9, left=1
Window: A[DOBECODEBA]NC
window = {D:1, O:2, B:1, E:1, C:1, A:1}, formed = 3
Valid! Try to contract...

Step 5: left=5, right=9
Window: ADOBEC[ODEBA]NC
window = {O:1, D:1, E:1, B:1, A:1}, formed = 2
Invalid (missing C), stop contracting

Step 6: right=12, left=5
Window: ADOBEC[ODEBANC]
window = {O:1, D:1, E:1, B:1, A:1, N:1, C:1}, formed = 3
Valid! Try to contract...

Step 7: left=9, right=12
Window: ADOBECODEB[ANC]
window = {A:1, N:1, C:1}, formed = 2
Invalid (missing B), stop contracting

Step 8: right=12, left=9 (expand complete)
Final contraction:
Window: ADOBECODEBA[NC]
window = {N:1, C:1}, formed = 1
Invalid

Minimum found: "BANC" (length 4)
```

**Implementation Details:**

**Character Counting:**
```cpp
// Count target characters
map<char, int> target, window;
for (char c : t) target[c]++;

int required = target.size();  // Unique chars needed
int formed = 0;                // Unique chars satisfied

// When adding character to window
window[c]++;
if (target.count(c) && window[c] == target[c])
    formed++;

// When removing character from window
if (target.count(c) && window[c] == target[c])
    formed--;
window[c]--;
```

**Window Validity:**
```cpp
// Window is valid when all unique characters satisfied
while (formed == required) {
    // Update minimum window
    if (right - left + 1 < min_length) {
        min_length = right - left + 1;
        result = s.substr(left, min_length);
    }
    
    // Contract window
    char leftChar = s[left];
    if (target.count(leftChar) && window[leftChar] == target[leftChar])
        formed--;
    window[leftChar]--;
    left++;
}
```

### Time Complexity: O(N + M)
**Why linear?**
- Count characters in t: O(M)
- Each character in s visited at most twice:
  - Once by right pointer (expand): O(N)
  - Once by left pointer (contract): O(N)
- Total: O(M) + O(2N) = O(N + M)

**Detailed breakdown:**
- Initialize target map: O(M)
- Right pointer moves: N steps total
- Left pointer moves: N steps total (amortized)
- Each step: O(1) operations (map lookup/update)
- Total: O(M) + O(N) + O(N) = O(N + M)

**Why each character visited at most twice?**
- Right pointer: visits each character once (0 to N-1)
- Left pointer: visits each character once (0 to N-1)
- No character is revisited by same pointer
- Total visits: 2N

### Space Complexity: O(M)
**Why?**
- Target map: stores at most M unique characters from t → O(M)
- Window map: stores at most M unique characters (only chars in t matter) → O(M)
- Few variables (left, right, formed, required): O(1)
- Total: O(M) + O(M) + O(1) = O(M)

**Breakdown:**
- If t has all unique characters: M entries in target map
- Window map only needs to track characters in t
- Even if s has more unique characters, we only care about those in t
- Space is bounded by size of t, not s

**Improvement:** From O(N³ + N² × M) to O(N + M)
- Example: N=10000, M=100
- Brute force: 10000³ + 10000² × 100 ≈ 1,000,000,000,000 operations
- Sliding window: 10000 + 100 = 10,100 operations (100,000,000× faster!)

**Why this is optimal:**
- Must read entire string s at least once: Ω(N)
- Must read entire string t at least once: Ω(M)
- Lower bound: Ω(N + M)
- Our solution: O(N + M)
- Therefore, this is optimal!

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³ + N² × M) | O(M) | Baseline - check all substrings |
| Sliding Window | O(N + M) | O(M) | Incremental counting, two pointers |

**Key Insights:**
1. **Brute Force → Sliding Window:** Recount every substring → maintain counts incrementally
2. **Two Pointers:** Expand to find valid, contract to minimize
3. **Amortized Analysis:** Each character visited at most twice total

**When to use:**
- **Sliding Window:** Always use this - it's optimal for this problem
- Pattern applies to many "minimum/maximum window" problems

> **Final Complexity:** O(N + M) time, O(M) space

<br>

---

## Edge Cases

1. **t longer than s:** Return "" (impossible to contain all characters)
2. **No valid window:** Return "" (s doesn't contain all characters of t)
3. **Entire s is minimum:** Return s (no smaller valid window exists)
4. **Multiple minimum windows:** Return any one (problem doesn't specify)
5. **Duplicate characters in t:** Count all occurrences (e.g., t="AAB" needs 2 A's)
6. **Empty strings:** 
   - If t is empty: return "" (no characters to find)
   - If s is empty: return "" (no window possible)

<br>

---

## Applications

1. **Text Analysis:** Find shortest passage containing all keywords
2. **Bioinformatics:** Find shortest DNA sequence with required bases
3. **Data Mining:** Extract minimal relevant text snippets
4. **Search Engines:** Generate snippets with all query terms
5. **Log Analysis:** Find shortest time window containing all events

<br>
<br>

---

```code```
