class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n²) | Space: O(1)
    def characterReplacementBruteForce(self, s, k):
        n = len(s)
        max_len = 0
        
        # Check all substrings
        for i in range(n):
            freq = {}
            for j in range(i, n):
                # Update frequency
                freq[s[j]] = freq.get(s[j], 0) + 1
                
                # Find max frequency
                max_freq = max(freq.values())
                length = j - i + 1
                
                # Check if valid (replacements needed ≤ k)
                if length - max_freq <= k:
                    max_len = max(max_len, length)
        
        return max_len
    
    # ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAP ====================
    # Time: O(n×26) = O(n) | Space: O(1)
    def characterReplacementSlidingWindow(self, s, k):
        n = len(s)
        freq = {}
        left = 0
        max_len = 0
        
        for right in range(n):
            # Add character to window
            freq[s[right]] = freq.get(s[right], 0) + 1
            
            # Shrink window if invalid
            while (right - left + 1) - max(freq.values()) > k:
                freq[s[left]] -= 1
                left += 1
            
            # Update max length
            max_len = max(max_len, right - left + 1)
        
        return max_len
    
    # ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    # Time: O(n) | Space: O(1)
    def characterReplacementOptimized(self, s, k):
        n = len(s)
        freq = {}
        left = 0
        max_len = 0
        max_freq = 0
        
        for right in range(n):
            # Add character to window
            freq[s[right]] = freq.get(s[right], 0) + 1
            
            # Update max frequency
            max_freq = max(max_freq, freq[s[right]])
            
            # Shrink window if invalid
            while (right - left + 1) - max_freq > k:
                freq[s[left]] -= 1
                left += 1
            
            # Update max length
            max_len = max(max_len, right - left + 1)
        
        return max_len
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def characterReplacement(self, s, k):
        return self.characterReplacementOptimized(s, k)
