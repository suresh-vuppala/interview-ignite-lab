class Solution {
    public String reverseString(String s) {
        Stack<Character> stack = new Stack<>();
        
        // Push all characters
        for (char c : s.toCharArray()) {
            stack.push(c);
        }
        
        // Pop all characters
        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }
        
        return result.toString();
    }
}
