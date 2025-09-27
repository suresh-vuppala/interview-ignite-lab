// Comprehensive lesson data for all courses
export const lessonData: Record<string, any> = {
  // DSA Course - Arrays & Strings
  'dsa-arrays-intro': {
    title: 'Introduction to Arrays & Strings',
    course: 'Data Structures & Algorithms',
    category: 'Arrays & Strings',
    duration: 25,
    isPremium: false,
    content: `
# Introduction to Arrays & Strings

Arrays and strings are the **fundamental building blocks** of programming. Mastering these data structures is crucial for succeeding in technical interviews at top tech companies like **Google**, **Facebook**, **Amazon**, and **Microsoft**.

## Why Arrays & Strings Matter

Arrays and strings appear in approximately **60% of all coding interview questions**. They serve as the foundation for more complex data structures and algorithms.

### Key Characteristics

**Arrays:**
- **Contiguous memory allocation** - Elements are stored in adjacent memory locations
- **O(1) random access** - Direct access to any element using index
- **Fixed size** in most languages (dynamic in Python, JavaScript)
- **Cache-friendly** due to memory locality

**Strings:**
- **Immutable** in most languages (Java, Python, C#)
- **Character arrays** under the hood
- **Unicode support** - Modern strings support international characters
- **Special operations** - Concatenation, substring, pattern matching

## Common Patterns

### 1. Two Pointers Technique
Perfect for problems involving pairs, palindromes, or sorted arrays.

**When to use:**
- Finding pairs with specific sum
- Checking palindromes
- Merging sorted arrays
- Removing duplicates

### 2. Sliding Window
Ideal for subarray/substring problems with constraints.

**When to use:**
- Maximum/minimum subarray problems
- Substring with specific properties
- Moving average calculations
- Fixed-size window problems

### 3. Prefix Sum
Efficient for range sum queries and cumulative operations.

**When to use:**
- Range sum queries
- Subarray sum problems
- Cumulative frequency
- 2D matrix operations

## Real-World Applications

- **Text Processing** - Search engines, word processors
- **Image Processing** - Pixel manipulation, filters
- **Database Indexing** - B-trees, hash tables
- **Network Protocols** - Packet parsing, data transmission
- **Game Development** - Collision detection, pathfinding

## Practice Strategy

1. **Start with basic operations** - Insert, delete, search
2. **Master the patterns** - Two pointers, sliding window, prefix sum
3. **Solve classic problems** - Two Sum, Valid Palindrome, Longest Substring
4. **Analyze time/space complexity** - Always consider Big O notation
5. **Handle edge cases** - Empty arrays, null inputs, single elements

> **💡 Pro Tip:** Always draw out examples on paper or whiteboard. Visualization helps identify patterns and edge cases!

## Next Steps

In the following lessons, we'll dive deep into each pattern with **real interview questions** from top tech companies. You'll learn not just how to solve problems, but how to **think like an interviewer** and approach new problems systematically.
    `,
    codeExamples: [
      {
        title: 'Array Basics - Dynamic Array Implementation',
        language: 'python',
        code: `class DynamicArray:
    """
    A simple dynamic array implementation
    Demonstrates core array operations
    """
    def __init__(self):
        self.capacity = 2
        self.size = 0
        self.data = [None] * self.capacity
    
    def get(self, index):
        """Get element at index - O(1)"""
        if 0 <= index < self.size:
            return self.data[index]
        raise IndexError("Index out of bounds")
    
    def set(self, index, value):
        """Set element at index - O(1)"""
        if 0 <= index < self.size:
            self.data[index] = value
        else:
            raise IndexError("Index out of bounds")
    
    def append(self, value):
        """Add element to end - O(1) amortized"""
        if self.size >= self.capacity:
            self._resize()
        self.data[self.size] = value
        self.size += 1
    
    def _resize(self):
        """Double the capacity when needed"""
        self.capacity *= 2
        new_data = [None] * self.capacity
        for i in range(self.size):
            new_data[i] = self.data[i]
        self.data = new_data`
      },
      {
        title: 'String Manipulation - Basic Operations',
        language: 'java',
        code: `public class StringOperations {
    
    /**
     * Check if string is palindrome (case-insensitive)
     * Time: O(n), Space: O(1)
     */
    public static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
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
    
    /**
     * Reverse words in a string
     * Input: "the sky is blue"
     * Output: "blue is sky the"
     */
    public static String reverseWords(String s) {
        String[] words = s.trim().split("\\\\s+");
        StringBuilder result = new StringBuilder();
        
        for (int i = words.length - 1; i >= 0; i--) {
            result.append(words[i]);
            if (i > 0) result.append(" ");
        }
        
        return result.toString();
    }
}`
      }
    ]
  },

  'dsa-arrays-two-pointers': {
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
  },

  'dsa-arrays-sliding-window': {
    title: 'Sliding Window Technique',
    course: 'Data Structures & Algorithms',
    category: 'Arrays & Strings',
    duration: 40,
    isPremium: true,
    content: `
# Sliding Window Technique

The **sliding window pattern** is a computational technique that converts nested loops into a single loop, dramatically improving time complexity from O(n²) to O(n) for many subarray/substring problems.

## Core Concept

A sliding window is a **sub-list that runs over an underlying collection**. The window "slides" over the data structure, maintaining a subset of elements that satisfy certain conditions.

### Window Types

**1. Fixed Size Window**
- Window size remains constant
- Slide by removing leftmost and adding rightmost element
- Example: Moving average, maximum in each window of size k

**2. Dynamic Size Window**
- Window size changes based on conditions
- Expand when condition not met, contract when exceeded
- Example: Longest substring without repeating characters

## Problem Identification

**Use sliding window when you see:**
- **Subarray/substring** problems
- **Consecutive elements** requirements
- **Optimization** problems (max/min length, sum, etc.)
- **Fixed or dynamic window size** constraints

**Keywords that hint at sliding window:**
- "longest/shortest substring"
- "maximum/minimum subarray"
- "window of size k"
- "consecutive elements"
- "without repeating"

## Template Patterns

### Fixed Size Window Template
\`\`\`python
def fixed_window(arr, k):
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    for i in range(k, len(arr)):
        window_sum = window_sum - arr[i-k] + arr[i]
        max_sum = max(max_sum, window_sum)
    
    return max_sum
\`\`\`

### Dynamic Size Window Template
\`\`\`python
def dynamic_window(s):
    left = 0
    window_set = set()
    max_length = 0
    
    for right in range(len(s)):
        while s[right] in window_set:
            window_set.remove(s[left])
            left += 1
        
        window_set.add(s[right])
        max_length = max(max_length, right - left + 1)
    
    return max_length
\`\`\`

## Classic Problems

### 1. Maximum Sum Subarray of Size K
**Problem:** Find maximum sum of any contiguous subarray of size k.
**Approach:** Fixed sliding window, maintain sum by adding new element and removing old.

### 2. Longest Substring Without Repeating Characters
**Problem:** Find length of longest substring without repeating characters.
**Approach:** Dynamic window with HashSet, expand right, contract left when duplicate found.

### 3. Minimum Window Substring
**Problem:** Find minimum window in string that contains all characters of pattern.
**Approach:** Dynamic window with character frequency counting.

## Time & Space Analysis

**Time Complexity:**
- **Before sliding window:** O(n²) or O(n³) with nested loops
- **After sliding window:** O(n) - each element visited at most twice
- **Dramatic improvement** for large datasets

**Space Complexity:**
- Usually O(1) for fixed window
- O(k) for dynamic window with auxiliary data structures
- Much better than O(n²) solutions

## Advanced Techniques

### Monotonic Deque
For sliding window maximum/minimum problems, maintain a deque of indices in monotonic order.

### Two Pointers with Conditions
Combine sliding window with two pointers for complex constraint problems.

### Frequency Counting
Use HashMap/array to track character/element frequencies within the window.

## Common Pitfalls

**Mistakes to avoid:**
- **Incorrect window initialization** - Off-by-one errors
- **Not handling edge cases** - Empty arrays, single elements
- **Inefficient window updates** - Recalculating entire window
- **Boundary violations** - Array index out of bounds

**Best Practices:**
- **Visualize the window** - Draw out the sliding process
- **Handle edge cases first** - Empty input, single element
- **Optimize updates** - Add/remove single elements, don't recalculate
- **Use appropriate data structures** - Sets for uniqueness, maps for counting

> **💡 Performance Tip:** Sliding window can reduce time complexity from O(n²) to O(n), making it one of the most impactful optimization techniques in competitive programming!

## Real-World Applications

- **Network packet analysis** - Monitor traffic in time windows
- **Stock price analysis** - Moving averages, trend detection
- **Data stream processing** - Real-time analytics
- **Text processing** - Pattern matching, compression
- **Image processing** - Convolution operations, filters

## Interview Strategy

1. **Identify the pattern** - Look for subarray/substring keywords
2. **Determine window type** - Fixed vs dynamic size
3. **Choose data structures** - Arrays, sets, maps based on requirements
4. **Implement incrementally** - Start with brute force, optimize to sliding window
5. **Test thoroughly** - Edge cases, boundary conditions
    `,
    codeExamples: [
      {
        title: 'Maximum Sum Subarray of Size K',
        language: 'python',
        code: `def max_sum_subarray(arr, k):
    """
    Find maximum sum of any contiguous subarray of size k.
    Time: O(n), Space: O(1)
    
    This is the classic sliding window problem that demonstrates
    how we can optimize from O(n*k) to O(n) time complexity.
    """
    if len(arr) < k:
        return None
    
    # Calculate sum of first window
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    # Slide the window: remove leftmost, add rightmost
    for i in range(k, len(arr)):
        window_sum = window_sum - arr[i - k] + arr[i]
        max_sum = max(max_sum, window_sum)
    
    return max_sum

# Example usage and test cases
def test_max_sum_subarray():
    # Test case 1: Normal case
    arr1 = [2, 1, 5, 1, 3, 2]
    k1 = 3
    result1 = max_sum_subarray(arr1, k1)
    print(f"Array: {arr1}, k={k1}, Max sum: {result1}")  # Expected: 9 (5+1+3)
    
    # Test case 2: All negative numbers
    arr2 = [-1, -2, -3, -4, -5]
    k2 = 2
    result2 = max_sum_subarray(arr2, k2)
    print(f"Array: {arr2}, k={k2}, Max sum: {result2}")  # Expected: -3 (-1+-2)
    
    # Test case 3: Single element
    arr3 = [10]
    k3 = 1
    result3 = max_sum_subarray(arr3, k3)
    print(f"Array: {arr3}, k={k3}, Max sum: {result3}")  # Expected: 10

test_max_sum_subarray()`
      },
      {
        title: 'Longest Substring Without Repeating Characters',
        language: 'java',
        code: `import java.util.*;

public class LongestSubstring {
    
    /**
     * Find length of longest substring without repeating characters
     * Time: O(n), Space: O(min(m,n)) where m is charset size
     * 
     * This demonstrates dynamic sliding window technique.
     */
    public static int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        Set<Character> window = new HashSet<>();
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            
            // Shrink window until no duplicate
            while (window.contains(rightChar)) {
                window.remove(s.charAt(left));
                left++;
            }
            
            // Add current character and update max length
            window.add(rightChar);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
    /**
     * Optimized version using HashMap to store character positions
     * Can skip multiple characters at once when duplicate found
     */
    public static int lengthOfLongestSubstringOptimized(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        Map<Character, Integer> charIndex = new HashMap<>();
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            
            // If character seen before and within current window
            if (charIndex.containsKey(rightChar) && charIndex.get(rightChar) >= left) {
                left = charIndex.get(rightChar) + 1;
            }
            
            charIndex.put(rightChar, right);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
    
    // Test cases
    public static void main(String[] args) {
        String[] testCases = {
            "abcabcbb",  // Expected: 3 ("abc")
            "bbbbb",     // Expected: 1 ("b")
            "pwwkew",    // Expected: 3 ("wke")
            "",          // Expected: 0
            "au"         // Expected: 2 ("au")
        };
        
        for (String test : testCases) {
            int result1 = lengthOfLongestSubstring(test);
            int result2 = lengthOfLongestSubstringOptimized(test);
            System.out.printf("String: '%s', Length: %d (optimized: %d)%n", 
                            test, result1, result2);
        }
    }
}`
      },
      {
        title: 'Sliding Window Maximum',
        language: 'cpp',
        code: `#include <vector>
#include <deque>
#include <iostream>

class SlidingWindowMaximum {
public:
    /**
     * Find maximum element in every sliding window of size k
     * Time: O(n), Space: O(k)
     * 
     * Uses monotonic deque to maintain maximum in O(1) time
     */
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // stores indices, maintains decreasing order of values
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove indices whose corresponding values are smaller than current
            // This maintains decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Add maximum of current window to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
    
    /**
     * Brute force approach for comparison
     * Time: O(n*k), Space: O(1)
     */
    std::vector<int> maxSlidingWindowBruteForce(std::vector<int>& nums, int k) {
        std::vector<int> result;
        
        for (int i = 0; i <= nums.size() - k; i++) {
            int maxVal = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                maxVal = std::max(maxVal, nums[j]);
            }
            result.push_back(maxVal);
        }
        
        return result;
    }
};

// Test function
void testSlidingWindowMaximum() {
    SlidingWindowMaximum solver;
    
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    auto result = solver.maxSlidingWindow(nums, k);
    
    std::cout << "Array: ";
    for (int num : nums) std::cout << num << " ";
    std::cout << "\\nWindow size: " << k << std::endl;
    std::cout << "Maximums: ";
    for (int max : result) std::cout << max << " ";
    std::cout << std::endl;
    // Expected output: 3 3 5 5 6 7
}

int main() {
    testSlidingWindowMaximum();
    return 0;
}`
      }
    ]
  },

  // System Design Course
  'system-design-fundamentals-intro': {
    title: 'System Design Fundamentals',
    course: 'System Design (HLD)',
    category: 'Fundamentals',
    duration: 45,
    isPremium: false,
    content: `
# System Design Fundamentals

System design interviews are **critical** for senior engineering positions at top tech companies. They test your ability to architect **large-scale distributed systems** that can handle millions of users while maintaining reliability, performance, and scalability.

## Why System Design Matters

**Modern applications serve billions of users:**
- **Facebook** - 3+ billion monthly active users
- **YouTube** - 2+ billion logged-in users monthly
- **Netflix** - 230+ million subscribers globally
- **Amazon** - 300+ million active customers

Designing systems at this scale requires understanding **fundamental principles** and **trade-offs**.

## Core Design Principles

### 1. Scalability
**The ability to handle increased load gracefully.**

**Horizontal Scaling (Scale Out):**
- Add more servers to handle load
- **Pros:** No single point of failure, cost-effective
- **Cons:** Complexity in data distribution
- **Example:** Web servers behind load balancer

**Vertical Scaling (Scale Up):**
- Increase power of existing servers (CPU, RAM)
- **Pros:** Simple, no architectural changes
- **Cons:** Hardware limits, single point of failure
- **Example:** Upgrading database server specs

### 2. Reliability
**System continues to work correctly even when failures occur.**

**Fault Tolerance Strategies:**
- **Redundancy** - Multiple instances of critical components
- **Replication** - Data copied across multiple locations
- **Circuit Breakers** - Prevent cascade failures
- **Graceful Degradation** - Reduced functionality vs complete failure

**Measuring Reliability:**
- **99.9% uptime** = 8.77 hours downtime per year
- **99.99% uptime** = 52.6 minutes downtime per year
- **99.999% uptime** = 5.26 minutes downtime per year

### 3. Availability
**System remains operational over time.**

**High Availability Techniques:**
- **Load Balancing** - Distribute traffic across healthy servers
- **Failover Mechanisms** - Automatic switching to backup systems
- **Health Checks** - Continuous monitoring of system components
- **Disaster Recovery** - Plans for catastrophic failures

### 4. Consistency
**All nodes see the same data simultaneously.**

**CAP Theorem:** Choose 2 of 3
- **Consistency** - All reads receive most recent write
- **Availability** - System continues to operate
- **Partition Tolerance** - System continues despite network failures

**Consistency Models:**
- **Strong Consistency** - All reads get latest write (RDBMS)
- **Eventual Consistency** - System will become consistent over time (NoSQL)
- **Weak Consistency** - No guarantees when all nodes will be consistent

## Essential System Components

### Load Balancers
**Distribute incoming requests across multiple servers.**

**Types:**
- **Layer 4 (Transport)** - Routes based on IP and port
- **Layer 7 (Application)** - Routes based on content (HTTP headers, URLs)

**Algorithms:**
- **Round Robin** - Requests distributed evenly
- **Least Connections** - Route to server with fewest active connections
- **IP Hash** - Route based on client IP hash
- **Weighted Round Robin** - Servers have different capacities

### Databases
**Store and retrieve data efficiently.**

**SQL Databases (RDBMS):**
- **ACID Properties** - Atomicity, Consistency, Isolation, Durability
- **Strong Consistency** - Immediate consistency across all nodes
- **Complex Queries** - JOINs, aggregations, transactions
- **Examples:** PostgreSQL, MySQL, Oracle

**NoSQL Databases:**
- **Document Stores** - JSON-like documents (MongoDB)
- **Key-Value Stores** - Simple key-value pairs (Redis, DynamoDB)
- **Column Family** - Column-oriented storage (Cassandra)
- **Graph Databases** - Relationship-focused (Neo4j)

### Caching
**Store frequently accessed data in fast storage.**

**Cache Levels:**
- **Browser Cache** - Client-side caching
- **CDN (Content Delivery Network)** - Geographic distribution
- **Application Cache** - In-memory storage (Redis, Memcached)
- **Database Cache** - Query result caching

**Cache Patterns:**
- **Cache-Aside** - Application manages cache
- **Write-Through** - Write to cache and database simultaneously
- **Write-Behind** - Write to cache first, database later
- **Refresh-Ahead** - Proactively refresh cache before expiration

### Message Queues
**Enable asynchronous communication between services.**

**Benefits:**
- **Decoupling** - Services don't need direct connections
- **Reliability** - Messages persisted until processed
- **Scalability** - Handle varying loads
- **Fault Tolerance** - Failed messages can be retried

**Types:**
- **Point-to-Point** - Single consumer per message (RabbitMQ)
- **Publish-Subscribe** - Multiple consumers per message (Apache Kafka)
- **Priority Queues** - Messages processed by priority
- **Dead Letter Queues** - Handle failed messages

## System Design Process

### 1. Requirements Clarification (5-10 minutes)
**Functional Requirements:**
- What features does the system support?
- What are the core use cases?
- Who are the users and how do they interact?

**Non-Functional Requirements:**
- How many users? (DAU, MAU)
- How much data? (Storage, read/write QPS)
- What's the expected response time?
- What's the required availability?

### 2. Capacity Estimation (5-10 minutes)
**Calculate system scale:**
- **Users:** Daily/Monthly Active Users
- **Storage:** Data size, growth rate
- **Bandwidth:** Read/Write QPS, peak traffic
- **Memory:** Cache requirements

### 3. System Interface Definition (5 minutes)
**Define APIs:**
- REST endpoints or GraphQL schema
- Input/output parameters
- Authentication/authorization

### 4. High-Level Design (10-15 minutes)
**Core components:**
- Load balancers
- Application servers
- Databases
- Caches
- Message queues

### 5. Detailed Design (10-15 minutes)
**Deep dive into:**
- Database schema
- Algorithm choices
- Data flow
- API design

### 6. Scale the Design (5-10 minutes)
**Address bottlenecks:**
- Database sharding
- Caching strategies
- Load balancing
- CDN usage

## Real-World Examples

### Design a URL Shortener (like bit.ly)
**Requirements:** Shorten long URLs, redirect to original, analytics
**Scale:** 100M URLs shortened daily, 100:1 read/write ratio
**Components:** Load balancer, app servers, database, cache, analytics service

### Design a Chat System (like WhatsApp)
**Requirements:** 1-on-1 chat, group chat, online presence, message delivery
**Scale:** 1B users, 50B messages daily
**Components:** WebSocket servers, message queue, user database, message storage

### Design a Video Streaming Service (like Netflix)
**Requirements:** Upload/store videos, stream to users, recommendations
**Scale:** 200M users, 1B hours watched daily
**Components:** CDN, video storage, recommendation engine, user database

> **💡 Interview Tip:** Always start with requirements clarification. Many candidates dive into design without understanding the scope, leading to over-engineering or missing critical requirements!

## Next Steps

In upcoming lessons, we'll dive deep into each component with **real system design problems** from companies like Google, Facebook, Amazon, and Netflix. You'll learn to think systematically about trade-offs and make architectural decisions that scale.
    `,
    codeExamples: [
      {
        title: 'Load Balancer Implementation',
        language: 'python',
        code: `import random
from typing import List, Optional

class Server:
    def __init__(self, ip: str, port: int, weight: int = 1):
        self.ip = ip
        self.port = port
        self.weight = weight
        self.current_connections = 0
        self.is_healthy = True
    
    def handle_request(self):
        """Simulate handling a request"""
        if self.is_healthy:
            self.current_connections += 1
            return f"Request handled by {self.ip}:{self.port}"
        return None
    
    def finish_request(self):
        """Simulate finishing a request"""
        self.current_connections = max(0, self.current_connections - 1)

class LoadBalancer:
    def __init__(self):
        self.servers: List[Server] = []
        self.current_index = 0
    
    def add_server(self, server: Server):
        """Add a server to the pool"""
        self.servers.append(server)
    
    def remove_server(self, server: Server):
        """Remove a server from the pool"""
        if server in self.servers:
            self.servers.remove(server)
    
    def round_robin(self) -> Optional[Server]:
        """Round Robin load balancing algorithm"""
        if not self.servers:
            return None
        
        healthy_servers = [s for s in self.servers if s.is_healthy]
        if not healthy_servers:
            return None
        
        server = healthy_servers[self.current_index % len(healthy_servers)]
        self.current_index += 1
        return server
    
    def least_connections(self) -> Optional[Server]:
        """Least Connections load balancing algorithm"""
        healthy_servers = [s for s in self.servers if s.is_healthy]
        if not healthy_servers:
            return None
        
        return min(healthy_servers, key=lambda s: s.current_connections)
    
    def weighted_round_robin(self) -> Optional[Server]:
        """Weighted Round Robin algorithm"""
        healthy_servers = [s for s in self.servers if s.is_healthy]
        if not healthy_servers:
            return None
        
        # Create weighted list
        weighted_servers = []
        for server in healthy_servers:
            weighted_servers.extend([server] * server.weight)
        
        if not weighted_servers:
            return None
        
        server = weighted_servers[self.current_index % len(weighted_servers)]
        self.current_index += 1
        return server
    
    def route_request(self, algorithm='round_robin'):
        """Route a request using specified algorithm"""
        if algorithm == 'round_robin':
            server = self.round_robin()
        elif algorithm == 'least_connections':
            server = self.least_connections()
        elif algorithm == 'weighted_round_robin':
            server = self.weighted_round_robin()
        else:
            return "Unknown algorithm"
        
        if server:
            return server.handle_request()
        return "No healthy servers available"

# Example usage
def demo_load_balancer():
    # Create load balancer and servers
    lb = LoadBalancer()
    
    servers = [
        Server("192.168.1.1", 8080, weight=3),
        Server("192.168.1.2", 8080, weight=2),
        Server("192.168.1.3", 8080, weight=1)
    ]
    
    for server in servers:
        lb.add_server(server)
    
    # Simulate requests
    print("Round Robin Algorithm:")
    for i in range(6):
        result = lb.route_request('round_robin')
        print(f"Request {i+1}: {result}")
    
    print("\\nLeast Connections Algorithm:")
    for i in range(6):
        result = lb.route_request('least_connections')
        print(f"Request {i+1}: {result}")

demo_load_balancer()`
      }
    ]
  },

  // LLD Course
  'lld-design-patterns-intro': {
    title: 'Introduction to Design Patterns',
    course: 'Low Level Design (LLD)',
    category: 'Design Patterns',
    duration: 35,
    isPremium: false,
    content: `
# Introduction to Design Patterns

Design patterns are **reusable solutions** to commonly occurring problems in software design. They represent **best practices** evolved over time by experienced developers and provide a **common vocabulary** for discussing design decisions.

## What Are Design Patterns?

Design patterns are **templates** that describe how to solve recurring design problems in object-oriented programming. They were popularized by the "Gang of Four" (GoF) book: **"Design Patterns: Elements of Reusable Object-Oriented Software"**.

### Key Benefits

**1. Reusability**
- Proven solutions that work across different contexts
- Reduce development time and effort
- Minimize bugs through tested approaches

**2. Communication**
- Common vocabulary for developers
- Easier to discuss and document designs
- Improved team collaboration

**3. Best Practices**
- Encapsulate expert knowledge
- Promote loose coupling and high cohesion
- Make code more maintainable and flexible

## Pattern Categories

### 1. Creational Patterns
**Control object creation mechanisms.**

**Common Patterns:**
- **Singleton** - Ensure only one instance exists
- **Factory Method** - Create objects without specifying exact classes
- **Builder** - Construct complex objects step by step
- **Abstract Factory** - Create families of related objects

**When to use:** Object creation is complex, needs to be controlled, or varies based on conditions.

### 2. Structural Patterns
**Deal with object composition and relationships.**

**Common Patterns:**
- **Adapter** - Make incompatible interfaces work together
- **Decorator** - Add behavior to objects dynamically
- **Facade** - Provide simplified interface to complex subsystem
- **Composite** - Treat individual and composite objects uniformly

**When to use:** Need to organize classes and objects to form larger structures.

### 3. Behavioral Patterns
**Focus on communication between objects and assignment of responsibilities.**

**Common Patterns:**
- **Observer** - Define one-to-many dependency between objects
- **Strategy** - Define family of algorithms and make them interchangeable
- **Command** - Encapsulate requests as objects
- **State** - Allow object to alter behavior when internal state changes

**When to use:** Need to manage algorithms, relationships, and responsibilities between objects.

## Design Principles

### SOLID Principles

**S - Single Responsibility Principle**
- A class should have only one reason to change
- Each class should have a single, well-defined purpose

**O - Open/Closed Principle**
- Software entities should be open for extension, closed for modification
- Add new functionality through extension, not modification

**L - Liskov Substitution Principle**
- Objects of a superclass should be replaceable with objects of its subclasses
- Subclasses must be substitutable for their base classes

**I - Interface Segregation Principle**
- Clients should not be forced to depend on interfaces they don't use
- Create specific, focused interfaces rather than large, general ones

**D - Dependency Inversion Principle**
- High-level modules should not depend on low-level modules
- Both should depend on abstractions, not concretions

### Additional Principles

**Composition over Inheritance**
- Favor object composition over class inheritance
- More flexible and promotes loose coupling

**Program to Interfaces**
- Depend on abstractions, not concrete implementations
- Makes code more flexible and testable

**Encapsulate What Varies**
- Identify aspects that vary and separate them from what stays the same
- Enables changes without affecting the rest of the code

## When to Use Design Patterns

### Good Indicators
- **Recurring problems** with similar solutions
- **Complex object creation** requirements
- **Need for flexibility** in object relationships
- **Communication between objects** needs to be managed
- **Code reusability** is important

### Warning Signs
- **Over-engineering** - Don't force patterns where they're not needed
- **Pattern obsession** - Not every problem needs a pattern
- **Complexity for its own sake** - Patterns should simplify, not complicate

### Pattern Selection Guidelines

**Ask these questions:**
1. What problem am I trying to solve?
2. What aspects of my design might change?
3. How can I make my code more flexible?
4. What relationships exist between my objects?
5. How can I promote reusability?

## Real-World Examples

### Singleton Pattern
**Use cases:**
- **Database connections** - Manage connection pool
- **Logging services** - Centralized logging
- **Configuration settings** - Application-wide settings
- **Cache managers** - Shared cache instances

### Factory Pattern
**Use cases:**
- **UI frameworks** - Create different types of UI components
- **Database drivers** - Create connections for different databases
- **Document processors** - Create parsers for different file formats
- **Game development** - Create different types of game objects

### Observer Pattern
**Use cases:**
- **Model-View architectures** - UI updates when data changes
- **Event handling systems** - Notify multiple listeners
- **Monitoring systems** - Alert when conditions are met
- **Social media feeds** - Notify followers of updates

## Common Misconceptions

**"Patterns are always good"**
- Patterns can add unnecessary complexity
- Use only when they solve actual problems

**"One pattern per problem"**
- Multiple patterns often work together
- Composite solutions are common

**"Patterns are language-specific"**
- Patterns are conceptual, not tied to specific languages
- Implementation varies by language capabilities

**"Patterns never change"**
- Patterns evolve with languages and practices
- New patterns emerge as technology advances

## Learning Strategy

### 1. Understand the Problem
- Study what problem each pattern solves
- Look at real-world analogies
- Understand the context where it's useful

### 2. Learn the Structure
- Understand the participants (classes/interfaces)
- Study the relationships between components
- Learn the collaboration patterns

### 3. Practice Implementation
- Code examples in your preferred language
- Try variations and modifications
- Experiment with different scenarios

### 4. Recognize When to Apply
- Practice identifying pattern opportunities
- Study existing codebases for pattern usage
- Review refactoring opportunities

> **💡 Best Practice:** Start with understanding problems before learning solutions. Focus on the "why" before the "how" of each pattern.

## Interview Preparation

**Common Questions:**
- Explain the difference between Singleton and Factory patterns
- When would you use Strategy vs State pattern?
- How do you implement the Observer pattern?
- What are the trade-offs of using Decorator pattern?
- Design a parking lot system using appropriate patterns

**Preparation Tips:**
1. **Know the basics** - Understand all 23 GoF patterns
2. **Practice coding** - Implement key patterns from memory
3. **Real examples** - Think of actual use cases from your experience
4. **Trade-offs** - Understand pros and cons of each pattern
5. **Combinations** - Know how patterns work together

In the next lessons, we'll dive deep into specific patterns with real implementation examples and design scenarios commonly asked in technical interviews.
    `,
    codeExamples: [
      {
        title: 'Singleton Pattern Implementation',
        language: 'java',
        code: `/**
 * Thread-safe Singleton implementation using double-checked locking
 * This is one of the most commonly asked patterns in interviews
 */
public class DatabaseConnection {
    // Volatile ensures visibility across threads
    private static volatile DatabaseConnection instance;
    private String connectionString;
    
    // Private constructor prevents external instantiation
    private DatabaseConnection() {
        // Simulate expensive initialization
        this.connectionString = "jdbc:mysql://localhost:3306/db";
        System.out.println("Database connection initialized");
    }
    
    /**
     * Double-checked locking for thread-safe lazy initialization
     * First check avoids synchronization overhead after initialization
     * Second check inside synchronized block ensures only one instance
     */
    public static DatabaseConnection getInstance() {
        if (instance == null) {  // First check (no locking)
            synchronized (DatabaseConnection.class) {
                if (instance == null) {  // Second check (with locking)
                    instance = new DatabaseConnection();
                }
            }
        }
        return instance;
    }
    
    public void executeQuery(String sql) {
        System.out.println("Executing query: " + sql);
    }
    
    public String getConnectionString() {
        return connectionString;
    }
}

/**
 * Alternative: Enum Singleton (Joshua Bloch recommendation)
 * Handles serialization and reflection attacks automatically
 */
enum DatabaseConnectionEnum {
    INSTANCE;
    
    private String connectionString;
    
    DatabaseConnectionEnum() {
        this.connectionString = "jdbc:mysql://localhost:3306/db";
    }
    
    public void executeQuery(String sql) {
        System.out.println("Executing query: " + sql);
    }
}

// Usage example
class SingletonDemo {
    public static void main(String[] args) {
        // Traditional singleton
        DatabaseConnection db1 = DatabaseConnection.getInstance();
        DatabaseConnection db2 = DatabaseConnection.getInstance();
        
        System.out.println("Same instance? " + (db1 == db2)); // true
        
        // Enum singleton
        DatabaseConnectionEnum.INSTANCE.executeQuery("SELECT * FROM users");
    }
}`
      },
      {
        title: 'Factory Pattern Implementation',
        language: 'python',
        code: `from abc import ABC, abstractmethod
from enum import Enum

class DocumentType(Enum):
    PDF = "pdf"
    WORD = "word"
    EXCEL = "excel"

class Document(ABC):
    """Abstract base class for all document types"""
    
    @abstractmethod
    def open(self) -> str:
        pass
    
    @abstractmethod
    def save(self, content: str) -> str:
        pass
    
    @abstractmethod
    def close(self) -> str:
        pass

class PDFDocument(Document):
    """Concrete implementation for PDF documents"""
    
    def open(self) -> str:
        return "Opening PDF document with Adobe Acrobat"
    
    def save(self, content: str) -> str:
        return f"Saving PDF: {content}"
    
    def close(self) -> str:
        return "Closing PDF document"

class WordDocument(Document):
    """Concrete implementation for Word documents"""
    
    def open(self) -> str:
        return "Opening Word document with Microsoft Word"
    
    def save(self, content: str) -> str:
        return f"Saving Word document: {content}"
    
    def close(self) -> str:
        return "Closing Word document"

class ExcelDocument(Document):
    """Concrete implementation for Excel documents"""
    
    def open(self) -> str:
        return "Opening Excel document with Microsoft Excel"
    
    def save(self, content: str) -> str:
        return f"Saving Excel spreadsheet: {content}"
    
    def close(self) -> str:
        return "Closing Excel document"

class DocumentFactory:
    """Factory class for creating different types of documents"""
    
    @staticmethod
    def create_document(doc_type: DocumentType) -> Document:
        """
        Factory method to create documents based on type
        
        Args:
            doc_type: Type of document to create
            
        Returns:
            Document instance
            
        Raises:
            ValueError: If document type is not supported
        """
        if doc_type == DocumentType.PDF:
            return PDFDocument()
        elif doc_type == DocumentType.WORD:
            return WordDocument()
        elif doc_type == DocumentType.EXCEL:
            return ExcelDocument()
        else:
            raise ValueError(f"Unsupported document type: {doc_type}")

# Usage example
def demo_factory_pattern():
    """Demonstrate factory pattern usage"""
    
    # Create different types of documents
    documents = [
        DocumentFactory.create_document(DocumentType.PDF),
        DocumentFactory.create_document(DocumentType.WORD),
        DocumentFactory.create_document(DocumentType.EXCEL)
    ]
    
    # Process all documents uniformly
    for i, doc in enumerate(documents, 1):
        print(f"\\n--- Document {i} ---")
        print(doc.open())
        print(doc.save(f"Content for document {i}"))
        print(doc.close())

# Alternative: Abstract Factory Pattern
class DocumentCreator(ABC):
    """Abstract factory for creating document families"""
    
    @abstractmethod
    def create_document(self) -> Document:
        pass
    
    @abstractmethod
    def create_template(self) -> str:
        pass

class PDFCreator(DocumentCreator):
    def create_document(self) -> Document:
        return PDFDocument()
    
    def create_template(self) -> str:
        return "Creating PDF template with forms"

class OfficeCreator(DocumentCreator):
    def create_document(self) -> Document:
        return WordDocument()
    
    def create_template(self) -> str:
        return "Creating Office template with styles"

if __name__ == "__main__":
    demo_factory_pattern()`
      },
      {
        title: 'Observer Pattern Implementation',
        language: 'typescript',
        code: `// Observer Pattern - Define one-to-many dependency between objects
// When one object changes state, all dependents are notified automatically

interface Observer {
  update(data: any): void;
}

interface Subject {
  addObserver(observer: Observer): void;
  removeObserver(observer: Observer): void;
  notifyObservers(data?: any): void;
}

// Concrete Subject - Stock Price Monitor
class StockPrice implements Subject {
  private observers: Observer[] = [];
  private stockSymbol: string;
  private price: number;

  constructor(symbol: string, initialPrice: number) {
    this.stockSymbol = symbol;
    this.price = initialPrice;
  }

  addObserver(observer: Observer): void {
    this.observers.push(observer);
    console.log(\`Observer added. Total observers: \${this.observers.length}\`);
  }

  removeObserver(observer: Observer): void {
    const index = this.observers.indexOf(observer);
    if (index > -1) {
      this.observers.splice(index, 1);
      console.log(\`Observer removed. Total observers: \${this.observers.length}\`);
    }
  }

  notifyObservers(data?: any): void {
    console.log(\`Notifying \${this.observers.length} observers...\`);
    this.observers.forEach(observer => {
      observer.update(data || {
        symbol: this.stockSymbol,
        price: this.price,
        timestamp: new Date()
      });
    });
  }

  setPrice(newPrice: number): void {
    console.log(\`\${this.stockSymbol} price changed from $\${this.price} to $\${newPrice}\`);
    this.price = newPrice;
    this.notifyObservers();
  }

  getPrice(): number {
    return this.price;
  }

  getSymbol(): string {
    return this.stockSymbol;
  }
}

// Concrete Observers
class EmailNotification implements Observer {
  private email: string;

  constructor(email: string) {
    this.email = email;
  }

  update(data: any): void {
    console.log(\`📧 Email to \${this.email}: \${data.symbol} is now $\${data.price}\`);
  }
}

class SMSNotification implements Observer {
  private phoneNumber: string;

  constructor(phone: string) {
    this.phoneNumber = phone;
  }

  update(data: any): void {
    console.log(\`📱 SMS to \${this.phoneNumber}: \${data.symbol} price alert: $\${data.price}\`);
  }
}

class DashboardDisplay implements Observer {
  private displayName: string;

  constructor(name: string) {
    this.displayName = name;
  }

  update(data: any): void {
    console.log(\`📊 \${this.displayName} updated: \${data.symbol} - $\${data.price} at \${data.timestamp.toLocaleTimeString()}\`);
  }
}

// Trading Bot that automatically reacts to price changes
class TradingBot implements Observer {
  private name: string;
  private threshold: number;

  constructor(name: string, buyThreshold: number) {
    this.name = name;
    this.threshold = buyThreshold;
  }

  update(data: any): void {
    if (data.price < this.threshold) {
      console.log(\`🤖 \${this.name}: Auto-buying \${data.symbol} at $\${data.price} (below threshold $\${this.threshold})\`);
    } else {
      console.log(\`🤖 \${this.name}: Monitoring \${data.symbol} at $\${data.price}\`);
    }
  }
}

// Demo usage
function demonstrateObserverPattern(): void {
  console.log("=== Observer Pattern Demo ===\\n");

  // Create subject (stock)
  const appleStock = new StockPrice("AAPL", 150.00);

  // Create observers
  const emailAlert = new EmailNotification("investor@example.com");
  const smsAlert = new SMSNotification("+1-555-0123");
  const dashboard = new DashboardDisplay("Main Dashboard");
  const tradingBot = new TradingBot("AutoTrader Pro", 145.00);

  // Subscribe observers
  appleStock.addObserver(emailAlert);
  appleStock.addObserver(smsAlert);
  appleStock.addObserver(dashboard);
  appleStock.addObserver(tradingBot);

  console.log("\\n--- Price Updates ---");
  
  // Simulate price changes
  appleStock.setPrice(155.25);
  console.log();
  
  appleStock.setPrice(142.50); // Should trigger trading bot
  console.log();

  // Remove an observer
  console.log("--- Removing SMS notifications ---");
  appleStock.removeObserver(smsAlert);
  
  appleStock.setPrice(148.75);
  console.log();
}

// Run the demo
demonstrateObserverPattern();

// Export for use in other modules
export { StockPrice, EmailNotification, SMSNotification, DashboardDisplay, TradingBot };`
      }
    ]
  },

  // Behavioral Course
  'behavioral-interview-prep': {
    title: 'Behavioral Interview Preparation',
    course: 'Behavioral Interview',
    category: 'Interview Preparation',
    duration: 30,
    isPremium: false,
    content: `
# Behavioral Interview Preparation

Behavioral interviews are **critical** for landing positions at top tech companies. They assess your **soft skills**, **cultural fit**, and ability to handle real-world workplace situations. Companies like Google, Amazon, and Facebook often weight behavioral interviews **equally** with technical interviews.

## Why Behavioral Interviews Matter

**What companies evaluate:**
- **Leadership potential** - Can you influence and guide others?
- **Problem-solving approach** - How do you tackle challenges?
- **Cultural fit** - Will you thrive in our environment?
- **Communication skills** - Can you articulate ideas clearly?
- **Growth mindset** - Do you learn from failures and feedback?

**Statistics:**
- **70% of senior hires** fail due to cultural/behavioral misfit
- **Amazon's Leadership Principles** are core to their hiring process
- **Google Project Oxygen** identified soft skills as key to management success

## The STAR Method

**Structure your responses using STAR:**

**S - Situation**
- Set the context
- Describe the background
- Keep it concise but clear

**T - Task**
- Explain your responsibility
- What needed to be accomplished?
- What was your specific role?

**A - Action**
- Detail the steps you took
- Focus on YOUR actions
- Be specific about your contributions

**R - Result**
- Quantify the outcome
- What did you learn?
- How did it benefit the team/company?

### STAR Example
**Question:** "Tell me about a time you had to deal with a difficult team member."

**Situation:** "In my previous role as a senior developer, I was leading a team of 5 engineers working on a critical payment system for an e-commerce platform with a tight 6-week deadline."

**Task:** "One team member consistently missed deadlines, delivered code with bugs, and was unresponsive in team meetings, putting our project timeline at risk."

**Action:** "I scheduled a private one-on-one meeting to understand the underlying issues. I discovered they were overwhelmed with personal issues and struggling with some technical concepts. I worked with them to create a support plan: pair programming sessions twice a week, breaking their tasks into smaller chunks, and providing resources for technical skill development."

**Result:** "Within two weeks, their performance improved significantly. We delivered the project on time, and the team member became one of our strongest contributors. They later thanked me for the support and said it was a turning point in their career."

## Common Question Categories

### 1. Leadership & Influence
**Sample Questions:**
- "Tell me about a time you had to convince someone to change their approach."
- "Describe a situation where you had to lead without authority."
- "Give me an example of when you took initiative on a project."

**What they're looking for:**
- Ability to influence others
- Taking ownership and responsibility
- Driving results through others

### 2. Problem Solving & Decision Making
**Sample Questions:**
- "Tell me about the most complex problem you've solved."
- "Describe a time you had to make a decision with incomplete information."
- "Give me an example of when you had to choose between multiple good options."

**What they're looking for:**
- Analytical thinking
- Decision-making process
- Handling ambiguity

### 3. Failure & Learning
**Sample Questions:**
- "Tell me about a time you failed and what you learned."
- "Describe a project that didn't go as planned."
- "Give me an example of when you received difficult feedback."

**What they're looking for:**
- Growth mindset
- Resilience and adaptability
- Learning from mistakes

### 4. Teamwork & Collaboration
**Sample Questions:**
- "Tell me about a time you had to work with a difficult colleague."
- "Describe a situation where you had to collaborate across different teams."
- "Give me an example of when you had to give constructive feedback."

**What they're looking for:**
- Interpersonal skills
- Conflict resolution
- Building relationships

### 5. Customer Focus
**Sample Questions:**
- "Tell me about a time you went above and beyond for a customer."
- "Describe a situation where you had to balance customer needs with business constraints."
- "Give me an example of when you improved the customer experience."

**What they're looking for:**
- Customer-centric thinking
- Balancing competing priorities
- Understanding user needs

## Company-Specific Frameworks

### Amazon Leadership Principles
**Key principles to prepare for:**
- **Customer Obsession** - Start with customer and work backwards
- **Ownership** - Act on behalf of entire company
- **Invent and Simplify** - Innovate and find simple solutions
- **Learn and Be Curious** - Continuous learning and improvement
- **Hire and Develop the Best** - Raise the performance bar

### Google's Googleyness
**What they look for:**
- **Intellectual humility** - Admitting when you're wrong
- **Comfort with ambiguity** - Thriving in uncertain situations
- **Evidence of impact** - Measurable contributions
- **Collaborative spirit** - Working well with others

### Meta's Values
**Core values:**
- **Move Fast** - Bias toward action
- **Be Bold** - Taking calculated risks
- **Focus on Impact** - Prioritizing high-impact work
- **Be Open** - Transparent communication
- **Build Social Value** - Positive impact on society

## Preparation Strategy

### 1. Story Bank Creation
**Prepare 15-20 stories covering:**
- 3-4 leadership examples
- 3-4 problem-solving scenarios
- 2-3 failure/learning experiences
- 3-4 teamwork situations
- 2-3 customer-focused examples
- 2-3 innovation/creativity instances

### 2. Story Mapping
**For each story, identify:**
- Which questions it could answer
- Key leadership principles it demonstrates
- Quantifiable results and metrics
- Lessons learned and growth

### 3. Practice & Refinement
**Regular practice routine:**
- **Week 1-2:** Develop story bank using STAR method
- **Week 3:** Practice with friends/colleagues
- **Week 4:** Record yourself and refine delivery
- **Week 5:** Mock interviews with behavioral focus

### 4. Research & Preparation
**Before each interview:**
- Study company values and culture
- Research interviewer's background (LinkedIn)
- Prepare thoughtful questions about the role
- Review job description for key competencies

## Common Mistakes to Avoid

**Story-related mistakes:**
- **Too vague** - Lack specific details and metrics
- **Not your story** - Talking about team achievements without your role
- **Too long** - Rambling without structure
- **Negative tone** - Speaking poorly about previous employers

**Behavioral mistakes:**
- **Not listening** - Missing nuances in questions
- **Generic answers** - Using same story for different questions
- **No questions** - Not asking thoughtful questions about role/company
- **Poor body language** - Lack of enthusiasm or engagement

## Advanced Tips

### Quantify Your Impact
**Instead of:** "I improved the system performance."
**Say:** "I optimized the database queries, reducing response time by 40% and improving user satisfaction scores from 3.2 to 4.1."

### Show Growth
**Demonstrate evolution:** Connect past experiences to current capabilities and future goals.

### Be Authentic
**Genuine stories** resonate better than perfect scenarios. Show vulnerability and real learning.

### Practice Active Listening
**Clarify questions** if needed. Ensure you're answering what's being asked.

> **💡 Interview Tip:** Prepare stories that can be adapted to multiple questions. A good leadership story might also demonstrate problem-solving, customer focus, or learning from failure.

## Questions to Ask Interviewers

**About the role:**
- "What does success look like in this position after 6 months?"
- "What are the biggest challenges facing the team right now?"
- "How does this role contribute to the company's broader goals?"

**About the team:**
- "Can you tell me about the team dynamics and collaboration style?"
- "How does the team handle disagreements or conflicting priorities?"
- "What opportunities are there for mentorship and growth?"

**About the company:**
- "How has the company culture evolved as it's grown?"
- "What excites you most about the company's future direction?"
- "How does the company support professional development?"

Remember: Behavioral interviews are conversations, not interrogations. Show genuine interest in the role and company while demonstrating your capabilities through compelling stories.
    `,
    codeExamples: [
      {
        title: 'STAR Method Template',
        language: 'markdown',
        code: `# STAR Method Response Template

## Question: [Insert behavioral question here]

### Situation (Context)
- **When:** [Time period/duration]
- **Where:** [Company, team, project context]
- **Background:** [What was happening, why was this important]
- **Stakeholders:** [Who was involved, team size, reporting structure]

**Example:**
"In Q2 of last year, I was working as a senior software engineer at TechCorp, leading the backend development for our mobile app that served 500K+ daily active users. Our team of 6 engineers was facing a critical performance issue where API response times had degraded by 60% over the past month, causing user complaints and affecting our App Store ratings."

### Task (Responsibility)
- **Your role:** [What was specifically your responsibility]
- **Objectives:** [What needed to be accomplished]
- **Constraints:** [Timeline, resources, limitations]
- **Stakes:** [Why this mattered, impact of success/failure]

**Example:**
"As the technical lead, I was responsible for diagnosing the root cause and implementing a solution within 2 weeks before our major product launch. The executive team was concerned because any delay would impact our partnership with a major client worth $2M in annual revenue."

### Action (What you did)
- **Analysis:** [How you approached the problem]
- **Decision process:** [How you evaluated options]
- **Implementation:** [Specific steps you took]
- **Collaboration:** [How you worked with others]
- **Challenges:** [Obstacles you overcame]

**Example:**
"I first conducted a comprehensive performance audit using APM tools and identified that our database queries were the bottleneck. I assembled a cross-functional team including a DBA and DevOps engineer. We analyzed query patterns and discovered that recent feature additions had created N+1 query problems.

I proposed a three-pronged solution:
1. Implement query optimization and database indexing
2. Add Redis caching for frequently accessed data  
3. Refactor the most problematic API endpoints

I personally led the refactoring effort, working 12-hour days to rewrite the core user authentication and profile APIs. I also set up automated performance monitoring to prevent future regressions."

### Result (Outcome)
- **Metrics:** [Quantifiable results, before/after comparison]
- **Timeline:** [When results were achieved]
- **Impact:** [Business/technical/team impact]
- **Learning:** [What you learned, how you grew]
- **Follow-up:** [Long-term outcomes, processes improved]

**Example:**
"Within 10 days, we reduced average API response time from 1.2 seconds to 300ms (75% improvement). User satisfaction scores increased from 3.1 to 4.2 stars, and we successfully launched on schedule. The client partnership was secured, and our solution became a template for other teams.

Personally, I learned the importance of proactive monitoring and performance testing in CI/CD pipelines. I also developed stronger project management skills by coordinating across multiple teams under pressure. This experience led to my promotion to Staff Engineer and I now mentor other developers on performance optimization techniques."

---

## Key Elements Checklist:
- [ ] Specific timeframe and context
- [ ] Clear role and responsibility  
- [ ] Detailed actions taken
- [ ] Quantified results
- [ ] Personal learning/growth
- [ ] Demonstrates relevant competency
- [ ] Appropriate length (2-3 minutes spoken)
- [ ] Professional and positive tone

## Competencies Demonstrated:
- [ ] Leadership
- [ ] Problem-solving
- [ ] Technical expertise
- [ ] Communication
- [ ] Teamwork
- [ ] Initiative
- [ ] Results orientation
- [ ] Learning agility`
      },
      {
        title: 'Story Bank Organizer',
        language: 'yaml',
        code: `# Behavioral Interview Story Bank
# Organize your experiences by competency and question type

stories:
  leadership:
    - title: "Leading Cross-Functional API Migration"
      situation: "Inherited legacy API serving 1M+ requests/day with 99.9% uptime requirement"
      task: "Lead migration to microservices architecture with zero downtime"
      action: "Created migration plan, coordinated 4 teams, implemented blue-green deployment"
      result: "Successful migration, 50% improved performance, 90% faster deployments"
      competencies: [leadership, technical_excellence, project_management]
      companies: [amazon, google, meta] # Where this story works well
      
    - title: "Mentoring Junior Developer"
      situation: "New graduate struggling with code quality and missing deadlines"
      task: "Help them become productive team member within 3 months"
      action: "Created structured mentoring plan, daily code reviews, pair programming"
      result: "Became top performer, received promotion, now mentors others"
      competencies: [leadership, developing_others, communication]
      companies: [all]

  problem_solving:
    - title: "Debugging Production Memory Leak"
      situation: "Critical service crashing every 6 hours in production"
      task: "Identify and fix root cause within 24 hours"
      action: "Systematic debugging approach, memory profiling, code analysis"
      result: "Found and fixed bug, prevented $50K in lost revenue"
      competencies: [problem_solving, technical_depth, ownership]
      companies: [all]
      
    - title: "Optimizing Database Performance"
      situation: "Dashboard load times increased from 2s to 15s over 3 months"
      task: "Investigate and resolve performance degradation"
      action: "Query analysis, indexing strategy, caching implementation"
      result: "Reduced load time to 800ms, improved user satisfaction 40%"
      competencies: [problem_solving, data_analysis, customer_obsession]
      companies: [amazon, netflix, uber]

  failure_learning:
    - title: "Failed Product Launch Recovery"
      situation: "Mobile app launch failed due to server crashes under load"
      task: "Recover quickly and prevent future issues"
      action: "Post-mortem analysis, load testing implementation, monitoring improvements"
      result: "Successful relaunch in 1 week, 99.9% uptime since"
      competencies: [learning_agility, resilience, process_improvement]
      companies: [all]

  teamwork:
    - title: "Resolving Team Conflict"
      situation: "Frontend and Backend teams in conflict over API design"
      task: "Mediate solution that satisfies both teams' needs"
      action: "Facilitated meetings, created shared documentation, found compromise"
      result: "Teams collaborated effectively, project delivered on time"
      competencies: [collaboration, communication, conflict_resolution]
      companies: [all]

  customer_focus:
    - title: "Improving User Onboarding"
      situation: "60% user drop-off during registration process"
      task: "Reduce friction and improve conversion rates"
      action: "User research, A/B testing, simplified flow design"
      result: "Increased conversion rate to 85%, added 10K new users monthly"
      competencies: [customer_obsession, data_driven, innovation]
      companies: [amazon, google, meta, netflix]

# Question Mapping
question_mappings:
  "Tell me about a time you had to influence someone":
    - "Leading Cross-Functional API Migration"
    - "Resolving Team Conflict"
    
  "Describe a challenging technical problem":
    - "Debugging Production Memory Leak"
    - "Optimizing Database Performance"
    
  "Tell me about a failure and what you learned":
    - "Failed Product Launch Recovery"
    
  "Give me an example of going above and beyond":
    - "Mentoring Junior Developer"
    - "Improving User Onboarding"

# Company-Specific Preparation
company_focus:
  amazon:
    key_principles: [customer_obsession, ownership, invent_and_simplify]
    emphasize_stories: [customer_focus, problem_solving, leadership]
    
  google:
    key_values: [impact, innovation, collaboration]
    emphasize_stories: [problem_solving, teamwork, learning]
    
  meta:
    key_values: [move_fast, be_bold, focus_on_impact]
    emphasize_stories: [leadership, innovation, customer_focus]

# Practice Schedule
practice_plan:
  week_1: "Develop STAR responses for all stories"
  week_2: "Practice with friends, get feedback"
  week_3: "Record responses, refine timing"
  week_4: "Mock interviews, company-specific prep"
  week_5: "Final polish, stress scenarios"`
      }
    ]
  }
};