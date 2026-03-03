class Node { int data; Node next, prev; Node(int d) { data = d; } }
public class DoublyDelete {
    Node head;
    void insert(int d) { Node n=new Node(d); if(head==null) head=n; else { Node c=head; while(c.next!=null) c=c.next; c.next=n; n.prev=c; }}
    void deleteBegin() { if(head!=null) { head=head.next; if(head!=null) head.prev=null; }}
    void deleteEnd() { if(head==null||head.next==null) { head=null; return; } Node c=head; while(c.next!=null) c=c.next; c.prev.next=null; }
    void display() { Node c=head; while(c!=null) { System.out.print(c.data+" "); c=c.next; } System.out.println(); }
    public static void main(String[] a) { DoublyDelete dl=new DoublyDelete(); for(int i=1;i<=4;i++) dl.insert(i); dl.deleteBegin(); dl.deleteEnd(); dl.display(); }
}