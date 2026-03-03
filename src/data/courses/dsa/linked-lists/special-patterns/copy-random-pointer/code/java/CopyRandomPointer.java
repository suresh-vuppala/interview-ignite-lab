class Node { int data; Node next, random; Node(int d) { data = d; } }
public class CopyRandomPointer {
    Node copy(Node h) { if(h==null) return null; Node c=h; while(c!=null) { Node n=new Node(c.data); n.next=c.next; c.next=n; c=n.next; } c=h; while(c!=null) { if(c.random!=null) c.next.random=c.random.next; c=c.next.next; } Node oh=h,nh=h.next,nc=nh; while(oh!=null) { oh.next=oh.next.next; nc.next=nc.next!=null?nc.next.next:null; oh=oh.next; nc=nc.next; } return nh; }
    public static void main(String[] a) { CopyRandomPointer cr=new CopyRandomPointer(); Node h=new Node(1); h.next=new Node(2); h.random=h.next; System.out.println("Copied"); }
}