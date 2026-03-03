#include <iostream>
using namespace std;
struct Node { int data; Node *next, *prev; Node(int v):data(v),next(nullptr),prev(nullptr){} };
class DLL { Node* head; public: DLL():head(nullptr){} void insert(int d) { Node* n=new Node(d); if(!head) head=n; else { Node* c=head; while(c->next) c=c->next; c->next=n; n->prev=c; }}
void deleteBegin() { if(head) { head=head->next; if(head) head->prev=nullptr; }}
void deleteEnd() { if(!head||!head->next) { head=nullptr; return; } Node* c=head; while(c->next) c=c->next; c->prev->next=nullptr; }
void display() { Node* c=head; while(c) { cout<<c->data<<" "; c=c->next; } cout<<endl; }};
int main() { DLL dl; for(int i=1;i<=4;i++) dl.insert(i); dl.deleteBegin(); dl.deleteEnd(); dl.display(); return 0; }