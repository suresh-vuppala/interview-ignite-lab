import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestBalancedSubstring(String s) {
        // We track the difference between character counts
        // State: (count_a - count_b, count_a - count_c)
        Map<String, Integer> stateMap = new HashMap<>();
        stateMap.put("0,0", -1); // Initial state (0, 0) at index -1
        
        int count_a = 0, count_b = 0, count_c = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Update counts
            if (s.charAt(i) == 'a') count_a++;
            else if (s.charAt(i) == 'b') count_b++;
            else count_c++;
            
            // Calculate state as a string representation
            String state = (count_a - count_b) + "," + (count_a - count_c);
            
            // If state was seen before, substring between is balanced
            if (stateMap.containsKey(state)) {
                maxLength = Math.max(maxLength, i - stateMap.get(state));
            } else {
                // Store first occurrence of this state
                stateMap.put(state, i);
            }
        }
        
        return maxLength;
    }
}
