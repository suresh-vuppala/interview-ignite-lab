// ============================================================
// Copy List with Random Pointer
// ============================================================
class Node{public:int val;Node*next,*random;Node(int v):val(v),next(nullptr),random(nullptr){}};
class Solution{public:
    Node*copyRandomList(Node*head){
        if(!head)return nullptr;
        // Pass 1: Interleave clones
        Node*curr=head;
        while(curr){Node*clone=new Node(curr->val);clone->next=curr->next;curr->next=clone;curr=clone->next;}
        // Pass 2: Set random pointers
        curr=head;
        while(curr){if(curr->random)curr->next->random=curr->random->next;curr=curr->next->next;}
        // Pass 3: Separate lists
        Node*cloneHead=head->next;curr=head;
        while(curr){Node*clone=curr->next;curr->next=clone->next;curr=curr->next;if(curr)clone->next=curr->next;}
        return cloneHead;
    }};
