import java.util.*;

class Solution {
    String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits.isEmpty()) return result;
        backtrack(digits, 0, new StringBuilder(), result);
        return result;
    }
    
    void backtrack(String digits, int i, StringBuilder curr, List<String> result) {
        if (i == digits.length()) {
            result.add(curr.toString());
            return;
        }
        String letters = map[digits.charAt(i) - '0'];
        for (char c : letters.toCharArray()) {
            curr.append(c);
            backtrack(digits, i+1, curr, result);
            curr.deleteCharAt(curr.length()-1);
        }
    }
}