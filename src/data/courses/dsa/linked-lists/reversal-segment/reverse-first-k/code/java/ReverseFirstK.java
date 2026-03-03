class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class ReverseFirstK {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public void reverseFirstK(int k) {
        if (head == null || k <= 1) return;
        Node prev = null, curr = head, next;
        int count = 0;
        while (curr != null && count < k) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head.next = curr;
        head = prev;
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
        ReverseFirstK list = new ReverseFirstK();
        for (int i = 1; i <= 6; i++) list.insert(i);
        System.out.print("Original: ");
        list.display();
        list.reverseFirstK(3);
        System.out.print("After reversing first 3: ");
        list.display();
    }
}