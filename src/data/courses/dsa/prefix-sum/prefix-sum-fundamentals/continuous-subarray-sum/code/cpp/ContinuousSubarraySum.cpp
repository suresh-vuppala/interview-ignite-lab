#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modMap;
        modMap[0] = -1; // Initialize with 0 modulo at index -1
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            
            // Check if we've seen this modulo before
            if (modMap.find(mod) != modMap.end()) {
                // Check if the subarray length is at least 2
                if (i - modMap[mod] >= 2) {
                    return true;
                }
            } else {
                // Store first occurrence of this modulo
                modMap[mod] = i;
            }
        }
        
        return false;
    }
};
