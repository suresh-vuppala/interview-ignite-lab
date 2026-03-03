class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class ReverseRecursive {
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
        head = reverseHelper(head);
    }
    
    private Node reverseHelper(Node node) {
        if (node == null || node.next == null) return node;
        Node newHead = reverseHelper(node.next);
        node.next.next = node;
        node.next = null;
        return newHead;
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
        ReverseRecursive list = new ReverseRecursive();
        for (int i = 1; i <= 5; i++) list.insert(i);
        System.out.print("Original: ");
        list.display();
        list.reverse();
        System.out.print("Reversed: ");
        list.display();
    }
}