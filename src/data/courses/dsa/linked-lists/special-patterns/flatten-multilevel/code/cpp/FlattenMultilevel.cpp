#include <iostream>
using namespace std;
struct Node { int data; Node *next, *prev, *child; Node(int v):data(v),next(nullptr),prev(nullptr),child(nullptr){} };
class LL { public: Node* flatten(Node* h) { if(!h) return nullptr; Node* c=h; while(c) { if(c->child) { Node* n=c->next; Node* ch=flatten(c->child); c->next=ch; ch->prev=c; c->child=nullptr; while(c->next) c=c->next; if(n) { c->next=n; n->prev=c; }} c=c->next; } return h; }};
int main() { LL fm; Node* h=new Node(1); h->next=new Node(2); h->next->child=new Node(3); cout<<"Flattened"<<endl; return 0; }