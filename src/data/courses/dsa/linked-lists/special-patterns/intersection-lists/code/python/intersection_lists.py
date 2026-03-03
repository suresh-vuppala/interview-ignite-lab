class Node:
    def __init__(self, d): self.data=d; self.next=None
class LL:
    def get_intersection(self, h1, h2): p1,p2=h1,h2; [(p1,p2):=(h2 if not p1 else p1.next, h1 if not p2 else p2.next) for _ in iter(lambda:p1!=p2,None)]; return p1
if __name__=="__main__": il=LL(); c=Node(8); c.next=Node(10); h1=Node(3); h1.next=Node(6); h1.next.next=c; h2=Node(4); h2.next=c; i=il.get_intersection(h1,h2); print(f"Intersection: {i.data if i else 'None'}")