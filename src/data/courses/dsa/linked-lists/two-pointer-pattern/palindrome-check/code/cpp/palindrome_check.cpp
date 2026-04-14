struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Copy to array, check palindrome — O(N) Space
// ============================================================
#include <vector>
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;for(auto c=head;c;c=c->next)vals.push_back(c->val);
        int l=0,r=vals.size()-1;while(l<r){if(vals[l++]!=vals[r--])return false;}return true;
    }
};

// ============================================================
// Solution 2: Reverse second half in-place — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast&&fast->next){slow=slow->next;fast=fast->next->next;}
        // Reverse second half
        ListNode*prev=nullptr;while(slow){auto nxt=slow->next;slow->next=prev;prev=slow;slow=nxt;}
        // Compare
        while(prev){if(head->val!=prev->val)return false;head=head->next;prev=prev->next;}
        return true;
    }
};
