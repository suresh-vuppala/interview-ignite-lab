// ============================================================
// Infix to Postfix
// ============================================================

import java.util.*;

class Solution {
    public String infixToPostfix(String s) {
        Map<Character,Integer> prec = Map.of('+',1,'-',1,'*',2,'/',2);
        Deque<Character> ops = new ArrayDeque<>();
        StringBuilder result = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) { result.append(c); }
            else if (c == '(') { ops.push(c); }
            else if (c == ')') {
                while (ops.peek() != '(') result.append(ops.pop());
                ops.pop();
            } else {
                while (!ops.isEmpty() && ops.peek() != '(' &&
                       prec.getOrDefault(ops.peek(),0) >= prec.getOrDefault(c,0))
                    result.append(ops.pop());
                ops.push(c);
            }
        }
        while (!ops.isEmpty()) result.append(ops.pop());
        return result.toString();
    }
}
