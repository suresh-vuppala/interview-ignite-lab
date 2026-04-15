struct ListNode { int val; ListNode* next; ListNode(int v):val(v),next(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Convert to integers, add, convert back — overflow risk!
// ============================================================
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long n1=0,n2=0,mul=1;
        while(l1){n1+=l1->val*mul;mul*=10;l1=l1->next;}
        mul=1;while(l2){n2+=l2->val*mul;mul*=10;l2=l2->next;}
        long sum=n1+n2;if(sum==0)return new ListNode(0);
        ListNode dummy(0);ListNode*tail=&dummy;
        while(sum>0){tail->next=new ListNode(sum%10);tail=tail->next;sum/=10;}
        return dummy.next; // OVERFLOW for large numbers!
    }
};

// ============================================================
// Solution 2: Digit-by-digit with carry — O(max(M,N)) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);ListNode*tail=&dummy;int carry=0;
        while(l1||l2||carry){
            int sum=carry;
            if(l1){sum+=l1->val;l1=l1->next;}
            if(l2){sum+=l2->val;l2=l2->next;}
            carry=sum/10;tail->next=new ListNode(sum%10);tail=tail->next;
        }
        return dummy.next;
    }
};
