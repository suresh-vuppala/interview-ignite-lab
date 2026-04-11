// ============================================================
// Remove K Digits
// ============================================================

class Solution {
    public String removeKdigits(String num, int k) {
        StringBuilder stack = new StringBuilder();
        for (char d : num.toCharArray()) {
            while (k > 0 && stack.length() > 0 && stack.charAt(stack.length()-1) > d) {
                stack.deleteCharAt(stack.length()-1); k--;
            }
            stack.append(d);
        }
        while (k > 0) { stack.deleteCharAt(stack.length()-1); k--; }
        // Strip leading zeros
        int start = 0;
        while (start < stack.length() && stack.charAt(start) == '0') start++;
        String result = stack.substring(start);
        return result.isEmpty() ? "0" : result;
    }
}
