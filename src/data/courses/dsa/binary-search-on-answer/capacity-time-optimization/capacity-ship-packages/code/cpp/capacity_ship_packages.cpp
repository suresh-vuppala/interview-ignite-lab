// Time: O(N * log(sum - max))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Binary search range for ship capacity
        int low = *max_element(weights.begin(), weights.end());  // Minimum capacity needed
        int high = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity needed
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if we can ship all packages with capacity = mid
            if (canShip(weights, days, mid)) {
                result = mid;      // This works, try smaller capacity
                high = mid - 1;
            } else {
                low = mid + 1;     // Too small, need larger capacity
            }
        }
        
        return result;
    }
    
private:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;        // Start with first day
        int currentLoad = 0;       // Current load on ship
        
        for (int i = 0; i < weights.size(); i++) {
            // If a single package exceeds capacity, impossible
            if (weights[i] > capacity) return false;
            
            // Try to load current package on current day
            if (currentLoad + weights[i] <= capacity) {
                currentLoad += weights[i];  // Load package
            } else {
                // Ship is full, move to next day
                daysNeeded++;
                currentLoad = weights[i];   // Start new day with current package
                
                // If we need more days than available, capacity is too small
                if (daysNeeded > days) return false;
            }
        }
        
        // Successfully shipped all packages within days limit
        return true;
    }
};