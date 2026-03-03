class Node { int data; Node next; Node(int d) { data = d; } }
public class FindMiddle {
    Node head;
    void insert(int d) { if(head==null) head=new Node(d); else { Node c=head; while(c.next!=null) c=c.next; c.next=new Node(d); }}
    Node findMiddle() { Node s=head,f=head; while(f!=null&&f.next!=null) { s=s.next; f=f.next.next; } return s; }
    public static void main(String[] a) { FindMiddle l=new FindMiddle(); for(int i=1;i<=5;i++) l.insert(i); System.out.println("Middle: "+l.findMiddle().data); }
}