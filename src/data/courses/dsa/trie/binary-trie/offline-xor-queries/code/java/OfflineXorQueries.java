import java.util.*;

class OfflineXorQueries {
    class TrieNode {
        TrieNode[] children = new TrieNode[2];
    }
    
    public int[] maximizeXor(int[] nums, int[][] queries) {
        Arrays.sort(nums);
        int[][] indexedQueries = new int[queries.length][3];
        for (int i = 0; i < queries.length; i++) {
            indexedQueries[i] = new int[]{queries[i][0], queries[i][1], i};
        }
        Arrays.sort(indexedQueries, (a, b) -> a[1] - b[1]);
        
        int[] result = new int[queries.length];
        TrieNode root = new TrieNode();
        int idx = 0;
        
        for (int[] query : indexedQueries) {
            int x = query[0], m = query[1], qIdx = query[2];
            while (idx < nums.length && nums[idx] <= m) {
                insert(root, nums[idx++]);
            }
            result[qIdx] = idx == 0 ? -1 : getMaxXor(root, x);
        }
        return result;
    }
    
    private void insert(TrieNode root, int num) {
        TrieNode node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node.children[bit] == null) node.children[bit] = new TrieNode();
            node = node.children[bit];
        }
    }
    
    private int getMaxXor(TrieNode root, int num) {
        TrieNode node = root;
        int xor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node.children[opposite] != null) {
                xor |= (1 << i);
                node = node.children[opposite];
            } else {
                node = node.children[bit];
            }
        }
        return xor;
    }
}
