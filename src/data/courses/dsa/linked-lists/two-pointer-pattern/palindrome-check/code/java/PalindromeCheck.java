class Node { int data; Node next; Node(int d) { data = d; } }
public class PalindromeCheck {
    Node head;
    void insert(int d) { if(head==null) head=new Node(d); else { Node c=head; while(c.next!=null) c=c.next; c.next=new Node(d); }}
    Node reverse(Node h) { Node p=null,c=h,n; while(c!=null) { n=c.next; c.next=p; p=c; c=n; } return p; }
    boolean isPalindrome() { Node s=head,f=head; while(f!=null&&f.next!=null) { s=s.next; f=f.next.next; } Node h2=reverse(s); Node p1=head,p2=h2; while(p2!=null) { if(p1.data!=p2.data) return false; p1=p1.next; p2=p2.next; } return true; }
    public static void main(String[] a) { PalindromeCheck l=new PalindromeCheck(); int[] v={1,2,3,2,1}; for(int i:v) l.insert(i); System.out.println("Is palindrome: "+l.isPalindrome()); }
}