class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class CycleStartNode {
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
    
    public Node detectCycleStart() {
        if (head == null) return null;
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }
        return null;
    }
    
    public static void main(String[] args) {
        CycleStartNode list = new CycleStartNode();
        for (int i = 1; i <= 5; i++) list.insert(i);
        list.createCycle(2);
        Node start = list.detectCycleStart();
        System.out.println("Cycle starts at: " + (start != null ? start.data : "No cycle"));
    }
}