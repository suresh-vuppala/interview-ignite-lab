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
    
    def reverse_first_k(self, k):
        if not self.head or k <= 1:
            return
        prev, curr = None, self.head
        count = 0
        while curr and count < k:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            count += 1
        self.head.next = curr
        self.head = prev
    
    def display(self):
        curr = self.head
        while curr:
            print(curr.data, end=" -> ")
            curr = curr.next
        print("None")

if __name__ == "__main__":
    ll = LinkedList()
    for i in range(1, 7):
        ll.insert(i)
    print("Original: ", end="")
    ll.display()
    ll.reverse_first_k(3)
    print("After reversing first 3: ", end="")
    ll.display()