import java.util.*;

class Solution {
    public List<List<Integer>> generateSubsequences(int[] arr) {
        List<List<Integer>> result = new ArrayList<>();
        generate(arr, 0, new ArrayList<>(), result);
        return result;
    }
    
    void generate(int[] arr, int i, List<Integer> curr, List<List<Integer>> result) {
        if (i == arr.length) {
            result.add(new ArrayList<>(curr));
            return;
        }
        generate(arr, i+1, curr, result);
        curr.add(arr[i]);
        generate(arr, i+1, curr, result);
        curr.remove(curr.size()-1);
    }
}