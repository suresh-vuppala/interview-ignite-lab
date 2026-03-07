#include <vector>
#include <unordered_map>
using namespace std;

class CountOddEvenSubarrays {
public:
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(1)
    
    static int countOddEvenBrute(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int oddCount = 0;
                int evenCount = 0;
                for (int idx = i; idx <= j; idx++) {
                    if (nums[idx] % 2 == 1) {
                        oddCount++;
                    } else {
                        evenCount++;
                    }
                }
                
                if (oddCount == evenCount) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(1)
    
    static int countOddEvenOptimized(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int oddCount = 0;
            int evenCount = 0;
            
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 1) {
                    oddCount++;
                } else {
                    evenCount++;
                }
                
                if (oddCount == evenCount) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    // ==================== SOLUTION 3: TRANSFORM + PREFIX SUM ====================
    // Time: O(N) | Space: O(N)
    
    static int countOddEvenPrefixSum(vector<int>& nums) {
        /*
         * Transform: odd → +1, even → -1
         * Problem becomes: count subarrays with sum = 0
         */
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1;  // Empty prefix
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            // Transform: odd → +1, even → -1
            if (num % 2 == 1) {
                prefixSum += 1;
            } else {
                prefixSum -= 1;
            }
            
            // If this prefix sum seen before, all previous occurrences
            // form valid subarrays (sum = 0) with current position
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                count += prefixSumMap[prefixSum];
                prefixSumMap[prefixSum]++;
            } else {
                prefixSumMap[prefixSum] = 1;
            }
        }
        
        return count;
    }
    
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    
    static int countOddEvenSubarrays(vector<int>& nums) {
        /*
         * Count subarrays with equal odd and even counts.
         * 
         * Time: O(N) - single pass
         * Space: O(N) - HashMap
         * 
         * Example:
         *     countOddEvenSubarrays([2, 5, 4, 6, 3, 1]) -> 6
         */
        return countOddEvenPrefixSum(nums);
    }
};
