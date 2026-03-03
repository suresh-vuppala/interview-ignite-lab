class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class ReverseBetween {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public void reverseBetween(int m, int n) {
        if (head == null || m == n) return;
        Node dummy = new Node(0);
        dummy.next = head;
        Node pre = dummy;
        for (int i = 1; i < m; i++) pre = pre.next;
        Node start = pre.next, then = start.next;
        for (int i = 0; i < n - m; i++) {
            start.next = then.next;
            then.next = pre.next;
            pre.next = then;
            then = start.next;
        }
        head = dummy.next;
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
        ReverseBetween list = new ReverseBetween();
        for (int i = 1; i <= 5; i++) list.insert(i);
        System.out.print("Original: ");
        list.display();
        list.reverseBetween(2, 4);
        System.out.print("After reversing 2 to 4: ");
        list.display();
    }
}