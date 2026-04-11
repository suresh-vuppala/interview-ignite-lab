// ============================================================
// Decode String
// ============================================================

import java.util.*;

class Solution {
    public String decodeString(String s) {
        Deque<String> strStack = new ArrayDeque<>();
        Deque<Integer> numStack = new ArrayDeque<>();
        StringBuilder cur = new StringBuilder();
        int num = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                strStack.push(cur.toString());
                numStack.push(num);
                cur = new StringBuilder();
                num = 0;
            } else if (c == ']') {
                String prev = strStack.pop();
                int count = numStack.pop();
                StringBuilder temp = new StringBuilder(prev);
                for (int i = 0; i < count; i++) temp.append(cur);
                cur = temp;
            } else {
                cur.append(c);
            }
        }

        return cur.toString();
    }
}
