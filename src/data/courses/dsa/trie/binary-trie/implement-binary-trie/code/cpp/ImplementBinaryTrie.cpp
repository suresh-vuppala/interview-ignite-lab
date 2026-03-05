class ImplementBinaryTrie {
    struct TrieNode {
        TrieNode* children[2] = {}; // 0 and 1 for binary
    };
    
    TrieNode* root = new TrieNode();
    
public:
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) { // Process from MSB to LSB
            int bit = (num >> i) & 1; // Extract bit at position i
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // Current bit
            int oppositeBit = 1 - bit; // Opposite bit for max XOR
            
            if (node->children[oppositeBit]) {
                maxXor |= (1 << i); // Set bit in result
                node = node->children[oppositeBit];
            } else {
                node = node->children[bit]; // Take same bit
            }
        }
        return maxXor;
    }
};
