import java.util.*;

class Solution {
    public List<List<Integer>> generateSubarrays(int[] arr) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            for (int j = i; j < arr.length; j++) {
                List<Integer> sub = new ArrayList<>();
                for (int k = i; k <= j; k++)
                    sub.add(arr[k]);
                result.add(sub);
            }
        }
        return result;
    }
}