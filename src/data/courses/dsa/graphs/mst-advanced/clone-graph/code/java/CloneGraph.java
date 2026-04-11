class Solution {
    Map<Node, Node> visited = new HashMap<>();
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        if (visited.containsKey(node)) return visited.get(node);
        Node clone = new Node(node.val);
        visited.put(node, clone);
        for (Node n : node.neighbors) clone.neighbors.add(cloneGraph(n));
        return clone;
    }
}