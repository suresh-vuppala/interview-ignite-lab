
Given a string s, find the length of the longest substring without repeating characters.

<br>

> Input:
> s = "abcabcbb"

> Output:
> 3

> Explanation:
> The longest substring without repeating characters is "abc", with length 3.
> Other substrings like "bca" and "cab" also have length 3.
> 
> **Key insight:** We need to track characters in current window and shrink when duplicates appear.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Generate all possible substrings and check each one to see if it contains all unique characters. Track the maximum length found.

**Algorithm:**
1. For each starting index i (0 to n-1)
2. For each ending index j (i to n-1)
3. Check if substring s[i...j] has all unique characters
4. If yes, update max_len with (j - i + 1)
5. Return max_len

### Time Complexity: O(N³)
**Why cubic?**
- Outer loop: N iterations (starting positions)
- Inner loop: N iterations (ending positions)
- Uniqueness check: O(N) for each substring
- Total: N × N × N = O(N³)

**Detailed breakdown:**
- Total substrings: N×(N+1)/2 ≈ N²/2
- Each substring checked for uniqueness: O(N)
- Total: N²/2 × N = O(N³)
- Example: String of length 100 → 100³ = 1,000,000 operations

### Space Complexity: O(min(N, M))
**Why?**
- Set to store characters: at most min(N, M) characters
- N = string length, M = charset size (e.g., 128 for ASCII)
- For each substring check, create new set
- Maximum set size = min(N, M)

**Problem:** Extremely slow for large strings due to redundant checks.

> **Key Insight for Improvement:**
> We're checking uniqueness from scratch for each substring. Can we reuse information? Yes! When extending from s[i...j] to s[i...j+1], we only need to check if s[j+1] is already in s[i...j].

<br>

---

## Solution 2: Brute Force Optimized

**Intuition:**
For each starting position, extend the substring one character at a time. Stop extending when we encounter a duplicate. This avoids rechecking the entire substring.

**Algorithm:**
1. For each starting index i
2. Create empty set for current window
3. For each ending index j starting from i:
   - If s[j] already in set, break (found duplicate)
   - Add s[j] to set
   - Update max_len with current window size
4. Return max_len

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations (starting positions)
- Inner loop: at most N iterations (extending window)
- Set operations (add/contains): O(1) average
- Total: N × N × O(1) = O(N²)

**Detailed breakdown:**
- For each starting position: extend until duplicate
- Worst case: no duplicates, extend full length each time
- Total operations: N + (N-1) + (N-2) + ... + 1 = N×(N+1)/2 ≈ O(N²)
- Example: String of length 100 → 5,050 operations

**Improvement:** From O(N³) to O(N²)
- Example: String of length 1000
- Brute force: 1,000,000,000 operations
- Optimized: 500,500 operations (2000× faster!)

### Space Complexity: O(min(N, M))
**Why?**
- Set stores characters in current window
- Maximum size = min(N, M)
- Reuse same set for each starting position

> **Key Insight for Improvement:**
> We're still restarting from each position. When we find a duplicate at position j, we move start to i+1 and rebuild the set. Can we avoid rebuilding? Yes! Use sliding window - when duplicate found, just remove characters from left until duplicate is gone.

<br>

---

## Solution 3: Sliding Window (Two Pointers)

**Intuition:**
Maintain a window [left, right] with all unique characters. When we encounter a duplicate at right, shrink window from left until the duplicate is removed. This avoids restarting from scratch.

**Algorithm:**
1. Initialize left = 0, empty set, max_len = 0
2. For right from 0 to n-1:
   - While s[right] is in set:
     - Remove s[left] from set
     - Increment left
   - Add s[right] to set
   - Update max_len = max(max_len, right - left + 1)
3. Return max_len

### Time Complexity: O(2N) = O(N)
**Why O(2N)?**
- Right pointer: moves from 0 to n-1 → N moves
- Left pointer: moves from 0 to n-1 → at most N moves
- Each character visited at most twice (once by right, once by left)
- Total: 2N = O(N)

**Detailed breakdown:**
- Right pointer always moves forward: N iterations
- Left pointer only moves forward (never backward): at most N moves total
- Each character added once and removed at most once
- Total operations: 2N
- Example: String of length 1000 → 2000 operations

**Improvement:** From O(N²) to O(N)
- Example: String of length 1000
- Previous: 500,500 operations
- Current: 2000 operations (250× faster!)

### Space Complexity: O(min(N, M))
**Why?**
- Set stores characters in current window
- Window size ≤ min(N, M)
- Maximum unique characters = min(string length, charset size)

