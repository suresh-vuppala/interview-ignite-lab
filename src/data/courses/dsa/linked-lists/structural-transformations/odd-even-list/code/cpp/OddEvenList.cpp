#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { public: Node* oddEven(Node* h) { if(!h) return nullptr; Node *o=h,*e=h->next,*eh=e; while(e&&e->next) { o->next=e->next; o=o->next; e->next=o->next; e=e->next; } o->next=eh; return h; }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL oe; Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=new Node(4); h->next->next->next->next=new Node(5); oe.display(oe.oddEven(h)); return 0; }