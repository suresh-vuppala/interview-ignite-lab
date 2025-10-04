export const dsaArraysTwoPointers = {
  title: 'Two Pointers Pattern',
  course: 'Data Structures & Algorithms',
  category: 'Arrays & Strings',
  duration: 35,
  isPremium: false,
  content: `
# Two Pointers Pattern

The **two pointers technique** is one of the most powerful and elegant patterns in algorithm design. It's used in approximately **30% of array and string problems** in technical interviews.

## Core Concept

The two pointers pattern involves using **two variables** (pointers) to traverse a data structure, typically moving towards each other or in the same direction at different speeds.

### Pattern Variations

**1. Opposite Direction (Convergent)**
- Pointers start at opposite ends
- Move toward each other
- Common in palindrome checks, two sum problems

**2. Same Direction (Fast & Slow)**
- Both pointers start at the beginning
- Move at different speeds
- Used in cycle detection, removing duplicates

**3. Sliding Window**
- Maintain a window of elements
- Expand or contract based on conditions
- Perfect for substring/subarray problems

## When to Use Two Pointers

**Indicators that suggest two pointers:**
- Problem involves **pairs** of elements
- Working with **sorted arrays**
- Need to find **palindromes**
- **Removing duplicates** from sorted data
- **Merging** two sorted structures
- **Reversing** arrays or strings

## Classic Problems & Solutions

### Problem 1: Two Sum (Sorted Array)
**Given a sorted array and target, find two numbers that add up to target.**

**Approach:** Use two pointers from opposite ends, adjust based on sum comparison.

### Problem 2: Valid Palindrome
**Check if string is palindrome, ignoring case and non-alphanumeric characters.**

**Approach:** Two pointers from ends, skip invalid characters, compare.

### Problem 3: Remove Duplicates
**Remove duplicates from sorted array in-place.**

**Approach:** Slow pointer for placement, fast pointer for exploration.

## Time & Space Complexity

**Advantages:**
- **Time Complexity:** Usually O(n) - single pass through data
- **Space Complexity:** O(1) - only using two pointer variables
- **Efficiency:** No need for extra data structures like hash maps

**Comparison with other approaches:**
- **Brute Force:** O(n²) time with nested loops
- **Hash Map:** O(n) time but O(n) space
- **Two Pointers:** O(n) time and O(1) space ✅

## Common Pitfalls & Tips

**Common Mistakes:**
- **Off-by-one errors** - Be careful with boundary conditions
- **Infinite loops** - Ensure pointers always make progress
- **Skipping elements** - Handle duplicates correctly
- **Edge cases** - Empty arrays, single elements

**Best Practices:**
- **Draw it out** - Visualize pointer movement
- **Test edge cases** - Empty, single element, all same elements
- **Verify boundaries** - Check array bounds before access
- **Consider sorted vs unsorted** - Two pointers work best with sorted data

## Advanced Techniques

### Dutch National Flag
Partition array into three parts using three pointers.

### Fast & Slow Pointers (Floyd's Cycle Detection)
Detect cycles in linked lists or arrays.

### Sliding Window Maximum
Maintain window of elements with maximum/minimum properties.

> **💡 Interview Tip:** When you see a problem involving pairs, palindromes, or sorted arrays, immediately consider the two pointers pattern. It often leads to the most optimal solution!

## Practice Problems

1. **Easy:** Valid Palindrome, Remove Duplicates from Sorted Array
2. **Medium:** 3Sum, Container With Most Water, Longest Palindromic Substring
3. **Hard:** Trapping Rain Water, Minimum Window Substring

Each problem builds upon the core two pointers concept with increasing complexity.
  `,
  codeExamples: [
    {
      title: 'Two Sum (Sorted Array)',
      language: 'python',
      code: `def two_sum_sorted(nums, target):
    """
    Find two numbers in sorted array that add up to target.
    Time: O(n), Space: O(1)
    
    Args:
        nums: List of integers (sorted)
        target: Target sum
    
    Returns:
        List of two indices or empty list if not found
    """
    left, right = 0, len(nums) - 1
    
    while left < right:
        current_sum = nums[left] + nums[right]
        
        if current_sum == target:
            return [left, right]
        elif current_sum < target:
            # Need larger sum, move left pointer right
            left += 1
        else:
            # Need smaller sum, move right pointer left
            right -= 1
    
    return []  # No solution found

# Example usage
nums = [2, 7, 11, 15]
target = 9
result = two_sum_sorted(nums, target)
print(f"Indices: {result}")  # Output: [0, 1]`
    },
    {
      title: 'Valid Palindrome',
      language: 'java',
      code: `public class PalindromeChecker {
    
    /**
     * Check if string is valid palindrome
     * Ignores case and non-alphanumeric characters
     * Time: O(n), Space: O(1)
     */
    public static boolean isPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return true;
        }
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric from left
            while (left < right && !isAlphanumeric(s.charAt(left))) {
                left++;
            }
            
            // Skip non-alphanumeric from right
            while (left < right && !isAlphanumeric(s.charAt(right))) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            char leftChar = Character.toLowerCase(s.charAt(left));
            char rightChar = Character.toLowerCase(s.charAt(right));
            
            if (leftChar != rightChar) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    private static boolean isAlphanumeric(char c) {
        return Character.isLetterOrDigit(c);
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println(isPalindrome("A man, a plan, a canal: Panama")); // true
        System.out.println(isPalindrome("race a car")); // false
        System.out.println(isPalindrome("")); // true
    }
}`
    },
    {
      title: 'Three Sum Problem',
      language: 'javascript',
      code: `/**
 * Find all unique triplets that sum to zero
 * Time: O(n²), Space: O(1) excluding output
 */
function threeSum(nums) {
    if (nums.length < 3) return [];
    
    // Sort the array first
    nums.sort((a, b) => a - b);
    const result = [];
    
    for (let i = 0; i < nums.length - 2; i++) {
        // Skip duplicate values for first element
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        
        let left = i + 1;
        let right = nums.length - 1;
        const target = -nums[i]; // We want nums[i] + nums[left] + nums[right] = 0
        
        while (left < right) {
            const sum = nums[left] + nums[right];
            
            if (sum === target) {
                result.push([nums[i], nums[left], nums[right]]);
                
                // Skip duplicates for left pointer
                while (left < right && nums[left] === nums[left + 1]) {
                    left++;
                }
                // Skip duplicates for right pointer
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

// Example usage
const nums = [-1, 0, 1, 2, -1, -4];
console.log(threeSum(nums)); // [[-1, -1, 2], [-1, 0, 1]]`
    }
  ]
};
