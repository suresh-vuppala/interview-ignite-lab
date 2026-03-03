class Node { int data; Node next; Node(int d) { data = d; } }
public class IntersectionLists {
    Node getIntersection(Node h1, Node h2) { Node p1=h1,p2=h2; while(p1!=p2) { p1=p1==null?h2:p1.next; p2=p2==null?h1:p2.next; } return p1; }
    public static void main(String[] a) { IntersectionLists il=new IntersectionLists(); Node c=new Node(8); c.next=new Node(10); Node h1=new Node(3); h1.next=new Node(6); h1.next.next=c; Node h2=new Node(4); h2.next=c; Node i=il.getIntersection(h1,h2); System.out.println("Intersection: "+(i!=null?i.data:"None")); }
}