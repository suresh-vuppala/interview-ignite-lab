class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class DeletionVariations {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public void deleteFromBeginning() {
        if (head != null) head = head.next;
    }
    
    public void deleteFromEnd() {
        if (head == null || head.next == null) {
            head = null;
            return;
        }
        Node curr = head;
        while (curr.next.next != null) curr = curr.next;
        curr.next = null;
    }
    
    public void deleteAtPosition(int pos) {
        if (head == null) return;
        if (pos == 0) {
            head = head.next;
            return;
        }
        Node curr = head;
        for (int i = 0; i < pos - 1 && curr != null; i++) curr = curr.next;
        if (curr != null && curr.next != null) curr.next = curr.next.next;
    }
    
    public void deleteByValue(int val) {
        if (head == null) return;
        if (head.data == val) {
            head = head.next;
            return;
        }
        Node curr = head;
        while (curr.next != null && curr.next.data != val) curr = curr.next;
        if (curr.next != null) curr.next = curr.next.next;
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
        DeletionVariations list = new DeletionVariations();
        for (int i = 1; i <= 5; i++) list.insert(i);
        list.display();
        list.deleteFromBeginning();
        list.deleteFromEnd();
        list.deleteAtPosition(1);
        list.deleteByValue(3);
        list.display();
    }
}