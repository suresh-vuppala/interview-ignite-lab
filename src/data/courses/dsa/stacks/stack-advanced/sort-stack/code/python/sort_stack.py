# ============================================================
# Sort Stack
# ============================================================

class Solution:
    def sortStack(self, stack):
        aux = []

        while stack:
            temp = stack.pop()

            # Move larger elements back to input
            while aux and aux[-1] > temp:
                stack.append(aux.pop())

            # Place temp at correct position
            aux.append(temp)

        # Move back to original stack
        while aux:
            stack.append(aux.pop())
