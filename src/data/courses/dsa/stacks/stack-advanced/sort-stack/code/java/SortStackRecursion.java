import java.util.*;

class SortStackRecursion {
    public void sortStack(Stack<Integer> stack) {
        if (stack.isEmpty()) return;
        
        int top = stack.pop();
        sortStack(stack); // Sort remaining
        insertSorted(stack, top); // Insert in sorted position
    }
    
    private void insertSorted(Stack<Integer> stack, int element) {
        if (stack.isEmpty() || stack.peek() < element) {
            stack.push(element);
            return;
        }
        
        int top = stack.pop();
        insertSorted(stack, element);
        stack.push(top);
    }
}
