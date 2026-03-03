class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def merge(self, l1, l2): d=Node(0); c=d; [(c.next,l1,c):=(l1,l1.next,c.next) if l1.data<l2.data else (c.next,l2,c):=(l2,l2.next,c.next) for _ in iter(lambda:l1 and l2,None)]; c.next=l1 or l2; return d.next
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": m=LL(); l1=Node(1); l1.next=Node(3); l1.next.next=Node(5); l2=Node(2); l2.next=Node(4); m.display(m.merge(l1,l2))