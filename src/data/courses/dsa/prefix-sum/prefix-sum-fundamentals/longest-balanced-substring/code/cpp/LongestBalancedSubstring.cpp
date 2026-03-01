#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestBalancedSubstring(string s) {
        // We track the difference between character counts
        // State: (count_a - count_b, count_a - count_c)
        unordered_map<long long, int> stateMap;
        stateMap[0] = -1; // Initial state (0, 0) at index -1
        
        int count_a = 0, count_b = 0, count_c = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Update counts
            if (s[i] == 'a') count_a++;
            else if (s[i] == 'b') count_b++;
            else count_c++;
            
            // Calculate state as a hash
            long long state = ((long long)(count_a - count_b) << 32) | (count_a - count_c);
            
            // If state was seen before, substring between is balanced
            if (stateMap.find(state) != stateMap.end()) {
                maxLength = max(maxLength, i - stateMap[state]);
            } else {
                // Store first occurrence of this state
                stateMap[state] = i;
            }
        }
        
        return maxLength;
    }
};
