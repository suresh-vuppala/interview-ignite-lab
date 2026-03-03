class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class DetectCycle {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public void createCycle(int pos) {
        if (head == null) return;
        Node tail = head, cycleNode = null;
        int index = 0;
        while (tail.next != null) {
            if (index == pos) cycleNode = tail;
            tail = tail.next;
            index++;
        }
        if (cycleNode != null) tail.next = cycleNode;
    }
    
    public boolean hasCycle() {
        if (head == null) return false;
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        DetectCycle list = new DetectCycle();
        for (int i = 1; i <= 5; i++) list.insert(i);
        System.out.println("Has cycle: " + list.hasCycle());
        list.createCycle(2);
        System.out.println("Has cycle after creating: " + list.hasCycle());
    }
}