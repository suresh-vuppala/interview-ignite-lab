import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> modMap = new HashMap<>();
        modMap.put(0, -1); // Initialize with 0 modulo at index -1
        
        int prefixSum = 0;
        
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            
            // Check if we've seen this modulo before
            if (modMap.containsKey(mod)) {
                // Check if the subarray length is at least 2
                if (i - modMap.get(mod) >= 2) {
                    return true;
                }
            } else {
                // Store first occurrence of this modulo
                modMap.put(mod, i);
            }
        }
        
        return false;
    }
}
