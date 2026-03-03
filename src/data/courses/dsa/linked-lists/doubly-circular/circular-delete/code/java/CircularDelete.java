class Node { int data; Node next; Node(int d) { data = d; } }
public class CircularDelete {
    Node head;
    void insert(int d) { Node n=new Node(d); if(head==null) { head=n; n.next=head; return; } Node c=head; while(c.next!=head) c=c.next; c.next=n; n.next=head; }
    void deleteBegin() { if(head==null) return; if(head.next==head) { head=null; return; } Node c=head; while(c.next!=head) c=c.next; c.next=head.next; head=head.next; }
    void display() { if(head==null) return; Node c=head; do { System.out.print(c.data+" "); c=c.next; } while(c!=head); System.out.println(); }
    public static void main(String[] a) { CircularDelete cl=new CircularDelete(); for(int i=1;i<=4;i++) cl.insert(i); cl.deleteBegin(); cl.display(); }
}