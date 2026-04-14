struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Find previous node, delete — O(N)
// ============================================================
class Solution1 {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head)return nullptr;
        if(head->next==head&&head->val==val){delete head;return nullptr;}
        ListNode*cur=head;
        while(cur->next!=head&&cur->next->val!=val)cur=cur->next;
        if(cur->next->val==val){
            ListNode*del=cur->next;
            if(del==head)head=del->next;
            cur->next=del->next;delete del;
        }
        return head;
    }
};

// ============================================================
// Solution 2: Find and delete with prev tracking — O(N)
// ============================================================
class Solution2 {
public:
    ListNode* deleteHead(ListNode* head) {
        if(!head)return nullptr;
        if(head->next==head){delete head;return nullptr;}
        ListNode*tail=head;while(tail->next!=head)tail=tail->next;
        ListNode*newHead=head->next;tail->next=newHead;delete head;return newHead;
    }
};
