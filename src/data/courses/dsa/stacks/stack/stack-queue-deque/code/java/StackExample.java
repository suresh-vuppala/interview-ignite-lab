import java.util.*;

class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        
        stack.push(5);
        stack.push(10);
        stack.push(15);
        
        System.out.println("Popped: " + stack.pop()); // 15
        System.out.println("Top: " + stack.peek());   // 10
        System.out.println("Size: " + stack.size());  // 2
        System.out.println("Empty: " + stack.isEmpty()); // false
    }
}
