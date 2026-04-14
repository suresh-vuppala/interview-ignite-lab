# ============================================================
# Solution 1: Check all pairs — O(N²)
# ============================================================
class Solution1:
    def findMaximumXOR(self, nums):
        max_xor = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                max_xor = max(max_xor, nums[i] ^ nums[j])
        return max_xor

# ============================================================
# Solution 2: Binary Trie — O(N*32) = O(N)
# ============================================================
class Solution2:
    def findMaximumXOR(self, nums):
        root = {}
        # Insert all numbers bit by bit (MSB first)
        for num in nums:
            node = root
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                if bit not in node: node[bit] = {}
                node = node[bit]
        # Query max XOR for each number
        max_xor = 0
        for num in nums:
            node, xor_val = root, 0
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                opp = 1 - bit  # Want opposite for max XOR
                if opp in node:
                    xor_val |= (1 << i)
                    node = node[opp]
                else:
                    node = node[bit]
            max_xor = max(max_xor, xor_val)
        return max_xor
