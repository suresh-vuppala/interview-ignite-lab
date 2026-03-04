class RemoveKDigits {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        for (char c : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > c) {
                stack.pop(); // Remove larger digit
                k--;
            }
            stack.push(c);
        }
        while (k-- > 0) stack.pop(); // Remove remaining k digits
        
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) sb.append(stack.pop());
        sb.reverse();
        
        while (sb.length() > 1 && sb.charAt(0) == '0') sb.deleteCharAt(0); // Remove leading zeros
        return sb.length() == 0 ? "0" : sb.toString();
    }
}