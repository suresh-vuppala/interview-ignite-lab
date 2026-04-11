class Solution {
public:
    // O(V+E) — BFS/DFS with hash map to track cloned nodes
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];
        
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (Node* neighbor : node->neighbors)
            clone->neighbors.push_back(cloneGraph(neighbor));
        return clone;
    }
};