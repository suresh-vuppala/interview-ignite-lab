#include <vector>
#include <unordered_map>
using namespace std;

class SubarraysDivisibleByK {
public:
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(1)
    
    static int subarraysDivisibleBrute(vector<int>& nums, int k) {
        /*
         * Generate all subarrays and check if sum is divisible by k.
         * 
         * For each starting position i:
         *     For each ending position j:
         *         Calculate sum of subarray [i...j]
         *         If sum % k == 0, count it
         */
        int n = nums.size();
        int count = 0;
        
        // Try all starting positions
        for (int i = 0; i < n; i++) {
            // Try all ending positions
            for (int j = i; j < n; j++) {
                // Calculate sum of subarray [i...j]
                int subarraySum = 0;
                for (int idx = i; idx <= j; idx++) {
                    subarraySum += nums[idx];
                }
                
                // Check if divisible by k
                if (subarraySum % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(1)
    
    static int subarraysDivisibleOptimized(vector<int>& nums, int k) {
        /*
         * Use running sum to avoid recalculating sum for each subarray.
         * 
         * For each starting position i:
         *     Maintain currentSum as we extend to j
         *     Just add nums[j] instead of recalculating entire sum
         */
        int n = nums.size();
        int count = 0;
        
        // Try all starting positions
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            
            // Extend to all ending positions
            for (int j = i; j < n; j++) {
                currentSum += nums[j];  // Add current element
                
                // Check if divisible by k
                if (currentSum % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    // ==================== SOLUTION 3: PREFIX SUM WITH HASHMAP ====================
    // Time: O(N) | Space: O(K)
    
    static int subarraysDivisiblePrefixSum(vector<int>& nums, int k) {
        /*
         * Use prefix sum modulo k with HashMap.
         * 
         * Key insight: If prefixSum[j] % k == prefixSum[i] % k,
         * then subarray [i+1...j] has sum divisible by k.
         * 
         * Store frequency of each remainder in HashMap.
         * When we see a remainder again, all previous occurrences
         * form valid subarrays with current position.
         */
        // HashMap to store remainder -> frequency
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;  // Empty prefix has remainder 0
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            // Update prefix sum
            prefixSum += num;
            
            // Calculate remainder (handle negative remainders)
            int remainder = prefixSum % k;
            if (remainder < 0) {
                remainder += k;  // Ensure remainder is in [0, k-1]
            }
            
            // If this remainder seen before, all previous occurrences
            // form valid subarrays with current position
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
                remainderCount[remainder]++;
            } else {
                remainderCount[remainder] = 1;
            }
        }
        
        return count;
    }
    
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    
    static int subarraysDivByK(vector<int>& nums, int k) {
        /*
         * Count subarrays with sum divisible by k.
         * 
         * Time: O(N) - single pass through array
         * Space: O(K) - HashMap stores at most K remainders
         * 
         * @param nums Vector of integers
         * @param k Divisor
         * @return Number of subarrays with sum divisible by k
         * 
         * Example:
         *     subarraysDivByK([4, 5, 0, -2, -3, 1], 5) -> 7
         */
        return subarraysDivisiblePrefixSum(nums, k);
    }
};