**Why this works:**
- Window always contains unique characters
- When duplicate found, we shrink from left until it's removed
- This maintains the invariant: window has all unique characters

> **Key Insight for Improvement:**
> When we find s[right] is duplicate, we remove characters one by one from left. Can we jump directly to the position after the previous occurrence of s[right]? Yes! Store last seen index of each character.

<br>

---

## Solution 4: Sliding Window with HashMap

**Intuition:**
Instead of removing characters one by one from left, store the last seen index of each character. When duplicate found, jump left pointer directly to (last_seen_index + 1).

**Algorithm:**
1. Initialize left = 0, empty map, max_len = 0
2. For right from 0 to n-1:
   - If s[right] in map and map[s[right]] >= left:
     - Update left = map[s[right]] + 1
   - Store map[s[right]] = right
   - Update max_len = max(max_len, right - left + 1)
3. Return max_len

### Time Complexity: O(N)
**Why?**
- Single pass through string: N iterations
- Each character processed exactly once
- Map operations (get/put): O(1) average
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Right pointer: N moves
- Left pointer: jumps directly (no while loop)
- Each character visited exactly once
- Total operations: N
- Example: String of length 1000 → 1000 operations

**Improvement:** From O(2N) to O(N)
- Example: String of length 1000
- Previous: 2000 operations
- Current: 1000 operations (2× faster!)

**Why faster:**
- No while loop to shrink window
- Direct jump to correct position
- Each character processed exactly once

### Space Complexity: O(min(N, M))
**Why?**
- HashMap stores character → index mapping
- At most min(N, M) entries
- N = string length, M = charset size

**Key difference from Solution 3:**
- Solution 3: Remove characters one by one (while loop)
- Solution 4: Jump directly to correct position (no loop)
- Both O(N) but Solution 4 has better constant factor

> **Key Insight for Improvement:**
> HashMap has overhead (hashing, collision handling). For ASCII/extended ASCII, can we use a fixed-size array instead? Yes! Use array of size 128 or 256 for direct indexing.

<br>

---

## Solution 5: Optimized with Array (ASCII)

**Intuition:**
For ASCII characters, use a fixed-size array (128 or 256) instead of HashMap. Array index = character's ASCII value. This eliminates hashing overhead and provides O(1) access with better constants.

**Algorithm:**
1. Create array charIndex[128] initialized to -1
2. Initialize left = 0, max_len = 0
3. For right from 0 to n-1:
   - If charIndex[s[right]] >= left:
     - Update left = charIndex[s[right]] + 1
   - Store charIndex[s[right]] = right
   - Update max_len = max(max_len, right - left + 1)
4. Return max_len

### Time Complexity: O(N)
**Why?**
- Single pass through string: N iterations
- Array access: O(1) (no hashing)
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Same as Solution 4: N operations
- But faster in practice due to array access vs hashing
- No hash function computation
- No collision handling

### Space Complexity: O(1)
**Why?**
- Fixed array size: 128 (ASCII) or 256 (extended ASCII)
- Space doesn't depend on input size
- O(128) = O(1) constant space

**Improvement:** From O(min(N, M)) to O(1)
- HashMap: space grows with unique characters
- Array: fixed size regardless of input
- Trade-off: Array wastes space if charset is large

**Why this is optimal:**
- Time: O(N) - must visit each character at least once
- Space: O(1) - fixed array size
- Cannot do better than O(N) time (must read entire string)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³) | O(min(N,M)) | Baseline - check all substrings |
| Brute Optimized | O(N²) | O(min(N,M)) | Extend incrementally - avoid recheck |
| Sliding Window (Set) | O(2N) | O(min(N,M)) | Two pointers - avoid restart |
| Sliding Window (Map) | O(N) | O(min(N,M)) | Jump left - no while loop |
| Array (ASCII) | O(N) | O(1) | Fixed array - no hashing |

**Key Insights:**
1. **Brute → Optimized:** Extend incrementally → avoid full recheck
2. **Optimized → Sliding Window:** Maintain window → avoid restart
3. **Set → HashMap:** Store indices → jump instead of shrink
4. **HashMap → Array:** Fixed size → eliminate hashing overhead

**When to use each:**
- **Brute Force:** Never (too slow)
- **Sliding Window (Set):** When need to understand the pattern
- **Sliding Window (Map):** General solution for any charset
- **Array:** When charset is small and known (ASCII)

> **Final Complexity:** O(N) time, O(1) space (for ASCII)

<br>
<br>

---

```code```
