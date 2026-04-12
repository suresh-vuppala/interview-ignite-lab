class Solution{public ListNode insert(ListNode head,int val){
    ListNode node=new ListNode(val);
    if(head==null){node.next=node;return node;}
    ListNode curr=head;while(curr.next!=head)curr=curr.next;
    curr.next=node;node.next=head;return head;
}}