#include <iostream>
#include <unordered_map>
using namespace std;
struct Node { int key, val; Node *prev, *next; Node(int k, int v):key(k),val(v),prev(nullptr),next(nullptr){} };
class LRUCache { unordered_map<int,Node*> map; Node *head, *tail; int cap;
void remove(Node* n) { n->prev->next=n->next; n->next->prev=n->prev; }
void insert(Node* n) { n->next=head->next; n->prev=head; head->next->prev=n; head->next=n; }
public: LRUCache(int capacity):cap(capacity) { head=new Node(0,0); tail=new Node(0,0); head->next=tail; tail->prev=head; }
int get(int key) { if(map.find(key)==map.end()) return -1; Node* n=map[key]; remove(n); insert(n); return n->val; }
void put(int key, int val) { if(map.find(key)!=map.end()) remove(map[key]); Node* n=new Node(key,val); map[key]=n; insert(n); if(map.size()>cap) { Node* lru=tail->prev; remove(lru); map.erase(lru->key); }}};
int main() { LRUCache c(2); c.put(1,1); c.put(2,2); cout<<c.get(1)<<endl; c.put(3,3); cout<<c.get(2)<<endl; return 0; }