import java.util.*;

class Solution {
    // ==================== SOLUTION 1: USING TEMPORARY STACK ====================
    // Time: O(n²) | Space: O(n)
    public Stack<Integer> sortStackWithTemp(Stack<Integer> stack) {
        Stack<Integer> temp = new Stack<>();
        
        while (!stack.isEmpty()) {
            // Pop element from input stack
            int current = stack.pop();
            
            // Move elements from temp to input that are greater than current
            while (!temp.isEmpty() && temp.peek() > current) {
                stack.push(temp.pop());
            }
            
            // Push current to temp in sorted position
            temp.push(current);
        }
        
        // Transfer back to original stack
        while (!temp.isEmpty()) {
            stack.push(temp.pop());
        }
        
        return stack;
    }
    
    // ==================== SOLUTION 2: RECURSIVE APPROACH ====================
    // Time: O(n²) | Space: O(n)
    public Stack<Integer> sortStackRecursive(Stack<Integer> stack) {
        // Base case: empty stack
        if (stack.isEmpty()) {
            return stack;
        }
        
        // Pop top element
        int temp = stack.pop();
        
        // Recursively sort remaining stack
        sortStackRecursive(stack);
        
        // Insert popped element in sorted position
        insertSorted(stack, temp);
        
        return stack;
    }
    
    private void insertSorted(Stack<Integer> stack, int element) {
        // Base case: empty stack or element is largest
        if (stack.isEmpty() || stack.peek() <= element) {
            stack.push(element);
            return;
        }
        
        // Pop top and recursively insert element
        int temp = stack.pop();
        insertSorted(stack, element);
        
        // Push back the popped element
        stack.push(temp);
    }
    
    // ==================== SOLUTION 3: USING ARRAY AND SORTING ====================
    // Time: O(n log n) | Space: O(n)
    public Stack<Integer> sortStackWithArray(Stack<Integer> stack) {
        // Transfer to array
        List<Integer> list = new ArrayList<>();
        while (!stack.isEmpty()) {
            list.add(stack.pop());
        }
        
        // Sort array
        Collections.sort(list);
        
        // Push back in reverse order (largest first)
        for (int i = list.size() - 1; i >= 0; i--) {
            stack.push(list.get(i));
        }
        
        return stack;
    }
    
    // ==================== SOLUTION 4: USING PRIORITY QUEUE (MIN HEAP) ====================
    // Time: O(n log n) | Space: O(n)
    public Stack<Integer> sortStackWithHeap(Stack<Integer> stack) {
        // Transfer to min heap
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        while (!stack.isEmpty()) {
            heap.offer(stack.pop());
        }
        
        // Transfer to temp stack (smallest first)
        Stack<Integer> temp = new Stack<>();
        while (!heap.isEmpty()) {
            temp.push(heap.poll());
        }
        
        // Transfer back to original (largest on top)
        while (!temp.isEmpty()) {
            stack.push(temp.pop());
        }
        
        return stack;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    // Using Array + Sort for best time complexity
    public Stack<Integer> sortStack(Stack<Integer> stack) {
        return sortStackWithArray(stack);
    }
}
