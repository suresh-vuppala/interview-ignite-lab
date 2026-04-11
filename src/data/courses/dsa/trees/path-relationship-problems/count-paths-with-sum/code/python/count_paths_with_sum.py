# ============================================================
# Path Sum III
# ============================================================
from collections import defaultdict
class Solution:
    def pathSum(self, root, targetSum: int) -> int:
        prefix_map = defaultdict(int)
        prefix_map[0] = 1

        def dfs(node, current_sum):
            if not node: return 0
            current_sum += node.val
            count = prefix_map[current_sum - targetSum]
            prefix_map[current_sum] += 1
            count += dfs(node.left, current_sum) + dfs(node.right, current_sum)
            prefix_map[current_sum] -= 1  # Backtrack
            return count

        return dfs(root, 0)
