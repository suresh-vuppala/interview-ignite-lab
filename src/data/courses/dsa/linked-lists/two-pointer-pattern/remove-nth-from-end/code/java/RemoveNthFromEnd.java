class Node { int data; Node next; Node(int d) { data = d; } }
public class RemoveNthFromEnd {
    Node head;
    void insert(int d) { if(head==null) head=new Node(d); else { Node c=head; while(c.next!=null) c=c.next; c.next=new Node(d); }}
    void removeNth(int n) { Node d=new Node(0); d.next=head; Node f=d,s=d; for(int i=0;i<=n;i++) f=f.next; while(f!=null) { s=s.next; f=f.next; } s.next=s.next.next; head=d.next; }
    void display() { Node c=head; while(c!=null) { System.out.print(c.data+" "); c=c.next; } System.out.println(); }
    public static void main(String[] a) { RemoveNthFromEnd l=new RemoveNthFromEnd(); for(int i=1;i<=5;i++) l.insert(i); l.removeNth(2); l.display(); }
}