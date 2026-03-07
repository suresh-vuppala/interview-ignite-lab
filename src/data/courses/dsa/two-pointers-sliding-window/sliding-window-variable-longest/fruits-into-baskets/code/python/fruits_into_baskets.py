class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n²) | Space: O(n)
    def totalFruitBruteForce(self, fruits):
        n = len(fruits)
        max_fruits = 0
        
        # Check all subarrays
        for i in range(n):
            types = set()
            for j in range(i, n):
                types.add(fruits[j])
                
                # Check if valid (at most 2 types)
                if len(types) <= 2:
                    max_fruits = max(max_fruits, j - i + 1)
                else:
                    break  # More than 2 types, no point continuing
        
        return max_fruits
    
    # ==================== SOLUTION 2: SLIDING WINDOW WITH HASHMAP ====================
    # Time: O(n) | Space: O(1)
    def totalFruitSlidingWindow(self, fruits):
        freq = {}
        left = 0
        max_fruits = 0
        
        for right in range(len(fruits)):
            # Add fruit to window
            freq[fruits[right]] = freq.get(fruits[right], 0) + 1
            
            # Shrink window while more than 2 types
            while len(freq) > 2:
                freq[fruits[left]] -= 1
                if freq[fruits[left]] == 0:
                    del freq[fruits[left]]
                left += 1
            
            # Update max fruits
            max_fruits = max(max_fruits, right - left + 1)
        
        return max_fruits
    
    # ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    # Time: O(n) | Space: O(1)
    def totalFruitOptimized(self, fruits):
        freq = {}
        left = 0
        
        for right in range(len(fruits)):
            # Add fruit to window
            freq[fruits[right]] = freq.get(fruits[right], 0) + 1
            
            # If more than 2 types, slide window
            if len(freq) > 2:
                freq[fruits[left]] -= 1
                if freq[fruits[left]] == 0:
                    del freq[fruits[left]]
                left += 1
        
        # Window size is the answer
        return len(fruits) - left
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def totalFruit(self, fruits):
        return self.totalFruitSlidingWindow(fruits)
