#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { Node* head; public: LL():head(nullptr){} void insert(int d) { if(!head) head=new Node(d); else { Node* c=head; while(c->next) c=c->next; c->next=new Node(d); }}
Node* findMiddle() { Node *s=head,*f=head; while(f&&f->next) { s=s->next; f=f->next->next; } return s; }};
int main() { LL l; for(int i=1;i<=5;i++) l.insert(i); cout<<"Middle: "<<l.findMiddle()->data<<endl; return 0; }