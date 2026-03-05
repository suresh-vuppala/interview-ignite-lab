class RadixNode:
    def __init__(self):
        self.children = {}
        self.is_end = False
        self.edge_label = ""

class CompressedTrie:
    def __init__(self):
        self.root = RadixNode()
    
    def insert(self, word):
        node = self.root
        i = 0
        while i < len(word):
            char = word[i]
            if char not in node.children:
                new_node = RadixNode()
                new_node.edge_label = word[i:]
                new_node.is_end = True
                node.children[char] = new_node
                return
            
            child = node.children[char]
            label = child.edge_label
            j = 0
            while j < len(label) and i < len(word) and label[j] == word[i]:
                i += 1
                j += 1
            
            if j < len(label):
                # Split edge
                split_node = RadixNode()
                split_node.edge_label = label[:j]
                split_node.children[label[j]] = child
                child.edge_label = label[j:]
                node.children[char] = split_node
                
                if i < len(word):
                    new_node = RadixNode()
                    new_node.edge_label = word[i:]
                    new_node.is_end = True
                    split_node.children[word[i]] = new_node
                else:
                    split_node.is_end = True
                return
            node = child
        node.is_end = True
    
    def search(self, word):
        node = self.root
        i = 0
        while i < len(word):
            char = word[i]
            if char not in node.children:
                return False
            child = node.children[char]
            label = child.edge_label
            for c in label:
                if i >= len(word) or word[i] != c:
                    return False
                i += 1
            node = child
        return node.is_end
