import java.util.*;

class DequeExample {
    public static void main(String[] args) {
        Deque<Integer> deque = new LinkedList<>();
        
        deque.addLast(5);    // [5]
        deque.addFirst(3);   // [3, 5]
        deque.addLast(7);    // [3, 5, 7]
        
        System.out.println("Front: " + deque.removeFirst()); // 3
        System.out.println("Rear: " + deque.removeLast());   // 7
        System.out.println("Remaining: " + deque);            // [5]
    }
}
