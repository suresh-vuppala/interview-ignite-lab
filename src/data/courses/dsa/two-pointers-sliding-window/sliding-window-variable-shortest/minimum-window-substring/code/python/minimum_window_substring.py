# ============================================================
# Minimum Window Substring
# ============================================================

from collections import Counter, defaultdict

# ============================================================
# Solution 1: Brute Force
# Time: O(N²×M) | Space: O(M)
# ============================================================
class Solution1:
    def minWindow(self, s: str, t: str) -> str:
        # Build frequency map for target string t
        target_freq = Counter(t)
        
        min_length = float('inf')
        min_window = ""
        
        # Try all possible substrings
        for start in range(len(s)):
            window_freq = defaultdict(int)
            
            for end in range(start, len(s)):
                # Add current character to window
                window_freq[s[end]] += 1
                
                # Check if current window contains all characters of t
                is_valid = all(window_freq[c] >= target_freq[c] for c in target_freq)
                
                # Update minimum window if valid and smaller
                if is_valid and end - start + 1 < min_length:
                    min_length = end - start + 1
                    min_window = s[start:end + 1]
                    break  # No need to expand further from this start
        
        return min_window

# ============================================================
# Solution 2: Sliding Window + Frequency Tracking (Optimal)
# Time: O(N+M) | Space: O(N+M)
# ============================================================
class Solution2:
    def minWindow(self, s: str, t: str) -> str:
        # Step 1: Build frequency map for target string t
        target_freq = Counter(t)
        
        # Step 2: Initialize variables
        required = len(target_freq)  # Number of unique chars in t that need to be present
        formed = 0                    # Number of unique chars in current window with desired frequency
        
        window_freq = defaultdict(int)  # Frequency map for current window
        
        left = 0                      # Left pointer of sliding window
        min_length = float('inf')     # Length of minimum window found
        min_start = 0                 # Start index of minimum window
        
        # Step 3: Expand window by moving right pointer
        for right in range(len(s)):
            right_char = s[right]
            
            # Add character from right to window
            window_freq[right_char] += 1
            
            # Check if frequency of current character matches the desired count in t
            if right_char in target_freq and window_freq[right_char] == target_freq[right_char]:
                formed += 1  # One more unique character requirement satisfied
            
            # Step 4: Try to shrink window from left while it's still valid
            while formed == required:
                # Update minimum window if current is smaller
                current_length = right - left + 1
                if current_length < min_length:
                    min_length = current_length
                    min_start = left
                
                # Remove character from left of window
                left_char = s[left]
                window_freq[left_char] -= 1
                
                # Check if removing this character breaks a requirement
                if left_char in target_freq and window_freq[left_char] < target_freq[left_char]:
                    formed -= 1  # One unique character requirement no longer satisfied
                
                left += 1  # Shrink window from left
        
        # Step 5: Return result
        return "" if min_length == float('inf') else s[min_start:min_start + min_length]

# ============================================================
# Solution 3: Binary Search on Length + Sliding Window
# Time: O(N×log N) | Space: O(N+M)
# ============================================================
class Solution3:
    def _can_find_window(self, s: str, t: str, window_len: int) -> int:
        """Helper: Check if any window of given length contains all chars of t.
        Returns start index if found, -1 otherwise.
        """
        # Build target frequency map
        target_freq = Counter(t)
        window_freq = defaultdict(int)
        
        required = len(target_freq)
        formed = 0
        
        # Initialize first window
        for i in range(min(window_len, len(s))):
            window_freq[s[i]] += 1
            if s[i] in target_freq and window_freq[s[i]] == target_freq[s[i]]:
                formed += 1
        
        # Check first window
        if formed == required:
            return 0
        
        # Slide window across string
        for right in range(window_len, len(s)):
            left = right - window_len
            
            # Add new character on right
            right_char = s[right]
            window_freq[right_char] += 1
            if right_char in target_freq and window_freq[right_char] == target_freq[right_char]:
                formed += 1
            
            # Remove character on left
            left_char = s[left]
            if left_char in target_freq and window_freq[left_char] == target_freq[left_char]:
                formed -= 1
            window_freq[left_char] -= 1
            
            # Check if current window is valid
            if formed == required:
                return left + 1
        
        return -1  # No valid window found
    
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""
        
        # Binary search on window length
        low = len(t)
        high = len(s)
        min_length = float('inf')
        min_start = 0
        
        while low <= high:
            mid = low + (high - low) // 2
            
            # Check if window of length mid exists
            start = self._can_find_window(s, t, mid)
            if start != -1:
                # Found valid window, try smaller length
                min_length = mid
                min_start = start
                high = mid - 1
            else:
                # Need larger window
                low = mid + 1
        
        return "" if min_length == float('inf') else s[min_start:min_start + min_length]
