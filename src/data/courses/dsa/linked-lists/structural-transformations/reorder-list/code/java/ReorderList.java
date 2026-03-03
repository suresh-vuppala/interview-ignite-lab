class Node { int data; Node next; Node(int d) { data = d; } }
public class ReorderList {
    void reorder(Node h) { if(h==null||h.next==null) return; Node s=h,f=h; while(f.next!=null&&f.next.next!=null) { s=s.next; f=f.next.next; } Node h2=reverse(s.next); s.next=null; merge(h,h2); }
    Node reverse(Node h) { Node p=null,c=h,n; while(c!=null) { n=c.next; c.next=p; p=c; c=n; } return p; }
    void merge(Node l1, Node l2) { while(l2!=null) { Node n1=l1.next,n2=l2.next; l1.next=l2; l2.next=n1; l1=n1; l2=n2; }}
    void display(Node h) { while(h!=null) { System.out.print(h.data+" "); h=h.next; } System.out.println(); }
    public static void main(String[] a) { ReorderList r=new ReorderList(); Node h=new Node(1); h.next=new Node(2); h.next.next=new Node(3); h.next.next.next=new Node(4); r.reorder(h); r.display(h); }
}