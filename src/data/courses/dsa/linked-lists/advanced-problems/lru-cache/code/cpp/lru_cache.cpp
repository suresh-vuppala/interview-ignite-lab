#include <unordered_map>
using namespace std;
struct DLLNode { int key, val; DLLNode *prev, *next; DLLNode(int k,int v):key(k),val(v),prev(nullptr),next(nullptr){} };

// ============================================================
// Solution 1: Array + linear search for LRU — O(N) per operation
// ============================================================
#include <vector>
class Solution1 {
    vector<pair<int,int>> cache; // {key, val}
    int cap;
public:
    Solution1(int capacity):cap(capacity){}
    int get(int key) {
        for(int i=0;i<(int)cache.size();i++)
            if(cache[i].first==key){
                auto p=cache[i];cache.erase(cache.begin()+i);cache.push_back(p);return p.second;
            }
        return -1;
    }
    void put(int key, int value) {
        for(int i=0;i<(int)cache.size();i++)
            if(cache[i].first==key){cache.erase(cache.begin()+i);break;}
        cache.push_back({key,value});
        if((int)cache.size()>cap)cache.erase(cache.begin());
    }
};

// ============================================================
// Solution 2: HashMap + Doubly Linked List — O(1) per operation
// ============================================================
class Solution2 {
    int cap; unordered_map<int,DLLNode*> map;
    DLLNode *head=new DLLNode(0,0), *tail=new DLLNode(0,0);
    void remove(DLLNode*n){n->prev->next=n->next;n->next->prev=n->prev;}
    void addToFront(DLLNode*n){n->next=head->next;n->prev=head;head->next->prev=n;head->next=n;}
public:
    Solution2(int capacity):cap(capacity){head->next=tail;tail->prev=head;}
    int get(int key){
        if(!map.count(key))return -1;
        auto n=map[key];remove(n);addToFront(n);return n->val;
    }
    void put(int key,int value){
        if(map.count(key)){auto n=map[key];remove(n);n->val=value;addToFront(n);return;}
        auto n=new DLLNode(key,value);map[key]=n;addToFront(n);
        if((int)map.size()>cap){auto lru=tail->prev;remove(lru);map.erase(lru->key);delete lru;}
    }
};
