// Time: O(N * log(sum - max))
// Space: O(1)

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int paintersPartition(vector<int>& boards, int m) {
        int n = boards.size();
        
        // Edge case: More painters than boards
        if (m > n) return -1;
        
        // Binary search range
        int low = *max_element(boards.begin(), boards.end());  // Minimum possible answer
        int high = accumulate(boards.begin(), boards.end(), 0); // Maximum possible answer
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if we can paint with max time = mid
            if (canPaint(boards, n, m, mid)) {
                result = mid;      // This works, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // Too small, need larger limit
            }
        }
        
        return result;
    }
    
private:
    bool canPaint(vector<int>& boards, int n, int m, int maxTime) {
        int painterCount = 1;      // Start with first painter
        int currentTime = 0;       // Time assigned to current painter
        
        for (int i = 0; i < n; i++) {
            // If a single board takes more time than our limit, impossible
            if (boards[i] > maxTime) return false;
            
            // Try to assign current board to current painter
            if (currentTime + boards[i] <= maxTime) {
                currentTime += boards[i];  // Assign to current painter
            } else {
                // Current painter's limit reached, assign to next painter
                painterCount++;
                currentTime = boards[i];   // Start new painter with current board
                
                // If we need more painters than available, this limit is too small
                if (painterCount > m) return false;
            }
        }
        
        // Successfully painted all boards within the limit
        return true;
    }
};
