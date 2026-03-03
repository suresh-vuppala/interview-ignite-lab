class Node { int data; Node next; Node(int d) { data = d; } }
public class FindNthFromEnd {
    Node head;
    void insert(int d) { if(head==null) head=new Node(d); else { Node c=head; while(c.next!=null) c=c.next; c.next=new Node(d); }}
    Node findNth(int n) { Node f=head,s=head; for(int i=0;i<n;i++) if(f!=null) f=f.next; while(f!=null) { s=s.next; f=f.next; } return s; }
    public static void main(String[] a) { FindNthFromEnd l=new FindNthFromEnd(); for(int i=1;i<=5;i++) l.insert(i); System.out.println("2nd from end: "+l.findNth(2).data); }
}