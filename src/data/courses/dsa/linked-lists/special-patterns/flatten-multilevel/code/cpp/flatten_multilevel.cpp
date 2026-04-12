// ============================================================
// Flatten Multilevel Doubly Linked List
// ============================================================
class Node{public:int val;Node*prev,*next,*child;Node(int v):val(v),prev(nullptr),next(nullptr),child(nullptr){}};
class Solution{public:
    Node*flatten(Node*head){
        Node*curr=head;
        while(curr){
            if(curr->child){
                Node*child=curr->child;
                // Find tail of child list
                Node*tail=child;
                while(tail->next)tail=tail->next;
                // Connect tail to curr.next
                tail->next=curr->next;
                if(curr->next)curr->next->prev=tail;
                // Insert child after curr
                curr->next=child;child->prev=curr;
                curr->child=nullptr;
            }
            curr=curr->next;
        }
        return head;
    }};
