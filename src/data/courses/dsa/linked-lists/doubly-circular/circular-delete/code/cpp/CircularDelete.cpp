#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class CLL { Node* head; public: CLL():head(nullptr){} void insert(int d) { Node* n=new Node(d); if(!head) { head=n; n->next=head; return; } Node* c=head; while(c->next!=head) c=c->next; c->next=n; n->next=head; }
void deleteBegin() { if(!head) return; if(head->next==head) { head=nullptr; return; } Node* c=head; while(c->next!=head) c=c->next; c->next=head->next; head=head->next; }
void display() { if(!head) return; Node* c=head; do { cout<<c->data<<" "; c=c->next; } while(c!=head); cout<<endl; }};
int main() { CLL cl; for(int i=1;i<=4;i++) cl.insert(i); cl.deleteBegin(); cl.display(); return 0; }