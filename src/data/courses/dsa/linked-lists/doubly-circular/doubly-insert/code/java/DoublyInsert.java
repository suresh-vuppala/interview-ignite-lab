class Node { int data; Node next, prev; Node(int d) { data = d; } }
public class DoublyInsert {
    Node head;
    void insertBegin(int d) { Node n=new Node(d); n.next=head; if(head!=null) head.prev=n; head=n; }
    void insertEnd(int d) { Node n=new Node(d); if(head==null) { head=n; return; } Node c=head; while(c.next!=null) c=c.next; c.next=n; n.prev=c; }
    void display() { Node c=head; while(c!=null) { System.out.print(c.data+" "); c=c.next; } System.out.println(); }
    public static void main(String[] a) { DoublyInsert dl=new DoublyInsert(); dl.insertEnd(1); dl.insertEnd(3); dl.insertBegin(0); dl.display(); }
}