class Node { int data; Node next; Node(int d) { data = d; } }
public class AddTwoNumbers {
    Node add(Node l1, Node l2) { Node d=new Node(0),c=d; int carry=0; while(l1!=null||l2!=null||carry>0) { int sum=carry; if(l1!=null) { sum+=l1.data; l1=l1.next; } if(l2!=null) { sum+=l2.data; l2=l2.next; } c.next=new Node(sum%10); carry=sum/10; c=c.next; } return d.next; }
    void display(Node h) { while(h!=null) { System.out.print(h.data); h=h.next; } System.out.println(); }
    public static void main(String[] a) { AddTwoNumbers at=new AddTwoNumbers(); Node l1=new Node(2); l1.next=new Node(4); l1.next.next=new Node(3); Node l2=new Node(5); l2.next=new Node(6); l2.next.next=new Node(4); at.display(at.add(l1,l2)); }
}