# Time: O(N²), Space: O(N)
def sort_stack_brute_force(stack):
    if not stack:
        return
    temp = []
    while stack:
        temp.append(stack.pop())
    temp.sort()
    while temp:
        stack.append(temp.pop())

# ============================================================

# Time: O(N²), Space: O(N)
def sort_stack_temp_stack(stack):
    temp = []
    while stack:
        curr = stack.pop()
        while temp and temp[-1] > curr:
            stack.append(temp.pop())
        temp.append(curr)
    while temp:
        stack.append(temp.pop())

# ============================================================

# Time: O(N²), Space: O(N)
def sort_stack_recursion_helper(stack):
    def insert_sorted(stack, element):
        if not stack or stack[-1] <= element:
            stack.append(element)
            return
        temp = stack.pop()
        insert_sorted(stack, element)
        stack.append(temp)
    
    if not stack:
        return
    temp = stack.pop()
    sort_stack_recursion_helper(stack)
    insert_sorted(stack, temp)

# ============================================================

# Time: O(N²), Space: O(N)
def sort_stack_recursion_inline(stack):
    if not stack:
        return
    temp = stack.pop()
    sort_stack_recursion_inline(stack)
    
    def insert(val):
        if not stack or stack[-1] <= val:
            stack.append(val)
        else:
            top = stack.pop()
            insert(val)
            stack.append(top)
    
    insert(temp)

# ============================================================

# Time: O(N log N), Space: O(N)
def sort_stack_merge_sort(stack):
    def merge(left, right):
        result = []
        while left and right:
            if left[-1] <= right[-1]:
                result.append(left.pop())
            else:
                result.append(right.pop())
        while left:
            result.append(left.pop())
        while right:
            result.append(right.pop())
        return result
    
    if len(stack) <= 1:
        return stack
    
    mid = len(stack) // 2
    left = [stack[i] for i in range(mid)]
    right = [stack[i] for i in range(mid, len(stack))]
    
    left = sort_stack_merge_sort(left)
    right = sort_stack_merge_sort(right)
    
    return merge(left, right)
