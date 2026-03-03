class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def partition(self, h, x): d1,d2,p1,p2=Node(0),Node(0),Node(0),Node(0); p1,p2=d1,d2; [(p1.next,p1):=(h,p1.next) if h.data<x else (p2.next,p2):=(h,p2.next) or (h:=h.next) for _ in iter(lambda:h,None)]; p2.next=None; p1.next=d2.next; return d1.next
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": p=LL(); h=Node(1); h.next=Node(4); h.next.next=Node(3); h.next.next.next=Node(2); p.display(p.partition(h,3))