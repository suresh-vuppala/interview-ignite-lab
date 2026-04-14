struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: HashSet — store visited nodes — O(N) Time+Space
// ============================================================
#include <unordered_set>
class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        while(head){if(seen.count(head))return true;seen.insert(head);head=head->next;}
        return false;
    }
};

// ============================================================
// Solution 2: Floyd's slow/fast pointers — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){slow=slow->next;fast=fast->next->next;if(slow==fast)return true;}
        return false;
    }
};
