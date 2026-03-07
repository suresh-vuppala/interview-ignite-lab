#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n³) | Space: O(n)
    int minimumCardPickupBruteForce(vector<int>& cards) {
        int n = cards.size();
        int minLen = INT_MAX;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Check if subarray has duplicates
                unordered_set<int> seen;
                bool hasDuplicate = false;
                
                for (int k = i; k <= j; k++) {
                    if (seen.count(cards[k])) {
                        hasDuplicate = true;
                        break;
                    }
                    seen.insert(cards[k]);
                }
                
                if (hasDuplicate) {
                    minLen = min(minLen, j - i + 1);
                }
            }
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
    
    // ==================== SOLUTION 2: HASHMAP WITH LAST SEEN POSITION ====================
    // Time: O(n) | Space: O(n)
    int minimumCardPickupHashMap(vector<int>& cards) {
        unordered_map<int, int> lastSeen;
        int minLen = INT_MAX;
        
        for (int i = 0; i < cards.size(); i++) {
            int card = cards[i];
            
            // If card seen before, calculate distance
            if (lastSeen.count(card)) {
                int distance = i - lastSeen[card] + 1;
                minLen = min(minLen, distance);
            }
            
            // Update last seen position
            lastSeen[card] = i;
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
    
    // ==================== SOLUTION 3: SLIDING WINDOW ====================
    // Time: O(n) | Space: O(n)
    int minimumCardPickupSlidingWindow(vector<int>& cards) {
        unordered_map<int, int> window;
        int left = 0;
        int minLen = INT_MAX;
        
        for (int right = 0; right < cards.size(); right++) {
            int card = cards[right];
            
            // If card already in window, we found a pair
            if (window.count(card)) {
                // Update minimum length
                minLen = min(minLen, right - window[card] + 1);
                
                // Shrink window from left until duplicate removed
                while (cards[left] != card) {
                    window.erase(cards[left]);
                    left++;
                }
                
                // Remove the duplicate from left
                window.erase(cards[left]);
                left++;
            }
            
            // Add card to window
            window[card] = right;
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    int minimumCardPickup(vector<int>& cards) {
        return minimumCardPickupHashMap(cards);
    }
};
