class Node { int data; Node next; Node(int d) { data = d; } }
public class RotateList {
    Node rotate(Node h, int k) { if(h==null||k==0) return h; int len=1; Node t=h; while(t.next!=null) { t=t.next; len++; } t.next=h; k=k%len; for(int i=0;i<len-k;i++) t=t.next; h=t.next; t.next=null; return h; }
    void display(Node h) { while(h!=null) { System.out.print(h.data+" "); h=h.next; } System.out.println(); }
    public static void main(String[] a) { RotateList r=new RotateList(); Node h=new Node(1); h.next=new Node(2); h.next.next=new Node(3); h.next.next.next=new Node(4); r.display(r.rotate(h,2)); }
}