class Node:
    def __init__(self, d): self.data=d; self.next=None
class CLL:
    def __init__(self): self.head=None
    def insert(self, d): n=Node(d); [self.head,n.next]:=[n,n] if not self.head else [(c:=c.next for _ in iter(lambda:c.next!=self.head,None)) or (c.next,n.next):=(n,self.head) for c in [self.head]]
    def delete_begin(self): [self.head:=None for _ in [1] if not self.head or self.head.next==self.head] or [(c:=c.next for _ in iter(lambda:c.next!=self.head,None)) or (c.next,self.head):=(self.head.next,self.head.next) for c in [self.head]]
    def display(self): [[(print(c.data,end=" ") or (c:=c.next)) for _ in iter(lambda:c!=self.head,None)] or print() for c in [self.head] if self.head]
if __name__=="__main__": cl=CLL(); [cl.insert(i) for i in range(1,5)]; cl.delete_begin(); cl.display()