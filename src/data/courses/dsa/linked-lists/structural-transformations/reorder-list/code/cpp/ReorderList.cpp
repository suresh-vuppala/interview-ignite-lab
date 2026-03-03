#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { Node* reverse(Node* h) { Node *p=nullptr,*c=h,*n; while(c) { n=c->next; c->next=p; p=c; c=n; } return p; }
void merge(Node* l1, Node* l2) { while(l2) { Node *n1=l1->next,*n2=l2->next; l1->next=l2; l2->next=n1; l1=n1; l2=n2; }}
public: void reorder(Node* h) { if(!h||!h->next) return; Node *s=h,*f=h; while(f->next&&f->next->next) { s=s->next; f=f->next->next; } Node* h2=reverse(s->next); s->next=nullptr; merge(h,h2); }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL r; Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=new Node(4); r.reorder(h); r.display(h); return 0; }