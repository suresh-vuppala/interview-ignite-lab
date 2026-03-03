class Node { int val; Node next, random; Node(int v) { val=v; }}
public class CloneRandomPointer {
    public Node clone(Node head) { if(head==null) return null; Node c=head; while(c!=null) { Node n=new Node(c.val); n.next=c.next; c.next=n; c=n.next; } c=head; while(c!=null) { if(c.random!=null) c.next.random=c.random.next; c=c.next.next; } Node oh=head,nh=head.next,nc=nh; while(oh!=null) { oh.next=oh.next.next; nc.next=nc.next!=null?nc.next.next:null; oh=oh.next; nc=nc.next; } return nh; }
    public static void main(String[] a) { CloneRandomPointer cr=new CloneRandomPointer(); Node h=new Node(1); h.next=new Node(2); h.next.next=new Node(3); h.random=h.next.next; h.next.random=h; Node copy=cr.clone(h); System.out.println("Cloned: "+copy.val); }
}