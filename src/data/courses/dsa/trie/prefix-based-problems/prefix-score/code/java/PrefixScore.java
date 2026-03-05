class PrefixScore {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        int prefixCount = 0; // Count of words passing through
    }
    
    private TrieNode root = new TrieNode();
    
    public int sumPrefixScores(String[] words) {
        // Build trie with prefix counts
        for (String word : words) {
            insert(word);
        }
        
        // Calculate sum of scores
        int totalScore = 0;
        for (String word : words) {
            totalScore += getScore(word);
        }
        return totalScore;
    }
    
    private void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
            node.prefixCount++; // Increment count
        }
    }
    
    private int getScore(String word) {
        TrieNode node = root;
        int score = 0;
        
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            node = node.children[idx];
            score += node.prefixCount; // Add prefix count
        }
        return score;
    }
}
