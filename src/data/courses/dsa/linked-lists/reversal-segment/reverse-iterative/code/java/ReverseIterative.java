class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class ReverseIterative {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public void reverse() {
        Node prev = null, curr = head, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
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
        ReverseIterative list = new ReverseIterative();
        for (int i = 1; i <= 5; i++) list.insert(i);
        System.out.print("Original: ");
        list.display();
        list.reverse();
        System.out.print("Reversed: ");
        list.display();
    }
}