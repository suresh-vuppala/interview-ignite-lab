class Solution:
    # ==================== SOLUTION 1: USING TEMPORARY STACK ====================
    # Time: O(n²) | Space: O(n)
    def sortStackWithTemp(self, stack):
        temp = []
        
        while stack:
            # Pop element from input stack
            current = stack.pop()
            
            # Move elements from temp to input that are greater than current
            while temp and temp[-1] > current:
                stack.append(temp.pop())
            
            # Push current to temp in sorted position
            temp.append(current)
        
        # Transfer back to original stack
        while temp:
            stack.append(temp.pop())
        
        return stack
    
    # ==================== SOLUTION 2: RECURSIVE APPROACH ====================
    # Time: O(n²) | Space: O(n)
    def sortStackRecursive(self, stack):
        # Base case: empty stack
        if not stack:
            return stack
        
        # Pop top element
        temp = stack.pop()
        
        # Recursively sort remaining stack
        self.sortStackRecursive(stack)
        
        # Insert popped element in sorted position
        self._insertSorted(stack, temp)
        
        return stack
    
    def _insertSorted(self, stack, element):
        # Base case: empty stack or element is largest
        if not stack or stack[-1] <= element:
            stack.append(element)
            return
        
        # Pop top and recursively insert element
        temp = stack.pop()
        self._insertSorted(stack, element)
        
        # Push back the popped element
        stack.append(temp)
    
    # ==================== SOLUTION 3: USING ARRAY AND SORTING ====================
    # Time: O(n log n) | Space: O(n)
    def sortStackWithArray(self, stack):
        # Transfer to array
        arr = []
        while stack:
            arr.append(stack.pop())
        
        # Sort array
        arr.sort()
        
        # Push back in reverse order (largest first)
        for i in range(len(arr) - 1, -1, -1):
            stack.append(arr[i])
        
        return stack
    
    # ==================== SOLUTION 4: USING PRIORITY QUEUE (MIN HEAP) ====================
    # Time: O(n log n) | Space: O(n)
    def sortStackWithHeap(self, stack):
        import heapq
        
        # Transfer to min heap
        heap = []
        while stack:
            heapq.heappush(heap, stack.pop())
        
        # Transfer to temp stack (smallest first)
        temp = []
        while heap:
            temp.append(heapq.heappop(heap))
        
        # Transfer back to original (largest on top)
        while temp:
            stack.append(temp.pop())
        
        return stack
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    # Using Array + Sort for best time complexity
    def sortStack(self, stack):
        return self.sortStackWithArray(stack)
