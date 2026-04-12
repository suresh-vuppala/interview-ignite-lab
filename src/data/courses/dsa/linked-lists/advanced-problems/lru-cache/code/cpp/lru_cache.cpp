// ============================================================
// LRU Cache
// ============================================================
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node { int key, val; Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {} };

    int capacity;
    unordered_map<int, Node*> map;
    Node *head, *tail; // Sentinel nodes

    void addToHead(Node* node) {
        node->next = head->next; node->prev = head;
        head->next->prev = node; head->next = node;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveToHead(Node* node) { removeNode(node); addToHead(node); }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0); tail = new Node(0, 0);
        head->next = tail; tail->prev = head;
    }

    int get(int key) {
        if (!map.count(key)) return -1;
        Node* node = map[key];
        moveToHead(node); // Mark as recently used
        return node->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            Node* node = map[key];
            node->val = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            map[key] = node;
            addToHead(node);
            if ((int)map.size() > capacity) {
                Node* lru = tail->prev; // Least recently used
                removeNode(lru);
                map.erase(lru->key);
                delete lru;
            }
        }
    }
};
