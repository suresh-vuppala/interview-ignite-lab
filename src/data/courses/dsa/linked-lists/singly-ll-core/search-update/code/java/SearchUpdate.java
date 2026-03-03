class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class SearchUpdate {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public boolean searchByValue(int val) {
        Node curr = head;
        while (curr != null) {
            if (curr.data == val) return true;
            curr = curr.next;
        }
        return false;
    }
    
    public int searchByPosition(int pos) {
        Node curr = head;
        for (int i = 0; i < pos && curr != null; i++) curr = curr.next;
        return curr != null ? curr.data : -1;
    }
    
    public void updateByPosition(int pos, int newVal) {
        Node curr = head;
        for (int i = 0; i < pos && curr != null; i++) curr = curr.next;
        if (curr != null) curr.data = newVal;
    }
    
    public void updateByValue(int oldVal, int newVal) {
        Node curr = head;
        while (curr != null) {
            if (curr.data == oldVal) {
                curr.data = newVal;
                return;
            }
            curr = curr.next;
        }
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
        SearchUpdate list = new SearchUpdate();
        for (int i = 1; i <= 5; i++) list.insert(i);
        System.out.println("Search 3: " + list.searchByValue(3));
        System.out.println("Value at pos 2: " + list.searchByPosition(2));
        list.updateByPosition(1, 10);
        list.updateByValue(5, 50);
        list.display();
    }
}