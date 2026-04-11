// ============================================================
// Evaluate Reverse Polish Notation
// ============================================================

import java.util.*;

class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Long> stack = new ArrayDeque<>();
        for (String t : tokens) {
            if ("+-*/".contains(t) && t.length() == 1) {
                long b = stack.pop(), a = stack.pop();
                switch (t) {
                    case "+": stack.push(a + b); break;
                    case "-": stack.push(a - b); break;
                    case "*": stack.push(a * b); break;
                    case "/": stack.push(a / b); break;
                }
            } else {
                stack.push(Long.parseLong(t));
            }
        }
        return stack.pop().intValue();
    }
}
