#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { public: Node* partition(Node* h, int x) { Node *d1=new Node(0),*d2=new Node(0),*p1=d1,*p2=d2; while(h) { if(h->data<x) { p1->next=h; p1=p1->next; } else { p2->next=h; p2=p2->next; } h=h->next; } p2->next=nullptr; p1->next=d2->next; return d1->next; }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL p; Node* h=new Node(1); h->next=new Node(4); h->next->next=new Node(3); h->next->next->next=new Node(2); p.display(p.partition(h,3)); return 0; }