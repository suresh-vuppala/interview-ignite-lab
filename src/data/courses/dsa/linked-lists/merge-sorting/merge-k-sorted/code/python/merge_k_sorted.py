import heapq
class Node:
    def __init__(self, d): self.data=d; self.next=None
    def __lt__(self, o): return self.data<o.data
class LL:
    def merge_k(self, lists): pq=[n for n in lists if n]; heapq.heapify(pq); d=Node(0); c=d
        while pq: n=heapq.heappop(pq); c.next=n; c=c.next; [heapq.heappush(pq,n.next) for _ in [1] if n.next]
        return d.next
    def display(self, h): [print(h.data,end=" ") or (h:=h.next) for _ in iter(lambda:h,None)]; print()
if __name__=="__main__": m=LL(); l1=Node(1); l1.next=Node(4); l2=Node(2); l2.next=Node(3); m.display(m.merge_k([l1,l2]))