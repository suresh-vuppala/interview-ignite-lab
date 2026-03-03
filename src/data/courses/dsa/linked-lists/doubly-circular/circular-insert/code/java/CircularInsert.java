class Node { int data; Node next; Node(int d) { data = d; } }
public class CircularInsert {
    Node head;
    void insertBegin(int d) { Node n=new Node(d); if(head==null) { head=n; n.next=head; return; } Node c=head; while(c.next!=head) c=c.next; n.next=head; c.next=n; head=n; }
    void insertEnd(int d) { Node n=new Node(d); if(head==null) { head=n; n.next=head; return; } Node c=head; while(c.next!=head) c=c.next; c.next=n; n.next=head; }
    void display() { if(head==null) return; Node c=head; do { System.out.print(c.data+" "); c=c.next; } while(c!=head); System.out.println(); }
    public static void main(String[] a) { CircularInsert cl=new CircularInsert(); cl.insertEnd(1); cl.insertEnd(2); cl.insertBegin(0); cl.display(); }
}