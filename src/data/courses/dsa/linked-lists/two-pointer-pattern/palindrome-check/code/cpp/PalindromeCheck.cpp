#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { Node* head; Node* reverse(Node* h) { Node *p=nullptr,*c=h,*n; while(c) { n=c->next; c->next=p; p=c; c=n; } return p; }
public: LL():head(nullptr){} void insert(int d) { if(!head) head=new Node(d); else { Node* c=head; while(c->next) c=c->next; c->next=new Node(d); }}
bool isPalindrome() { Node *s=head,*f=head; while(f&&f->next) { s=s->next; f=f->next->next; } Node *h2=reverse(s),*p1=head,*p2=h2; while(p2) { if(p1->data!=p2->data) return false; p1=p1->next; p2=p2->next; } return true; }};
int main() { LL l; int v[]={1,2,3,2,1}; for(int i:v) l.insert(i); cout<<"Is palindrome: "<<l.isPalindrome()<<endl; return 0; }