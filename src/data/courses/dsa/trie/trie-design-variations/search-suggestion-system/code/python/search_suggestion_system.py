# ============================================================
# Solution 1: Brute Force
# ============================================================

class Solution1:
    # Brute force: hash set / nested loops / direct comparison
    # See Solution 2 below for optimal Trie-based approach
    pass


# ============================================================
# Solution 2: Optimal (Trie-based)
# ============================================================
class TrieNode:
    def __init__(self):
        self.children = {}
        self.suggestions = []

class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()
        root = TrieNode()
        
        # Build trie with top 3 suggestions at each node
        for product in products:
            node = root
            for char in product:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
                if len(node.suggestions) < 3:
                    node.suggestions.append(product)
        
        # Query for each prefix
        result = []
        node = root
        for char in searchWord:
            if node and char in node.children:
                node = node.children[char]
                result.append(node.suggestions)
            else:
                node = None
                result.append([])
        return result
