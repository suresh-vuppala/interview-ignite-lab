class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class FindMiddleNode {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public int findMiddleTwoPass() {
        int count = 0;
        Node curr = head;
        while (curr != null) {
            count++;
            curr = curr.next;
        }
        curr = head;
        for (int i = 0; i < count / 2; i++) curr = curr.next;
        return curr.data;
    }
    
    public int findMiddleSlowFast() {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow.data;
    }
    
    public void display() {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " -> ");
            curr = curr.next;
        }
        System.out.println("null");
    }
    
    public static void main(String[] args) {
        FindMiddleNode list = new FindMiddleNode();
        for (int i = 1; i <= 5; i++) list.insert(i);
        list.display();
        System.out.println("Middle (Two-Pass): " + list.findMiddleTwoPass());
        System.out.println("Middle (Slow-Fast): " + list.findMiddleSlowFast());
    }
}