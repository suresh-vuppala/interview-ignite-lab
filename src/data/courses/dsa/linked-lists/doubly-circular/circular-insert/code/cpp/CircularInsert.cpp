#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class CLL { Node* head; public: CLL():head(nullptr){} void insertBegin(int d) { Node* n=new Node(d); if(!head) { head=n; n->next=head; return; } Node* c=head; while(c->next!=head) c=c->next; n->next=head; c->next=n; head=n; }
void insertEnd(int d) { Node* n=new Node(d); if(!head) { head=n; n->next=head; return; } Node* c=head; while(c->next!=head) c=c->next; c->next=n; n->next=head; }
void display() { if(!head) return; Node* c=head; do { cout<<c->data<<" "; c=c->next; } while(c!=head); cout<<endl; }};
int main() { CLL cl; cl.insertEnd(1); cl.insertEnd(2); cl.insertBegin(0); cl.display(); return 0; }