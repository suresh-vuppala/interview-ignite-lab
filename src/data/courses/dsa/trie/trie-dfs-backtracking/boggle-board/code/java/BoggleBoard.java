import java.util.*;

class BoggleBoard {
    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        String word = null; // Store word at end
    }
    
    private int[][] dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // 8 directions
    
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) insert(root, word);
        
        List<String> result = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
    
    private void insert(TrieNode root, String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) node.children[idx] = new TrieNode();
            node = node.children[idx];
        }
        node.word = word; // Store complete word
    }
    
    private void dfs(char[][] board, int i, int j, TrieNode node, List<String> result) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length) return;
        
        char c = board[i][j];
        if (c == '#' || node.children[c - 'a'] == null) return; // Visited or no path
        
        node = node.children[c - 'a'];
        if (node.word != null) {
            result.add(node.word); // Found word
            node.word = null; // Avoid duplicates
        }
        
        board[i][j] = '#'; // Mark visited
        for (int[] dir : dirs) { // Explore 8 directions
            dfs(board, i + dir[0], j + dir[1], node, result);
        }
        board[i][j] = c; // Backtrack
    }
}
