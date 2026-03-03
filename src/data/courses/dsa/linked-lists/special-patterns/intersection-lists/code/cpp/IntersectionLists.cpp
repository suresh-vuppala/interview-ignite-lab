#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
class LL { public: Node* getIntersection(Node* h1, Node* h2) { Node *p1=h1,*p2=h2; while(p1!=p2) { p1=p1?p1->next:h2; p2=p2?p2->next:h1; } return p1; }};
int main() { LL il; Node* c=new Node(8); c->next=new Node(10); Node* h1=new Node(3); h1->next=new Node(6); h1->next->next=c; Node* h2=new Node(4); h2->next=c; Node* i=il.getIntersection(h1,h2); cout<<"Intersection: "<<(i?to_string(i->data):"None")<<endl; return 0; }