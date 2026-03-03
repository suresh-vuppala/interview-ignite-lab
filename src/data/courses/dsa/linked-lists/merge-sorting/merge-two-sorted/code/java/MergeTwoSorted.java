class Node { int data; Node next; Node(int d) { data = d; } }
public class MergeTwoSorted {
    Node merge(Node l1, Node l2) { Node d=new Node(0),c=d; while(l1!=null&&l2!=null) { if(l1.data<l2.data) { c.next=l1; l1=l1.next; } else { c.next=l2; l2=l2.next; } c=c.next; } c.next=l1!=null?l1:l2; return d.next; }
    void display(Node h) { while(h!=null) { System.out.print(h.data+" "); h=h.next; } System.out.println(); }
    public static void main(String[] a) { MergeTwoSorted m=new MergeTwoSorted(); Node l1=new Node(1); l1.next=new Node(3); l1.next.next=new Node(5); Node l2=new Node(2); l2.next=new Node(4); m.display(m.merge(l1,l2)); }
}