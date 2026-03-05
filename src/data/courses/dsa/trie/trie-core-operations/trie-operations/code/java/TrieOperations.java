class TrieOperations {
    class TrieNode {
        TrieNode[] children = new TrieNode[26]; // 26 lowercase letters
        boolean isEnd = false; // Marks end of word
    }
    
    private TrieNode root = new TrieNode();
    
    public void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a'; // Convert char to index (0-25)
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode(); // Create new node
            }
            node = node.children[idx]; // Move to child
        }
        node.isEnd = true; // Mark end of word
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) return false; // Path doesn't exist
            node = node.children[idx];
        }
        return node.isEnd; // Check if it's a complete word
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) return false; // Path doesn't exist
            node = node.children[idx];
        }
        return true; // Prefix exists (don't check isEnd)
    }
}
