// ============================================================
// Evaluate Nested Expression
// ============================================================

import java.util.*;

// ============================================================
// Solution: Stack-Based Evaluation
// Time: O(N) | Space: O(N)
// ============================================================
class Solution {
    // Helper class to store operator and operands
    static class Frame {
        String operator;
        List<Integer> operands;
        
        Frame(String operator) {
            this.operator = operator;
            this.operands = new ArrayList<>();
        }
    }
    
    public int evaluate(String s) {
        // Stack of frames (operator, operands)
        Stack<Frame> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            // Parse operator (letters)
            if (Character.isLetter(c)) {
                StringBuilder op = new StringBuilder();
                while (i < s.length() && Character.isLetter(s.charAt(i))) {
                    op.append(s.charAt(i++));
                }

                // Validate operator
                String operator = op.toString();
                if (!operator.equals("add") && !operator.equals("sub") && !operator.equals("mult")) {
                    return -1;  // Invalid operator
                }

                stack.push(new Frame(operator));
                i--;  // Adjust for loop increment
            }

            // Parse number (digits)
            else if (Character.isDigit(c)) {
                // Number without operator frame → invalid
                if (stack.isEmpty()) return -1;

                int num = 0;
                while (i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i++) - '0');
                }

                // Add operand to current frame
                stack.peek().operands.add(num);
                i--;  // Adjust for loop increment
            }

            // Closing bracket → compute result
            else if (c == ')') {
                // No frame to close → invalid
                if (stack.isEmpty()) return -1;

                Frame frame = stack.pop();

                // Validate: exactly 2 operands
                if (frame.operands.size() != 2) return -1;

                // Compute result based on operator
                int result;
                if (frame.operator.equals("add")) {
                    result = frame.operands.get(0) + frame.operands.get(1);
                } else if (frame.operator.equals("sub")) {
                    result = frame.operands.get(0) - frame.operands.get(1);
                } else {  // mult
                    result = frame.operands.get(0) * frame.operands.get(1);
                }

                // Pass result to parent or return if outermost
                if (!stack.isEmpty()) {
                    stack.peek().operands.add(result);
                } else {
                    // Check if we've consumed entire string
                    if (i == s.length() - 1) {
                        return result;
                    } else {
                        return -1;  // Extra characters after result
                    }
                }
            }

            // Ignore commas, spaces, opening parentheses
            else if (c == ',' || c == ' ' || c == '(') {
                continue;
            }

            // Invalid character
            else {
                return -1;
            }
        }

        // If stack not empty → unfinished expression
        return -1;
    }
}
