class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE WITH SORTING ====================
    # Time: O(n×k log k) | Space: O(k)
    def findAnagramsBruteForce(self, s, p):
        result = []
        k = len(p)
        n = len(s)
        sorted_p = sorted(p)
        
        # Check each window
        for i in range(n - k + 1):
            window = s[i:i + k]
            if sorted(window) == sorted_p:
                result.append(i)
        
        return result
    
    # ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAP ====================
    # Time: O(n) | Space: O(1)
    def findAnagramsFreqMap(self, s, p):
        result = []
        k = len(p)
        n = len(s)
        
        if n < k:
            return result
        
        # Build frequency maps
        p_count = {}
        window_count = {}
        
        for char in p:
            p_count[char] = p_count.get(char, 0) + 1
        
        # First window
        for i in range(k):
            char = s[i]
            window_count[char] = window_count.get(char, 0) + 1
        
        # Check first window
        if window_count == p_count:
            result.append(0)
        
        # Slide window
        for i in range(k, n):
            # Add new character
            new_char = s[i]
            window_count[new_char] = window_count.get(new_char, 0) + 1
            
            # Remove old character
            old_char = s[i - k]
            window_count[old_char] -= 1
            if window_count[old_char] == 0:
                del window_count[old_char]
            
            # Check if anagram
            if window_count == p_count:
                result.append(i - k + 1)
        
        return result
    
    # ==================== SOLUTION 3: OPTIMIZED WITH MATCH COUNT ====================
    # Time: O(n) | Space: O(1)
    def findAnagramsOptimized(self, s, p):
        result = []
        k = len(p)
        n = len(s)
        
        if n < k:
            return result
        
        # Frequency arrays for lowercase letters
        p_count = [0] * 26
        window_count = [0] * 26
        
        # Build pattern frequency
        for char in p:
            p_count[ord(char) - ord('a')] += 1
        
        # Build first window and count matches
        matches = 0
        for i in range(k):
            idx = ord(s[i]) - ord('a')
            window_count[idx] += 1
        
        # Count initial matches
        for i in range(26):
            if p_count[i] == window_count[i]:
                matches += 1
        
        if matches == 26:
            result.append(0)
        
        # Slide window
        for i in range(k, n):
            # Add new character
            new_idx = ord(s[i]) - ord('a')
            window_count[new_idx] += 1
            if window_count[new_idx] == p_count[new_idx]:
                matches += 1
            elif window_count[new_idx] == p_count[new_idx] + 1:
                matches -= 1
            
            # Remove old character
            old_idx = ord(s[i - k]) - ord('a')
            window_count[old_idx] -= 1
            if window_count[old_idx] == p_count[old_idx]:
                matches += 1
            elif window_count[old_idx] == p_count[old_idx] - 1:
                matches -= 1
            
            # Check if all match
            if matches == 26:
                result.append(i - k + 1)
        
        return result
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def findAnagrams(self, s, p):
        return self.findAnagramsOptimized(s, p)
