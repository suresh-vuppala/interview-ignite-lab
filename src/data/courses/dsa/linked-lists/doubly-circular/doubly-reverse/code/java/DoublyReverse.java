class Node { int data; Node next, prev; Node(int d) { data = d; } }
public class DoublyReverse {
    Node head;
    void insert(int d) { Node n=new Node(d); if(head==null) head=n; else { Node c=head; while(c.next!=null) c=c.next; c.next=n; n.prev=c; }}
    void reverse() { Node c=head,t=null; while(c!=null) { t=c.prev; c.prev=c.next; c.next=t; c=c.prev; } if(t!=null) head=t.prev; }
    void display() { Node c=head; while(c!=null) { System.out.print(c.data+" "); c=c.next; } System.out.println(); }
    public static void main(String[] a) { DoublyReverse dl=new DoublyReverse(); for(int i=1;i<=4;i++) dl.insert(i); dl.reverse(); dl.display(); }
}