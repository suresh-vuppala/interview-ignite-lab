export const dsaArraysSlidingWindow = {
  title: 'Sliding Window Pattern',
  course: 'DSA',
  duration: 45,
  isPremium: true,
  content: "## Understanding Sliding Window\n\nThe sliding window technique is a powerful algorithmic pattern used to solve problems involving **arrays** or **strings** where you need to find a contiguous subset that satisfies certain conditions.\n\n### Key Concepts\n\nThe sliding window maintains a subset of elements and slides through the array by:\n- **Expanding** the window to include new elements\n- **Contracting** the window to exclude elements\n- Maintaining specific properties within the window\n\n### Common Use Cases\n\n- Finding the **maximum sum** of a subarray of size k\n- Longest substring with at most k distinct characters\n- Minimum window substring containing all characters\n- Finding anagrams in a string\n\n> This technique reduces time complexity from O(n²) to O(n) for many problems by avoiding redundant calculations.\n\n## Fixed Window Size\n\nWhen the window size is fixed, you:\n\n1. Initialize the window with the first k elements\n2. Slide the window one position at a time\n3. Remove the leftmost element and add the new rightmost element\n4. Update your result based on the current window\n\n### Example: Maximum Sum Subarray\n\n- Input: [2, 1, 5, 1, 3, 2], k = 3\n- Find maximum sum of any subarray of size 3\n- Answer: 9 (subarray [5, 1, 3])\n\n## Variable Window Size\n\nFor **dynamic** window sizes, you need to:\n\n- Use two pointers (left and right)\n- Expand the window by moving right pointer\n- Contract the window by moving left pointer when constraints are violated\n- Track the best result seen so far",
  codeExamples: [
    {
      title: 'Fixed Window - Maximum Sum Subarray',
      language: 'python',
      code: "def max_sum_subarray(arr, k):\n    \"\"\"\n    Find maximum sum of subarray of size k\n    Time: O(n), Space: O(1)\n    \"\"\"\n    n = len(arr)\n    if n < k:\n        return None\n    \n    # Calculate sum of first window\n    window_sum = sum(arr[:k])\n    max_sum = window_sum\n    \n    # Slide the window\n    for i in range(k, n):\n        # Add new element, remove old element\n        window_sum = window_sum + arr[i] - arr[i - k]\n        max_sum = max(max_sum, window_sum)\n    \n    return max_sum\n\n# Example usage\narr = [2, 1, 5, 1, 3, 2]\nk = 3\nprint(max_sum_subarray(arr, k))  # Output: 9"
    },
    {
      title: 'Variable Window - Longest Substring',
      language: 'python',
      code: "def longest_substring_k_distinct(s, k):\n    \"\"\"\n    Find longest substring with at most k distinct characters\n    Time: O(n), Space: O(k)\n    \"\"\"\n    char_count = {}\n    left = 0\n    max_length = 0\n    \n    for right in range(len(s)):\n        # Expand window\n        char_count[s[right]] = char_count.get(s[right], 0) + 1\n        \n        # Contract window if constraint violated\n        while len(char_count) > k:\n            char_count[s[left]] -= 1\n            if char_count[s[left]] == 0:\n                del char_count[s[left]]\n            left += 1\n        \n        # Update result\n        max_length = max(max_length, right - left + 1)\n    \n    return max_length\n\n# Example\ns = \"eceba\"\nk = 2\nprint(longest_substring_k_distinct(s, k))  # Output: 3 (\"ece\")"
    }
  ]
};
