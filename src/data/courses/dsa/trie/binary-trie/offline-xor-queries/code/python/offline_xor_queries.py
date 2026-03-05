class TrieNode:
    def __init__(self):
        self.children = [None, None]

class OfflineXorQueries:
    def insert(self, root: TrieNode, num: int) -> None:
        node = root
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            if not node.children[bit]:
                node.children[bit] = TrieNode()
            node = node.children[bit]
    
    def getMaxXor(self, root: TrieNode, num: int) -> int:
        node = root
        xor_val = 0
        for i in range(31, -1, -1):
            bit = (num >> i) & 1
            opposite = 1 - bit
            if node.children[opposite]:
                xor_val |= (1 << i)
                node = node.children[opposite]
            else:
                node = node.children[bit]
        return xor_val
    
    def maximizeXor(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        nums.sort()
        indexed_queries = [(q[0], q[1], i) for i, q in enumerate(queries)]
        indexed_queries.sort(key=lambda x: x[1])
        
        result = [0] * len(queries)
        root = TrieNode()
        idx = 0
        
        for x, m, q_idx in indexed_queries:
            while idx < len(nums) and nums[idx] <= m:
                self.insert(root, nums[idx])
                idx += 1
            result[q_idx] = -1 if idx == 0 else self.getMaxXor(root, x)
        
        return result
