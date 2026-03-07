#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(n)
    int totalFruitBruteForce(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            unordered_set<int> types;
            for (int j = i; j < n; j++) {
                types.insert(fruits[j]);
                
                // Check if valid (at most 2 types)
                if (types.size() <= 2) {
                    maxFruits = max(maxFruits, j - i + 1);
                } else {
                    break;  // More than 2 types
                }
            }
        }
        
        return maxFruits;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH HASHMAP ====================
    // Time: O(n) | Space: O(1)
    int totalFruitSlidingWindow(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            // Add fruit to window
            freq[fruits[right]]++;
            
            // Shrink window while more than 2 types
            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }
            
            // Update max fruits
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    // Time: O(n) | Space: O(1)
    int totalFruitOptimized(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            // Add fruit to window
            freq[fruits[right]]++;
            
            // If more than 2 types, slide window
            if (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }
        }
        
        // Window size is the answer
        return fruits.size() - left;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    int totalFruit(vector<int>& fruits) {
        return totalFruitSlidingWindow(fruits);
    }
};
