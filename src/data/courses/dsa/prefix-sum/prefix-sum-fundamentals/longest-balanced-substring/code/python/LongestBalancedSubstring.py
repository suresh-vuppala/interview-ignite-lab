from collections import defaultdict

class Solution:
    def longestBalancedSubstring(self, s: str) -> int:
        # We track the difference between character counts
        # State: (count_a - count_b, count_a - count_c)
        state_map = defaultdict(lambda: -1)
        state_map[(0, 0)] = -1  # Initial state at index -1
        
        count_a = 0
        count_b = 0
        count_c = 0
        max_length = 0
        
        for i in range(len(s)):
            # Update counts
            if s[i] == 'a':
                count_a += 1
            elif s[i] == 'b':
                count_b += 1
            else:
                count_c += 1
            
            # Calculate state as a tuple
            state = (count_a - count_b, count_a - count_c)
            
            # If state was seen before, substring between is balanced
            if state in state_map:
                max_length = max(max_length, i - state_map[state])
            else:
                # Store first occurrence of this state
                state_map[state] = i
        
        return max_length
