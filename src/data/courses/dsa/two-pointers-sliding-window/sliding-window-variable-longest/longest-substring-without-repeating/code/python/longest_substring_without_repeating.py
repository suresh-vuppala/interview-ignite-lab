class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(N³) | Space: O(min(N, M))
    def lengthOfLongestSubstringBruteForce(self, s):
        n = len(s)
        max_len = 0
        
        for i in range(n):
            for j in range(i, n):
                if self._allUnique(s, i, j):
                    max_len = max(max_len, j - i + 1)
        
        return max_len
    
    def _allUnique(self, s, start, end):
        char_set = set()
        for i in range(start, end + 1):
            if s[i] in char_set:
                return False
            char_set.add(s[i])
        return True
    
    # ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    # Time: O(N²) | Space: O(min(N, M))
    def lengthOfLongestSubstringBruteOptimized(self, s):
        n = len(s)
        max_len = 0
        
        for i in range(n):
            char_set = set()
            for j in range(i, n):
                if s[j] in char_set:
                    break
                char_set.add(s[j])
                max_len = max(max_len, j - i + 1)
        
        return max_len
    
    # ==================== SOLUTION 3: SLIDING WINDOW (TWO POINTERS) ====================
    # Time: O(2N) = O(N) | Space: O(min(N, M))
    def lengthOfLongestSubstringSlidingWindow(self, s):
        n = len(s)
        char_set = set()
        left = 0
        max_len = 0
        
        for right in range(n):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(s[right])
            max_len = max(max_len, right - left + 1)
        
        return max_len
    
    # ==================== SOLUTION 4: SLIDING WINDOW WITH HASHMAP ====================
    # Time: O(N) | Space: O(min(N, M))
    def lengthOfLongestSubstringHashMap(self, s):
        n = len(s)
        char_map = {}
        left = 0
        max_len = 0
        
        for right in range(n):
            if s[right] in char_map:
                left = max(left, char_map[s[right]] + 1)
            char_map[s[right]] = right
            max_len = max(max_len, right - left + 1)
        
        return max_len
    
    # ==================== SOLUTION 5: OPTIMIZED WITH ARRAY (ASCII) - OPTIMAL ====================
    # Time: O(N) | Space: O(1)
    def lengthOfLongestSubstring(self, s):
        char_index = [-1] * 128
        left = 0
        max_len = 0
        
        for right in range(len(s)):
            if char_index[ord(s[right])] >= left:
                left = char_index[ord(s[right])] + 1
            char_index[ord(s[right])] = right
            max_len = max(max_len, right - left + 1)
        
        return max_len
