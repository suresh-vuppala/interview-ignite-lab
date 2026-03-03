class Node {
    int data;
    Node next;
    
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CreationTraversal {
    private Node head;
    
    // 1. Create linked list from array
    public void create(int[] values) {
        if (values.length == 0) return;
        
        head = new Node(values[0]);
        Node current = head;
        
        for (int i = 1; i < values.length; i++) {
            current.next = new Node(values[i]);
            current = current.next;
        }
    }
    
    // 2. Traverse and print all nodes
    public void traverse() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
    
    // 3. Count total nodes
    public int countNodes() {
        int count = 0;
        Node current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }
    
    public static void main(String[] args) {
        CreationTraversal list = new CreationTraversal();
        
        // Create linked list
        list.create(new int[]{1, 2, 3, 4, 5});
        
        // Traverse and print
        System.out.print("List: ");
        list.traverse();
        
        // Count nodes
        System.out.println("Total nodes: " + list.countNodes());
    }
}