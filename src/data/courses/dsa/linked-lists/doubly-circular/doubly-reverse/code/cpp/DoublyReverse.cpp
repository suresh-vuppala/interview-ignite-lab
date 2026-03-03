#include <iostream>
using namespace std;
struct Node { int data; Node *next, *prev; Node(int v):data(v),next(nullptr),prev(nullptr){} };
class DLL { Node* head; public: DLL():head(nullptr){} void insert(int d) { Node* n=new Node(d); if(!head) head=n; else { Node* c=head; while(c->next) c=c->next; c->next=n; n->prev=c; }}
void reverse() { Node *c=head,*t=nullptr; while(c) { t=c->prev; c->prev=c->next; c->next=t; c=c->prev; } if(t) head=t->prev; }
void display() { Node* c=head; while(c) { cout<<c->data<<" "; c=c->next; } cout<<endl; }};
int main() { DLL dl; for(int i=1;i<=4;i++) dl.insert(i); dl.reverse(); dl.display(); return 0; }