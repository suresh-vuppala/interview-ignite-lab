## Problem Statement

You are given a string `s` consisting only of the characters `'a'`, `'b'`, and `'c'`.

A substring of `s` is called **balanced** if all distinct characters in the substring appear the **same number of times**.

Return the **length of the longest balanced substring** of `s`.

### Example

```
Input: s = "abbac"
Output: 4
Explanation: The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

Input: s = "abc"
Output: 0
Explanation: The only balanced substring is the empty string.

Input: s = "aabbcccc"
Output: 6
Explanation: "aabbcc" is a balanced substring with length 6.
```

## Approach

### Naive Approach
- Check all possible substrings
- Verify if each is balanced (all distinct chars have same count)
- Time Complexity: O(n³)
- Space Complexity: O(1) or O(n) for character counts

### Optimized Approach (Prefix Sum + State Hashing)

1. **Track Character Frequencies**:
   - Maintain count of each character 'a', 'b', 'c' as we iterate

2. **State Representation**:
   - Instead of storing actual counts, track the **difference** between character counts
   - For example: (count_a - count_b, count_b - count_c)
   - Or use: (count_a - count_b, count_a - count_c)

3. **Key Insight**:
   - A substring is balanced if all counts are equal
   - This means all differences should be 0
   - But we need differences relative to each other, not absolute counts

4. **Frequency Difference Pattern**:
   - If we see the same (diff_ab, diff_ac) state at two different indices, the substring between them is balanced
   - All characters have equal counts in between if their relative differences become 0

5. **Algorithm**:
   - Use a map to store first occurrence of each state (difference tuple)
   - Initialize map with {(0, 0): -1}
   - For each character at index i:
     - Update counts for the character
     - Calculate current state = (count_a - count_b, count_a - count_c)
     - If state was seen before, substring between first and current occurrence is balanced
     - Update max_length
     - Store current state if not seen

## Complexity Analysis

### Time Complexity: O(n)

**Detailed Explanation:**
- Single pass through string: O(n)
- HashMap operations (insert/lookup): O(1)
- Character count update: O(1)
- Overall: O(n) average case

### Space Complexity: O(1)

**Detailed Explanation:**
- HashMap stores at most O(n²) possible states, but in practice much less
- Character counts for 3 characters: constant space
- State values (differences): bounded by n, but practically O(1) relevant states
- O(n) worst case, O(1) practical

## Key Insights

- **Relative Difference Pattern**: Track differences between character counts, not absolute counts
- **State Hashing**: Represent complex conditions (all equal counts) as simple state pairs
- **Balanced Condition**: When same state repeats, all characters between are equal
- **Character Independence**: Works with any number of distinct characters
- **Efficient State Space**: Using differences captures the essential information needed

## Code Implementation

Below are the complete implementations of the longestBalancedSubstring function in different programming languages:

**Key Implementation Details:**
- Track count of each character ('a', 'b', 'c') as we iterate
- Use state tuple: (count_a - count_b, count_a - count_c) to represent balance
- Store first occurrence of each state
- When state repeats, all characters between have equal counts
- Return the maximum substring length found

Select a language above to view the implementation.

```code```

## Key Insights

- **Relative Difference Pattern**: Track differences between character counts, not absolute counts
- **State Hashing**: Represent complex conditions (all equal counts) as simple state pairs
- **Balanced Condition**: When same state repeats, all characters between are equal
- **Character Independence**: Works with any number of distinct characters
- **Efficient State Space**: Using differences captures the essential information needed
