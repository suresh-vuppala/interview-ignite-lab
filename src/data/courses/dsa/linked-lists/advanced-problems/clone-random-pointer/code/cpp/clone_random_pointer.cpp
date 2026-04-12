// ============================================================
// Clone Random Pointer (Hash Map approach)
// ============================================================
#include <unordered_map>
using namespace std;
class Node{public:int val;Node*next,*random;Node(int v):val(v),next(nullptr),random(nullptr){}};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> map;

        // Pass 1: Create all clones
        Node* curr = head;
        while (curr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: Set pointers
        curr = head;
        while (curr) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};
