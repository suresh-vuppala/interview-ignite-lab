import java.util.*;

class DecodeString {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<String> stringStack = new Stack<>();
        String current = "";
        int k = 0;
        
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                k = k * 10 + (c - '0'); // Build multi-digit number
            } else if (c == '[') {
                countStack.push(k);
                stringStack.push(current);
                current = "";
                k = 0;
            } else if (c == ']') {
                int count = countStack.pop();
                String prev = stringStack.pop();
                current = prev + current.repeat(count);
            } else {
                current += c;
            }
        }
        
        return current;
    }
}
