// ============================================================
// Clone Graph
// ============================================================
#include <vector>
#include <unordered_map>
using namespace std;
class Node { public: int val; vector<Node*> neighbors;
    Node(int v):val(v){} Node(int v, vector<Node*> n):val(v),neighbors(n){} };

class Solution {
    unordered_map<Node*, Node*> cloneMap;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (cloneMap.count(node)) return cloneMap[node]; // Already cloned

        Node* clone = new Node(node->val);
        cloneMap[node] = clone;

        for (Node* neighbor : node->neighbors)
            clone->neighbors.push_back(cloneGraph(neighbor));

        return clone;
    }
};
