// ============================================================
// Score of Parentheses
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Stack with Score Tracking
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
    public int scoreOfParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        int total = 0;     // final result (outermost level)
        int value;
        
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(0);
                // start a new frame → begin collecting inner score
            } else {
                // compute value of current "( ... )"
                int inside = stack.pop();
                
                if (inside == 0) {
                    // Case: "()"
                    value = 1;
                } else {
                    // Case: "(A)"
                    value = 2 * inside;
                }
                
                if (stack.isEmpty()) {
                    // no parent → contributes directly to final result
                    // Example: "()()" → both pairs go directly to total
                    total += value;
                } else {
                    // child block contributes its value to its parent
                    // Example: "(())" → inner "()" contributes 1 to outer
                    int parentScore = stack.pop();
                    parentScore = parentScore + value;
                    stack.push(parentScore);
                }
            }
        }
        
        return total;
    }
}

// ============================================================
// Solution 2: Stack with Depth Tracking
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public int scoreOfParentheses(String s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                depth++;
            } else {
                depth--;
                // Check if this forms "()" - previous char was '('
                if (s.charAt(i - 1) == '(') {
                    // Add 2^depth to score (depth before decrement)
                    score += (1 << depth);  // Equivalent to Math.pow(2, depth)
                }
            }
        }
        
        return score;
    }
}

// ============================================================
// Solution 3: Divide and Conquer (Recursive)
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution3 {
    private int helper(String s, int start, int end) {
        // Base case: empty string
        if (start >= end) return 0;
        
        // Check if entire string is wrapped: (A)
        int balance = 0;
        boolean isWrapped = true;
        
        for (int i = start; i < end; i++) {
            balance += (s.charAt(i) == '(') ? 1 : -1;
            // If balance becomes 0 before the end, not fully wrapped
            if (balance == 0 && i < end - 1) {
                isWrapped = false;
                break;
            }
        }
        
        // If wrapped like (A), return 2 * score(A)
        if (isWrapped) {
            return 2 * helper(s, start + 1, end - 1);
        }
        
        // Otherwise, split into balanced parts and sum
        int totalScore = 0;
        balance = 0;
        int partStart = start;
        
        for (int i = start; i < end; i++) {
            balance += (s.charAt(i) == '(') ? 1 : -1;
            
            // Found a balanced part
            if (balance == 0) {
                totalScore += helper(s, partStart, i + 1);
                partStart = i + 1;
            }
        }
        
        return totalScore;
    }
    
    public int scoreOfParentheses(String s) {
        // Base case for "()"
        if (s.equals("()")) return 1;
        return helper(s, 0, s.length());
    }
}
