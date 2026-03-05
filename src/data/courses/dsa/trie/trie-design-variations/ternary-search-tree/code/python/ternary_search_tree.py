class TSTNode:
    def __init__(self, char):
        self.char = char
        self.left = None
        self.middle = None
        self.right = None
        self.is_end = False

class TernarySearchTree:
    def __init__(self):
        self.root = None
    
    def insert(self, word):
        self.root = self._insert(self.root, word, 0)
    
    def _insert(self, node, word, index):
        char = word[index]
        if node is None:
            node = TSTNode(char)
        
        if char < node.char:
            node.left = self._insert(node.left, word, index)
        elif char > node.char:
            node.right = self._insert(node.right, word, index)
        else:
            if index < len(word) - 1:
                node.middle = self._insert(node.middle, word, index + 1)
            else:
                node.is_end = True
        return node
    
    def search(self, word):
        node = self._search(self.root, word, 0)
        return node is not None and node.is_end
    
    def _search(self, node, word, index):
        if node is None:
            return None
        
        char = word[index]
        if char < node.char:
            return self._search(node.left, word, index)
        elif char > node.char:
            return self._search(node.right, word, index)
        else:
            if index == len(word) - 1:
                return node
            return self._search(node.middle, word, index + 1)
