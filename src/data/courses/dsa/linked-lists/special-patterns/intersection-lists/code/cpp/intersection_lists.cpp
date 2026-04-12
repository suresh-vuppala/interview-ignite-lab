// ============================================================
// Intersection of Two Linked Lists
// ============================================================
struct ListNode{int val;ListNode*next;ListNode(int v):val(v),next(nullptr){}};
class Solution{public:
    ListNode*getIntersectionNode(ListNode*headA,ListNode*headB){
        ListNode*a=headA,*b=headB;
        while(a!=b){
            a=a?a->next:headB; // Redirect to other list's head
            b=b?b->next:headA;
        }
        return a; // Intersection or null
    }};
