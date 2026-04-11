Given a string s, find the length of the longest substring without repeating characters.

<br>

> Input:
> s = "abcabcbb"

> Output:
> 3

> Explanation:
> "abc" is the longest substring without repeating characters. Length = 3.
> 
> **Key insight:** Expand window right. When a duplicate is found, shrink from left until the window is valid again. A hash map tracking the last index of each character lets us jump the left pointer directly.

<br>



---

## Constraints

- `0 ≤ s.length ≤ 5 × 10⁴`
- `s consists of English letters, digits, symbols, and spaces`

<br>

---

## All Possible Edge Cases

1. **Empty string:** Return 0
2. **All unique:** "abcdef" → length = 6
3. **All same:** "aaaa" → length = 1
4. **Single character:** "a" → length = 1
5. **Duplicate at end:** "abcda" → "abcd" length = 4

<br>

---

## Solution 1: Brute Force — Check All Substrings

**Intuition:**
Try every possible substring. For each, check if all characters are unique.

**Algorithm:**
1. For each start i:
   - For each end j > i:
     - Check if s[i..j] has all unique characters (use a set)
     - Update maxLen

### Time Complexity: O(N³)
**Why?**
- O(N²) substrings × O(N) to check each for uniqueness

**Detailed breakdown:**
- N = 50,000 → 50,000³ = 1.25 × 10¹⁴ — far too slow

### Space Complexity: O(min(N, 128))
**Why?**
- Set stores at most all unique ASCII characters

> **Drawback:**
> Checking each substring from scratch — O(N) per substring × O(N²) substrings = O(N³). When we extend a valid substring by one character, we only need to check if that one character is already present — not rescan the entire substring.

> **Key Insight for Improvement:**
> Use a sliding window with a set. Expand right: if new char is unique, add to set. If duplicate, shrink from left (removing chars from set) until valid again. Each char is added/removed from set at most once → O(N).

<br>

---

## Solution 2: Sliding Window + Hash Set

**Intuition:**
Expand the window by moving right. If the new character is already in the set (duplicate), shrink from the left until it's removed.

**Algorithm:**
1. left = 0, maxLen = 0, set = {}
2. For right = 0 to n-1:
   - While s[right] in set: set.remove(s[left]), left++
   - set.add(s[right])
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(N)
**Why?**
- Each character added to set once, removed at most once
- Left pointer moves at most N times total
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 50,000 → at most 100,000 set operations

### Space Complexity: O(min(N, 128))

> **Drawback:**
> When a duplicate is found, we shrink from the left one character at a time until the duplicate is removed. If the duplicate's first occurrence is far from the left, we do many unnecessary removals.

> **Key Insight for Improvement:**
> Store each character's LAST SEEN INDEX in a hash map. When a duplicate is found, jump left directly to (lastSeen + 1). No incremental shrinking needed — O(1) per duplicate instead of O(K).

<br>

---

## Solution 3: Sliding Window + Last Index Map (Optimal)

**Intuition:**
Map each character to its most recent index. When s[right] was last seen at index j (and j ≥ left), jump left to j+1. This skips all intermediate characters in one step.

**Algorithm:**
1. left = 0, maxLen = 0, map = {}
2. For right = 0 to n-1:
   - If s[right] in map AND map[s[right]] ≥ left:
     - left = map[s[right]] + 1 (jump past the duplicate)
   - map[s[right]] = right (update last seen index)
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Each iteration: O(1) map lookup + O(1) update
- Left pointer may jump forward but never backwards

**Detailed breakdown:**
- N = 50,000 → exactly 50,000 iterations
- No inner while loop — truly single pass

**Example walkthrough:**
```
s = "abcabcbb"

right=0('a'): map={a:0}, left=0, len=1
right=1('b'): map={a:0,b:1}, left=0, len=2
right=2('c'): map={a:0,b:1,c:2}, left=0, len=3
right=3('a'): 'a' seen at 0 ≥ left=0 → left=1, map={a:3,b:1,c:2}, len=3
right=4('b'): 'b' seen at 1 ≥ left=1 → left=2, map={a:3,b:4,c:2}, len=3
right=5('c'): 'c' seen at 2 ≥ left=2 → left=3, map={a:3,b:4,c:5}, len=3
right=6('b'): 'b' seen at 4 ≥ left=3 → left=5, map={a:3,b:6,c:5}, len=2
right=7('b'): 'b' seen at 6 ≥ left=5 → left=7, map={a:3,b:7,c:5}, len=1

maxLen = 3 ✓
```

### Space Complexity: O(min(N, 128))
**Why?**
- Map stores at most one entry per unique character

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³) | O(N) | Check all substrings |
| Set + Shrink | O(N) | O(N) | Sliding window, shrink one at a time |
| Last Index Map | O(N) | O(N) | Jump left directly — no inner loop |

**Recommended Solution:** Last Index Map (Solution 3) — O(N) time, truly single pass.

**Key Insights:**
1. **Brute → Set Window:** Don't recheck entire substring — maintain set incrementally
2. **Set → Map:** Don't shrink incrementally — jump left using last-seen index
3. **Check left ≥ map[c]:** Ensures we only consider duplicates INSIDE the current window


<br>
<br>

---

```code```
