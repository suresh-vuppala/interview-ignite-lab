# ============================================================
# Getting Started with Arrays
# ============================================================

class Solution:
    def basicArrayOps(self):
        # Creation
        arr = [1, 2, 3, 4, 5]

        # Access O(1)
        print(arr[0])  # 1

        # Traversal O(N)
        for val in arr:
            print(val)

        # Insert at end O(1) amortized
        arr.append(6)

        # Insert at index O(N)
        arr.insert(2, 99)

        # Delete O(N)
        arr.pop(2)  # Remove at index
        arr.remove(3)  # Remove by value

        return arr
