export default {
  title: 'Two Pointers Pattern',
  course: 'Data Structures & Algorithms',
  category: 'Arrays & Strings',
  duration: 35,
  isPremium: false,
  content: `
The **Two Pointers** technique is one of the most elegant and efficient patterns in algorithmic problem-solving. It's particularly powerful for array and string manipulation problems, often reducing time complexity from O(n²) to O(n).

## Core Concept

The two pointers pattern uses two reference points (indices) that traverse the data structure in a coordinated manner. The movement strategy depends on the problem:

### Pattern Variations

**1. Opposite Direction (Convergent)**
- Start from both ends (left=0, right=n-1)
- Move towards center
- Used for: Palindromes, pair finding in sorted arrays

**2. Same Direction (Parallel)**
- Both pointers move in same direction
- One pointer leads, other follows
- Used for: Removing duplicates, slow-fast pointer problems

**3. Sliding Window**
- Two pointers maintain a window
- Expand/contract based on conditions
- Used for: Subarray/substring problems

## When to Use Two Pointers

✅ **Perfect scenarios:**
- Problem involves sorted array
- Need to find pairs with specific relationship
- Checking palindromes or symmetry
- In-place array modifications
- Finding subarrays with constraints

❌ **Not suitable for:**
- Unsorted arrays (usually need sorting first)
- Problems requiring random access
- When order matters and can't be changed

## Classic Problems

### 1. Two Sum (Sorted Array)
**Problem:** Find two numbers that add up to target
**Approach:** Use opposite direction pointers
**Time:** O(n) | **Space:** O(1)

### 2. Valid Palindrome
**Problem:** Check if string reads same forwards and backwards
**Approach:** Compare characters from both ends
**Time:** O(n) | **Space:** O(1)

### 3. Container With Most Water
**Problem:** Find two lines that contain most water
**Approach:** Start from widest, move inward
**Time:** O(n) | **Space:** O(1)

### 4. Three Sum
**Problem:** Find all unique triplets that sum to zero
**Approach:** Fix one number, use two pointers for others
**Time:** O(n²) | **Space:** O(1) excluding output

## Complexity Analysis

**Time Complexity:**
- Single pass: O(n)
- With sorting: O(n log n)
- Nested (Three Sum): O(n²)

**Space Complexity:**
- Usually O(1) - constant extra space
- In-place modifications
- No additional data structures needed

## Common Pitfalls

⚠️ **Watch out for:**
1. **Off-by-one errors** - Check boundary conditions carefully
2. **Infinite loops** - Ensure pointers always progress
3. **Duplicate handling** - Skip duplicates when needed
4. **Empty/null inputs** - Handle edge cases
5. **Integer overflow** - Be careful with sum calculations

## Advanced Techniques

### Skip Duplicates Pattern
\`\`\`
while (left < right && arr[left] == arr[left + 1]) left++;
while (left < right && arr[right] == arr[right - 1]) right--;
\`\`\`

### Expand Around Center (Palindromes)
\`\`\`
while (left >= 0 && right < n && s[left] == s[right]) {
    left--;
    right++;
}
\`\`\`

## Interview Tips

💡 **Best practices:**
1. **Draw it out** - Visualize pointer movements
2. **Test edge cases** - Empty, single element, all same
3. **Consider sorting** - Sometimes O(n log n) sorting enables O(n) solution
4. **Communicate** - Explain your pointer movement logic
5. **Optimize incrementally** - Start with brute force, then optimize

> **🎯 Interview Strategy:** When you see a sorted array or need to find pairs/triplets, two pointers should be your first consideration!

## Practice Progression

**Beginner:**
- Valid Palindrome
- Remove Duplicates from Sorted Array
- Merge Sorted Arrays

**Intermediate:**
- Two Sum II (Sorted)
- 3Sum
- Container With Most Water

**Advanced:**
- Trapping Rain Water
- 4Sum
- Longest Substring Without Repeating Characters
  `,
  codeExamples: [
    {
      title: 'Two Sum (Sorted Array)',
      language: 'python',
      code: `def two_sum_sorted(numbers, target):
    """
    Find two numbers that add up to target in sorted array
    Time: O(n), Space: O(1)
    
    Args:
        numbers: List[int] - sorted array
        target: int - target sum
    Returns:
        List[int] - indices of two numbers (1-indexed)
    """
    left, right = 0, len(numbers) - 1
    
    while left < right:
        current_sum = numbers[left] + numbers[right]
        
        if current_sum == target:
            # Return 1-indexed positions
            return [left + 1, right + 1]
        elif current_sum < target:
            # Need larger sum, move left pointer right
            left += 1
        else:
            # Need smaller sum, move right pointer left
            right -= 1
    
    # No solution found
    return [-1, -1]

# Example usage
print(two_sum_sorted([2, 7, 11, 15], 9))  # Output: [1, 2]
print(two_sum_sorted([2, 3, 4], 6))       # Output: [1, 3]`
    },
    {
      title: 'Valid Palindrome',
      language: 'java',
      code: `public class Solution {
    /**
     * Check if string is valid palindrome (alphanumeric only, case-insensitive)
     * Time: O(n), Space: O(1)
     */
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
            
            // Skip non-alphanumeric from right
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (Character.toLowerCase(s.charAt(left)) != 
                Character.toLowerCase(s.charAt(right))) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
}

// Example usage:
// isPalindrome("A man, a plan, a canal: Panama") -> true
// isPalindrome("race a car") -> false`
    },
    {
      title: 'Three Sum Problem',
      language: 'javascript',
      code: `/**
 * Find all unique triplets that sum to zero
 * Time: O(n²), Space: O(1) excluding output
 * 
 * @param {number[]} nums - array of integers
 * @return {number[][]} - array of triplets
 */
function threeSum(nums) {
    const result = [];
    
    // Sort array for two-pointer approach
    nums.sort((a, b) => a - b);
    
    for (let i = 0; i < nums.length - 2; i++) {
        // Skip duplicates for first number
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        
        // Two pointers for remaining numbers
        let left = i + 1;
        let right = nums.length - 1;
        const target = -nums[i];
        
        while (left < right) {
            const sum = nums[left] + nums[right];
            
            if (sum === target) {
                result.push([nums[i], nums[left], nums[right]]);
                
                // Skip duplicates for second number
                while (left < right && nums[left] === nums[left + 1]) {
                    left++;
                }
                // Skip duplicates for third number
                while (left < right && nums[right] === nums[right - 1]) {
                    right--;
                }
                
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}

// Example usage:
console.log(threeSum([-1, 0, 1, 2, -1, -4]));
// Output: [[-1, -1, 2], [-1, 0, 1]]`
    }
  ]
};
