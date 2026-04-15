// Time: O(N log N + N * log(max - min))
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int k) {
        // Sort stalls to place cows in order
        sort(stalls.begin(), stalls.end());
        
        // Binary search range for minimum distance
        int low = 1;                              // Minimum possible distance
        int high = stalls.back() - stalls[0];     // Maximum possible distance
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if we can place k cows with minimum distance = mid
            if (canPlace(stalls, k, mid)) {
                result = mid;      // This works, try larger distance
                low = mid + 1;
            } else {
                high = mid - 1;    // Too large, need smaller distance
            }
        }
        
        return result;
    }
    
private:
    bool canPlace(vector<int>& stalls, int k, int minDist) {
        int cowsPlaced = 1;            // Place first cow at first stall
        int lastPosition = stalls[0];  // Position of last placed cow
        
        // Try to place remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            // If current stall is at least minDist away from last cow
            if (stalls[i] - lastPosition >= minDist) {
                cowsPlaced++;              // Place cow here
                lastPosition = stalls[i];  // Update last position
                
                // If we've placed all k cows, we're done
                if (cowsPlaced == k) return true;
            }
        }
        
        // Check if we placed all k cows
        return cowsPlaced >= k;
    }
};