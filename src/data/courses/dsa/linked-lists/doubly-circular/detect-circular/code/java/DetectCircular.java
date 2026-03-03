class Node { int data; Node next; Node(int d) { data = d; } }
public class DetectCircular {
    boolean isCircular(Node h) { if(h==null) return false; Node s=h,f=h; while(f!=null&&f.next!=null) { s=s.next; f=f.next.next; if(s==f) return s==h; } return false; }
    public static void main(String[] a) { DetectCircular dc=new DetectCircular(); Node h=new Node(1); h.next=new Node(2); h.next.next=new Node(3); h.next.next.next=h; System.out.println("Is circular: "+dc.isCircular(h)); }
}