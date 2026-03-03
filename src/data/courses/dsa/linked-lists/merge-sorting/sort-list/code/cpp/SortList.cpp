#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { Node* getMid(Node* h) { Node *s=h,*f=h->next; while(f&&f->next) { s=s->next; f=f->next->next; } return s; }
Node* merge(Node* l1, Node* l2) { Node* d=new Node(0); Node* c=d; while(l1&&l2) { if(l1->data<l2->data) { c->next=l1; l1=l1->next; } else { c->next=l2; l2=l2->next; } c=c->next; } c->next=l1?l1:l2; return d->next; }
public: Node* sortList(Node* h) { if(!h||!h->next) return h; Node* m=getMid(h); Node* r=m->next; m->next=nullptr; return merge(sortList(h),sortList(r)); }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL s; Node* h=new Node(4); h->next=new Node(2); h->next->next=new Node(1); h->next->next->next=new Node(3); s.display(s.sortList(h)); return 0; }