struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Linear search — O(N) Time, O(1) Space
// ============================================================
class Solution1 {
public:
    bool search(ListNode* head, int target) {
        while(head){if(head->val==target)return true;head=head->next;}return false;
    }
    void update(ListNode* head, int oldVal, int newVal) {
        while(head){if(head->val==oldVal){head->val=newVal;return;}head=head->next;}
    }
};

// ============================================================
// Solution 2: Search with index tracking — O(N)
// ============================================================
class Solution2 {
public:
    int searchIndex(ListNode* head, int target) {
        int idx=0;while(head){if(head->val==target)return idx;head=head->next;idx++;}return -1;
    }
    bool updateAtIndex(ListNode* head, int idx, int newVal) {
        for(int i=0;i<idx&&head;i++)head=head->next;
        if(!head)return false;head->val=newVal;return true;
    }
};
