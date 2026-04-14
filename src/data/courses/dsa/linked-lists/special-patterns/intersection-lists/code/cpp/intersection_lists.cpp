struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: HashSet — store all nodes of list1, check list2 — O(M+N) Space
// ============================================================
#include <unordered_set>
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> seen;
        while(headA){seen.insert(headA);headA=headA->next;}
        while(headB){if(seen.count(headB))return headB;headB=headB->next;}
        return nullptr;
    }
};

// ============================================================
// Solution 2: Two pointers — switch lists at end — O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode*a=headA,*b=headB;
        while(a!=b){a=a?a->next:headB;b=b?b->next:headA;}
        return a; // Meet at intersection or both null
    }
};
