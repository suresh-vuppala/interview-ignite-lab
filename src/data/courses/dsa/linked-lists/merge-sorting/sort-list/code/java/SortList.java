class Node { int data; Node next; Node(int d) { data = d; } }
public class SortList {
    Node sortList(Node h) { if(h==null||h.next==null) return h; Node m=getMid(h),r=m.next; m.next=null; return merge(sortList(h),sortList(r)); }
    Node getMid(Node h) { Node s=h,f=h.next; while(f!=null&&f.next!=null) { s=s.next; f=f.next.next; } return s; }
    Node merge(Node l1, Node l2) { Node d=new Node(0),c=d; while(l1!=null&&l2!=null) { if(l1.data<l2.data) { c.next=l1; l1=l1.next; } else { c.next=l2; l2=l2.next; } c=c.next; } c.next=l1!=null?l1:l2; return d.next; }
    void display(Node h) { while(h!=null) { System.out.print(h.data+" "); h=h.next; } System.out.println(); }
    public static void main(String[] a) { SortList s=new SortList(); Node h=new Node(4); h.next=new Node(2); h.next.next=new Node(1); h.next.next.next=new Node(3); s.display(s.sortList(h)); }
}