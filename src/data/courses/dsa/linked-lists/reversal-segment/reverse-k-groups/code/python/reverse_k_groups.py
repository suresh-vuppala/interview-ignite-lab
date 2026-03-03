class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def insert(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = Node(data)
    
    def reverse_k_groups(self, k):
        self.head = self._reverse_k_helper(self.head, k)
    
    def _reverse_k_helper(self, head, k):
        curr = head
        count = 0
        while curr and count < k:
            curr = curr.next
            count += 1
        if count == k:
            curr = self._reverse_k_helper(curr, k)
            while count > 0:
                tmp = head.next
                head.next = curr
                curr = head
                head = tmp
                count -= 1
            head = curr
        return head
    
    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print("None")

if __name__ == "__main__":
    ll = LinkedList()
    for i in range(1, 9):
        ll.insert(i)
    print("Original: ", end="")
    ll.display()
    ll.reverse_k_groups(3)
    print("After reversing in groups of 3: ", end="")
    ll.display()