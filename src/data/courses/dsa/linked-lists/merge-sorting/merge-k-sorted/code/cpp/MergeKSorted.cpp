#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node { int data; Node* next; Node(int v):data(v),next(nullptr){} };
struct Compare { bool operator()(Node* a, Node* b) { return a->data > b->data; } };
class LL { public: Node* mergeK(vector<Node*>& lists) { priority_queue<Node*,vector<Node*>,Compare> pq; for(auto n:lists) if(n) pq.push(n); Node* d=new Node(0); Node* c=d; while(!pq.empty()) { Node* n=pq.top(); pq.pop(); c->next=n; c=c->next; if(n->next) pq.push(n->next); } return d->next; }
void display(Node* h) { while(h) { cout<<h->data<<" "; h=h->next; } cout<<endl; }};
int main() { LL m; Node* l1=new Node(1); l1->next=new Node(4); Node* l2=new Node(2); l2->next=new Node(3); vector<Node*> lists={l1,l2}; m.display(m.mergeK(lists)); return 0; }