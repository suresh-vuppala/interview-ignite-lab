class Node { int data; Node next, prev, child; Node(int d) { data = d; } }
public class FlattenMultilevel {
    Node flatten(Node h) { if(h==null) return null; Node c=h; while(c!=null) { if(c.child!=null) { Node n=c.next; Node ch=flatten(c.child); c.next=ch; ch.prev=c; c.child=null; while(c.next!=null) c=c.next; if(n!=null) { c.next=n; n.prev=c; }} c=c.next; } return h; }
    public static void main(String[] a) { FlattenMultilevel fm=new FlattenMultilevel(); Node h=new Node(1); h.next=new Node(2); h.next.child=new Node(3); System.out.println("Flattened"); }
}