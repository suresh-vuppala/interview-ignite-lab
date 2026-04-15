struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: HashSet visited — O(N) Space
// ============================================================
#include <unordered_set>
class Solution1 {
public:
    bool isCircular(ListNode* head) {
        if(!head)return false;
        unordered_set<ListNode*> seen;
        ListNode*cur=head;
        while(cur){if(seen.count(cur))return cur==head;seen.insert(cur);cur=cur->next;}
        return false;
    }
};

// ============================================================
// Solution 2: Simple traversal check — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    bool isCircular(ListNode* head) {
        if(!head)return false;
        ListNode*cur=head->next;
        while(cur&&cur!=head)cur=cur->next;
        return cur==head; // Reached back to head = circular
    }
};
