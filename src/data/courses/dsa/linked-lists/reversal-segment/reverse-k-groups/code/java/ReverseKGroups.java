class Node {
    int data;
    Node next;
    Node(int data) { this.data = data; }
}

public class ReverseKGroups {
    private Node head;
    
    public void insert(int data) {
        if (head == null) head = new Node(data);
        else {
            Node curr = head;
            while (curr.next != null) curr = curr.next;
            curr.next = new Node(data);
        }
    }
    
    public void reverseKGroups(int k) {
        head = reverseKHelper(head, k);
    }
    
    private Node reverseKHelper(Node head, int k) {
        Node curr = head;
        int count = 0;
        while (curr != null && count < k) {
            curr = curr.next;
            count++;
        }
        if (count == k) {
            curr = reverseKHelper(curr, k);
            while (count-- > 0) {
                Node tmp = head.next;
                head.next = curr;
                curr = head;
                head = tmp;
            }
            head = curr;
        }
        return head;
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
        ReverseKGroups list = new ReverseKGroups();
        for (int i = 1; i <= 8; i++) list.insert(i);
        System.out.print("Original: ");
        list.display();
        list.reverseKGroups(3);
        System.out.print("After reversing in groups of 3: ");
        list.display();
    }
}