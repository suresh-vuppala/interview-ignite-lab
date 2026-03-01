import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestWPI(int[] hours) {
        Map<Integer, Integer> firstOccurrence = new HashMap<>();
        firstOccurrence.put(0, -1);
        
        int prefixSum = 0;
        int maxLength = 0;
        
        for (int i = 0; i < hours.length; i++) {
            // Add 1 for tiring day (>8), -1 for non-tiring day
            prefixSum += (hours[i] > 8) ? 1 : -1;
            
            // If prefix sum > 0, interval from start is well-performing
            if (prefixSum > 0) {
                maxLength = i + 1;
            }
            // If (prefixSum - 1) was seen before, subarray between them has sum > 0
            else if (firstOccurrence.containsKey(prefixSum - 1)) {
                maxLength = Math.max(maxLength, i - firstOccurrence.get(prefixSum - 1));
            }
            
            // Store first occurrence of this prefix sum
            if (!firstOccurrence.containsKey(prefixSum)) {
                firstOccurrence.put(prefixSum, i);
            }
        }
        
        return maxLength;
    }
}
