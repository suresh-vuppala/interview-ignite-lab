#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> firstOccurrence;
        firstOccurrence[0] = -1;
        
        int prefixSum = 0;
        int maxLength = 0;
        
        for (int i = 0; i < hours.size(); i++) {
            // Add 1 for tiring day (>8), -1 for non-tiring day
            prefixSum += (hours[i] > 8) ? 1 : -1;
            
            // If prefix sum > 0, interval from start is well-performing
            if (prefixSum > 0) {
                maxLength = i + 1;
            }
            // If (prefixSum - 1) was seen before, subarray between them has sum > 0
            else if (firstOccurrence.find(prefixSum - 1) != firstOccurrence.end()) {
                maxLength = max(maxLength, i - firstOccurrence[prefixSum - 1]);
            }
            
            // Store first occurrence of this prefix sum
            if (firstOccurrence.find(prefixSum) == firstOccurrence.end()) {
                firstOccurrence[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};
