class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; this.next = null; }
}

public class InsertionVariations {
    private Node head;
    
    // Insert at beginning - O(1)
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
    
    // Insert at end - O(n)
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }
    
    // Insert at position (0-indexed) - O(n)
    public void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }
        Node newNode = new Node(data);
        Node current = head;
        for (int i = 0; i < position - 1 && current != null; i++) {
            current = current.next;
        }
        if (current == null) {
            System.out.println("Invalid position");
            return;
        }
        newNode.next = current.next;
        current.next = newNode;
    }
    
    // Insert after a specific node value - O(n)
    public void insertAfterNode(int targetData, int newData) {
        Node current = head;
        while (current != null && current.data != targetData) {
            current = current.next;
        }
        if (current == null) {
            System.out.println("Node not found");
            return;
        }
        Node newNode = new Node(newData);
        newNode.next = current.next;
        current.next = newNode;
    }
    
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
    
    public static void main(String[] args) {
        InsertionVariations list = new InsertionVariations();
        
        list.insertAtEnd(3);
        list.insertAtEnd(5);
        list.insertAtBeginning(1);
        list.insertAtPosition(2, 1);
        list.insertAfterNode(3, 4);
        
        list.display(); // 1 -> 2 -> 3 -> 4 -> 5 -> null
    }
}