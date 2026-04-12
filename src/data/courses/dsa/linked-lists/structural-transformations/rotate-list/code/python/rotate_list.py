class Solution:
    def rotateRight(self,head,k):
        if not head or not head.next or k==0:return head
        length,tail=1,head
        while tail.next:tail=tail.next;length+=1
        k%=length
        if k==0:return head
        tail.next=head
        new_tail=head
        for _ in range(length-k-1):new_tail=new_tail.next
        new_head=new_tail.next;new_tail.next=None
        return new_head