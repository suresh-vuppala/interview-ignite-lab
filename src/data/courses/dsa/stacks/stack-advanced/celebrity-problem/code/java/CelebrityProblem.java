import java.util.*;

class CelebrityProblem {
    public int findCelebrity(int[][] M) {
        int n = M.length;
        Stack<Integer> stack = new Stack<>();
        
        // Push all people
        for (int i = 0; i < n; i++) {
            stack.push(i);
        }
        
        // Find candidate
        while (stack.size() > 1) {
            int a = stack.pop();
            int b = stack.pop();
            if (M[a][b] == 1) {
                stack.push(b); // a knows b, so a is not celebrity
            } else {
                stack.push(a); // a doesn't know b, so b is not celebrity
            }
        }
        
        int candidate = stack.pop();
        
        // Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[candidate][i] == 1 || M[i][candidate] == 0) {
                    return -1; // Not a celebrity
                }
            }
        }
        
        return candidate;
    }
}
