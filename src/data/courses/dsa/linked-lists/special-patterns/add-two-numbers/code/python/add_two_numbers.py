# ============================================================
# Add Two Numbers
# ============================================================
class Solution:
    def addTwoNumbers(self,l1,l2):
        dummy=tail=ListNode(0);carry=0
        while l1 or l2 or carry:
            s=carry
            if l1:s+=l1.val;l1=l1.next
            if l2:s+=l2.val;l2=l2.next
            carry,digit=divmod(s,10)
            tail.next=ListNode(digit);tail=tail.next
        return dummy.next
