#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { public: Node* rotate(Node* h, int k) { if(!h||k==0) return h; int len=1; Node* t=h; while(t->next) { t=t->next; len++; } t->next=h; k=k%len; for(int i=0;i<len-k;i++) t=t->next; h=t->next; t->next=nullptr; return h; }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL r; Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=new Node(4); r.display(r.rotate(h,2)); return 0; }