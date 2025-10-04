export const dsaArraysIntro = {
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
};
