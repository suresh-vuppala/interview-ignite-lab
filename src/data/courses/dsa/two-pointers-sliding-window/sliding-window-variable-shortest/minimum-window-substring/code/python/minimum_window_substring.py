from collections import Counter

class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n³) | Space: O(m)
    def minWindowBruteForce(self, s, t):
        if not s or not t:
            return ""
        
        t_count = Counter(t)
        min_window = ""
        min_len = float('inf')
        
        # Check all substrings
        for i in range(len(s)):
            for j in range(i, len(s)):
                # Check if substring contains all chars of t
                window = s[i:j+1]
                window_count = Counter(window)
                
                valid = True
                for char, count in t_count.items():
                    if window_count[char] < count:
                        valid = False
                        break
                
                if valid and len(window) < min_len:
                    min_len = len(window)
                    min_window = window
        
        return min_window
    
    # ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAPS ====================
    # Time: O(n+m) | Space: O(m+k)
    def minWindowSlidingWindow(self, s, t):
        if not s or not t:
            return ""
        
        t_count = Counter(t)
        window_count = {}
        
        left = 0
        min_len = float('inf')
        min_start = 0
        
        for right in range(len(s)):
            # Add character to window
            char = s[right]
            window_count[char] = window_count.get(char, 0) + 1
            
            # Try to shrink window
            while self._contains_all(window_count, t_count):
                # Update minimum
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_start = left
                
                # Shrink from left
                window_count[s[left]] -= 1
                if window_count[s[left]] == 0:
                    del window_count[s[left]]
                left += 1
        
        return s[min_start:min_start + min_len] if min_len != float('inf') else ""
    
    def _contains_all(self, window_count, t_count):
        for char, count in t_count.items():
            if window_count.get(char, 0) < count:
                return False
        return True
    
    # ==================== SOLUTION 3: OPTIMIZED WITH MATCH COUNT ====================
    # Time: O(n+m) | Space: O(m+k)
    def minWindowOptimized(self, s, t):
        if not s or not t:
            return ""
        
        t_count = Counter(t)
        required = len(t_count)
        
        window_count = {}
        matched = 0
        
        left = 0
        min_len = float('inf')
        min_start = 0
        
        for right in range(len(s)):
            # Add character to window
            char = s[right]
            window_count[char] = window_count.get(char, 0) + 1
            
            # Check if this character's frequency matches
            if char in t_count and window_count[char] == t_count[char]:
                matched += 1
            
            # Try to shrink window
            while matched == required:
                # Update minimum
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_start = left
                
                # Shrink from left
                left_char = s[left]
                window_count[left_char] -= 1
                if left_char in t_count and window_count[left_char] < t_count[left_char]:
                    matched -= 1
                left += 1
        
        return s[min_start:min_start + min_len] if min_len != float('inf') else ""
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def minWindow(self, s, t):
        return self.minWindowOptimized(s, t)
