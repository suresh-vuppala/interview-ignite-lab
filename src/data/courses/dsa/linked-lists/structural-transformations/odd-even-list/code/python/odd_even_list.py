class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def odd_even(self, h):
        if not h: return None
        o,e,eh=h,h.next,h.next; [(o.next,o,e.next,e):=(e.next,o.next,o.next,e.next) for _ in iter(lambda:e and e.next,None)]; o.next=eh; return h
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": oe=LL(); h=Node(1); h.next=Node(2); h.next.next=Node(3); h.next.next.next=Node(4); h.next.next.next.next=Node(5); oe.display(oe.odd_even(h))