class Node:
    def __init__(self, d): self.data=d; self.next=None
class CLL:
    def __init__(self): self.head=None
    def insert_begin(self, d): n=Node(d); [self.head,n.next]:=[n,n] if not self.head else [(c:=c.next for _ in iter(lambda:c.next!=self.head,None)) or (n.next,c.next,self.head):=(self.head,n,n) for c in [self.head]]
    def insert_end(self, d): n=Node(d); [self.head,n.next]:=[n,n] if not self.head else [(c:=c.next for _ in iter(lambda:c.next!=self.head,None)) or (c.next,n.next):=(n,self.head) for c in [self.head]]
    def display(self): [[(print(c.data,end=" ") or (c:=c.next)) for _ in iter(lambda:c!=self.head,None)] or print() for c in [self.head] if self.head]
if __name__=="__main__": cl=CLL(); cl.insert_end(1); cl.insert_end(2); cl.insert_begin(0); cl.display()