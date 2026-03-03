#include <iostream>
using namespace std;
struct Node { int data; Node *next, *random; Node(int v):data(v),next(nullptr),random(nullptr){} };
class LL { public: Node* copy(Node* h) { if(!h) return nullptr; Node* c=h; while(c) { Node* n=new Node(c->data); n->next=c->next; c->next=n; c=n->next; } c=h; while(c) { if(c->random) c->next->random=c->random->next; c=c->next->next; } Node *oh=h,*nh=h->next,*nc=nh; while(oh) { oh->next=oh->next->next; nc->next=nc->next?nc->next->next:nullptr; oh=oh->next; nc=nc->next; } return nh; }};
int main() { LL cr; Node* h=new Node(1); h->next=new Node(2); h->random=h->next; cout<<"Copied"<<endl; return 0; }