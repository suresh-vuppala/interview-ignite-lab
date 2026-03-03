#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { public: bool isCircular(Node* h) { if(!h) return false; Node *s=h,*f=h; while(f&&f->next) { s=s->next; f=f->next->next; if(s==f) return s==h; } return false; }};
int main() { LL dc; Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(3); h->next->next->next=h; cout<<"Is circular: "<<dc.isCircular(h)<<endl; return 0; }