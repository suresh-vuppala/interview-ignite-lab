#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { public: Node* merge(Node* l1, Node* l2) { Node* d=new Node(0); Node* c=d; while(l1&&l2) { if(l1->data<l2->data) { c->next=l1; l1=l1->next; } else { c->next=l2; l2=l2->next; } c=c->next; } c->next=l1?l1:l2; return d->next; }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL m; Node* l1=new Node(1); l1->next=new Node(3); l1->next->next=new Node(5); Node* l2=new Node(2); l2->next=new Node(4); m.display(m.merge(l1,l2)); return 0; }