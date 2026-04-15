struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Two separate lists, concatenate — O(N) Space for new nodes
// ============================================================
class Solution1 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode oddD(0),evenD(0);ListNode*ot=&oddD,*et=&evenD;
        int idx=1;for(auto c=head;c;c=c->next,idx++){
            if(idx%2==1){ot->next=new ListNode(c->val);ot=ot->next;}
            else{et->next=new ListNode(c->val);et=et->next;}}
        ot->next=evenD.next;return oddD.next;
    }
};

// ============================================================
// Solution 2: In-place pointer rewiring — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return nullptr;
        ListNode*odd=head,*even=head->next,*evenHead=even;
        while(even&&even->next){odd->next=even->next;odd=odd->next;even->next=odd->next;even=even->next;}
        odd->next=evenHead;return head;
    }
};
