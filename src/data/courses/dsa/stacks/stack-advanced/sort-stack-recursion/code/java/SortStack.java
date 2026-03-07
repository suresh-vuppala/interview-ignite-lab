import java.util.*;

// Time: O(N²), Space: O(N)
class SortStack {
    public void sortStackBruteForce(Stack<Integer> stack) {
        List<Integer> temp = new ArrayList<>();
        while (!stack.isEmpty()) temp.add(stack.pop());
        Collections.sort(temp);
        Collections.reverse(temp);
        for (int val : temp) stack.push(val);
    }

    // ============================================================

    // Time: O(N²), Space: O(N)
    public void sortStackTempStack(Stack<Integer> stack) {
        Stack<Integer> temp = new Stack<>();
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            while (!temp.isEmpty() && temp.peek() > curr) {
                stack.push(temp.pop());
            }
            temp.push(curr);
        }
        while (!temp.isEmpty()) stack.push(temp.pop());
    }

    // ============================================================

    // Time: O(N²), Space: O(N)
    public void sortStackRecursionHelper(Stack<Integer> stack) {
        if (stack.isEmpty()) return;
        int temp = stack.pop();
        sortStackRecursionHelper(stack);
        insertSorted(stack, temp);
    }

    private void insertSorted(Stack<Integer> stack, int element) {
        if (stack.isEmpty() || stack.peek() <= element) {
            stack.push(element);
            return;
        }
        int temp = stack.pop();
        insertSorted(stack, element);
        stack.push(temp);
    }

    // ============================================================

    // Time: O(N²), Space: O(N)
    public void sortStackRecursionInline(Stack<Integer> stack) {
        if (stack.isEmpty()) return;
        int temp = stack.pop();
        sortStackRecursionInline(stack);
        insert(stack, temp);
    }

    private void insert(Stack<Integer> stack, int val) {
        if (stack.isEmpty() || stack.peek() <= val) {
            stack.push(val);
        } else {
            int top = stack.pop();
            insert(stack, val);
            stack.push(top);
        }
    }

    // ============================================================

    // Time: O(N log N), Space: O(N)
    public Stack<Integer> sortStackMergeSort(Stack<Integer> stack) {
        if (stack.size() <= 1) return stack;
        
        int mid = stack.size() / 2;
        Stack<Integer> left = new Stack<>();
        Stack<Integer> right = new Stack<>();
        
        for (int i = 0; i < mid; i++) left.push(stack.get(i));
        for (int i = mid; i < stack.size(); i++) right.push(stack.get(i));
        
        left = sortStackMergeSort(left);
        right = sortStackMergeSort(right);
        
        return merge(left, right);
    }

    private Stack<Integer> merge(Stack<Integer> left, Stack<Integer> right) {
        Stack<Integer> result = new Stack<>();
        while (!left.isEmpty() && !right.isEmpty()) {
            if (left.peek() <= right.peek()) {
                result.push(left.pop());
            } else {
                result.push(right.pop());
            }
        }
        while (!left.isEmpty()) result.push(left.pop());
        while (!right.isEmpty()) result.push(right.pop());
        return result;
    }
}
