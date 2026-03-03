#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class MergeKSortedLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        for (auto node : lists) {
            if (node) minHeap.push(node);
        }
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return dummy.next;
    }
};