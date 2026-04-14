#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
struct Node { int val; vector<Node*> neighbors; Node(int v):val(v){} };

// ============================================================
// Solution 1: BFS + HashMap — O(V+E) Time, O(V) Space
// ============================================================
class Solution1 {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloned;
        queue<Node*> q;
        cloned[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (Node* nb : cur->neighbors) {
                if (!cloned.count(nb)) {
                    cloned[nb] = new Node(nb->val);
                    q.push(nb);
                }
                cloned[cur]->neighbors.push_back(cloned[nb]);
            }
        }
        return cloned[node];
    }
};

// ============================================================
// Solution 2: DFS + HashMap — O(V+E) Time, O(V) Space
// ============================================================
class Solution2 {
    unordered_map<Node*, Node*> cloned;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (cloned.count(node)) return cloned[node];
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        for (Node* nb : node->neighbors)
            copy->neighbors.push_back(cloneGraph(nb));
        return copy;
    }
};
