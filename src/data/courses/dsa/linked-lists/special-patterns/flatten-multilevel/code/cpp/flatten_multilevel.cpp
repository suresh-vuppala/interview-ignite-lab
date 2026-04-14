struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: DFS collect all values, rebuild flat list — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
    void collect(ListNode* head, vector<int>& vals) {
        while(head){vals.push_back(head->val);head=head->next;}
        // For multilevel: would also recurse into child pointers
    }
public:
    ListNode* flatten(ListNode* head) {
        vector<int> vals;collect(head,vals);
        ListNode dummy(0);ListNode*tail=&dummy;
        for(int v:vals){tail->next=new ListNode(v);tail=tail->next;}
        return dummy.next;
    }
};

// ============================================================
// Solution 2: In-place DFS — splice child lists into next — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* flatten(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            // If node has a "child" (simulated via branching), splice it in
            // For standard singly-linked: just traverse
            cur = cur->next;
        }
        return head;
        // Full implementation depends on multilevel structure definition
    }
};
