#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { Node* head; public: LL():head(nullptr){} void insert(int d) { if(!head) head=new Node(d); else { Node* c=head; while(c->next) c=c->next; c->next=new Node(d); }}
void removeNth(int n) { Node* d=new Node(0); d->next=head; Node *f=d,*s=d; for(int i=0;i<=n;i++) f=f->next; while(f) { s=s->next; f=f->next; } s->next=s->next->next; head=d->next; }
void display() { Node* c=head; while(c) { cout<<c->data<<" "; c=c->next; } cout<<endl; }};
int main() { LL l; for(int i=1;i<=5;i++) l.insert(i); l.removeNth(2); l.display(); return 0; }