#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { Node* head; public: LL():head(nullptr){} void insert(int d) { if(!head) head=new Node(d); else { Node* c=head; while(c->next) c=c->next; c->next=new Node(d); }}
Node* findNth(int n) { Node *f=head,*s=head; for(int i=0;i<n;i++) if(f) f=f->next; while(f) { s=s->next; f=f->next; } return s; }};
int main() { LL l; for(int i=1;i<=5;i++) l.insert(i); cout<<"2nd from end: "<<l.findNth(2)->data<<endl; return 0; }