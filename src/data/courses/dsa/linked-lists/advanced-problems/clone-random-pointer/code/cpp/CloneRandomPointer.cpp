#include <iostream>
using namespace std;
struct Node { int val; Node *next, *random; Node(int v):val(v),next(nullptr),random(nullptr){} };
class Solution { public: Node* clone(Node* head) { if(!head) return nullptr; Node* c=head; while(c) { Node* n=new Node(c->val); n->next=c->next; c->next=n; c=n->next; } c=head; while(c) { if(c->random) c->next->random=c->random->next; c=c->next->next; } Node *oh=head,*nh=head->next,*nc=nh; while(oh) { oh->next=oh->next->next; nc->next=nc->next?nc->next->next:nullptr; oh=oh->next; nc=nc->next; } return nh; }};
int main() { Solution s; Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->random=h->next->next; h->next->random=h; Node* copy=s.clone(h); cout<<"Cloned: "<<copy->val<<endl; return 0; }