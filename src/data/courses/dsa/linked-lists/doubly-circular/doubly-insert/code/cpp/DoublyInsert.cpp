#include <iostream>
using namespace std;
struct Node { int data; Node *next, *prev; Node(int v):data(v),next(nullptr),prev(nullptr){} };
class DLL { Node* head; public: DLL():head(nullptr){} void insertBegin(int d) { Node* n=new Node(d); n->next=head; if(head) head->prev=n; head=n; }
void insertEnd(int d) { Node* n=new Node(d); if(!head) { head=n; return; } Node* c=head; while(c->next) c=c->next; c->next=n; n->prev=c; }
void display() { Node* c=head; while(c) { cout<<c->data<<" "; c=c->next; } cout<<endl; }};
int main() { DLL dl; dl.insertEnd(1); dl.insertEnd(3); dl.insertBegin(0); dl.display(); return 0; }