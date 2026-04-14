struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Rotate one position K times — O(N*K)
// ============================================================
class Solution1 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0)return head;
        int len=0;for(auto c=head;c;c=c->next)len++;k%=len;
        for(int i=0;i<k;i++){
            auto c=head;while(c->next->next)c=c->next;
            auto last=c->next;c->next=nullptr;last->next=head;head=last;
        }
        return head;
    }
};

// ============================================================
// Solution 2: Make circular, break at new position — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0)return head;
        int len=1;ListNode*tail=head;while(tail->next){len++;tail=tail->next;}
        k%=len;if(k==0)return head;
        tail->next=head; // Make circular
        int stepsToNewTail=len-k;
        ListNode*newTail=head;for(int i=1;i<stepsToNewTail;i++)newTail=newTail->next;
        head=newTail->next;newTail->next=nullptr;
        return head;
    }
};
