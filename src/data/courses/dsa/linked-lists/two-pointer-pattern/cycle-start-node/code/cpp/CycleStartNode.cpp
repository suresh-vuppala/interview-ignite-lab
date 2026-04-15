struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: HashSet — first revisited node — O(N) Time+Space
// ============================================================
#include <unordered_set>
class Solution1 {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        while(head){if(seen.count(head))return head;seen.insert(head);head=head->next;}
        return nullptr;
    }
};

// ============================================================
// Solution 2: Floyd's — meet point then reset one pointer — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;fast=fast->next->next;
            if(slow==fast){slow=head;while(slow!=fast){slow=slow->next;fast=fast->next;}return slow;}
        }
        return nullptr;
    }
};
