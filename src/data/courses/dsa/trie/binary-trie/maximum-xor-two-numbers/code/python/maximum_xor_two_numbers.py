class TrieNode:
    def __init__(self):
        self.children = [None, None]  # 0 and 1 for binary

class MaximumXorTwoNumbers:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num: int) -> None:
        node = self.root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def getMaxXor(self, num: int) -> int:
        node = self.root
        xor_val = 0
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            opposite = 1 - bit  # Choose opposite for max XOR
            if node.children[opposite]:
                xor_val |= (1 << i)  # Set bit in result
                node = node.children[opposite]
            else:
                node = node.children[bit]
        return xor_val
    
    def findMaximumXOR(self, nums: list[int]) -> int:
        # Insert all numbers into trie
        for num in nums:
            self.insert(num)
        
        # Find max XOR for each number
        max_xor = 0
        for num in nums:
            max_xor = max(max_xor, self.getMaxXor(num))
        return max_xor
