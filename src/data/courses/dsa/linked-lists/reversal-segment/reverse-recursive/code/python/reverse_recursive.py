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
    
    def reverse(self):
        self.head = self._reverse_helper(self.head)
    
    def _reverse_helper(self, node):
        if not node or not node.next:
            return node
        new_head = self._reverse_helper(node.next)
        node.next.next = node
        node.next = None
        return new_head
    
    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print("None")

if __name__ == "__main__":
    ll = LinkedList()
    for i in range(1, 6):
        ll.insert(i)
    print("Original: ", end="")
    ll.display()
    ll.reverse()
    print("Reversed: ", end="")
    ll.display()