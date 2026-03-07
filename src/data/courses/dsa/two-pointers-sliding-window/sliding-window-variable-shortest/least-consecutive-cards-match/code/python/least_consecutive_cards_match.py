class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n³) | Space: O(n)
    def minimumCardPickupBruteForce(self, cards):
        n = len(cards)
        min_len = float('inf')
        
        # Check all subarrays
        for i in range(n):
            for j in range(i, n):
                # Check if subarray has duplicates
                seen = set()
                has_duplicate = False
                
                for k in range(i, j + 1):
                    if cards[k] in seen:
                        has_duplicate = True
                        break
                    seen.add(cards[k])
                
                if has_duplicate:
                    min_len = min(min_len, j - i + 1)
        
        return min_len if min_len != float('inf') else -1
    
    # ==================== SOLUTION 2: HASHMAP WITH LAST SEEN POSITION ====================
    # Time: O(n) | Space: O(n)
    def minimumCardPickupHashMap(self, cards):
        last_seen = {}
        min_len = float('inf')
        
        for i, card in enumerate(cards):
            # If card seen before, calculate distance
            if card in last_seen:
                distance = i - last_seen[card] + 1
                min_len = min(min_len, distance)
            
            # Update last seen position
            last_seen[card] = i
        
        return min_len if min_len != float('inf') else -1
    
    # ==================== SOLUTION 3: SLIDING WINDOW ====================
    # Time: O(n) | Space: O(n)
    def minimumCardPickupSlidingWindow(self, cards):
        window = {}
        left = 0
        min_len = float('inf')
        
        for right in range(len(cards)):
            card = cards[right]
            
            # If card already in window, we found a pair
            if card in window:
                # Update minimum length
                min_len = min(min_len, right - window[card] + 1)
                
                # Shrink window from left until duplicate removed
                while cards[left] != card:
                    del window[cards[left]]
                    left += 1
                
                # Remove the duplicate from left
                del window[cards[left]]
                left += 1
            
            # Add card to window
            window[card] = right
        
        return min_len if min_len != float('inf') else -1
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def minimumCardPickup(self, cards):
        return self.minimumCardPickupHashMap(cards)
