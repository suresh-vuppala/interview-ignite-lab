class StackUsingQueues {
    Queue<Integer> q = new LinkedList<>();
    
    void push(int x) {
        q.add(x);
        for (int i = 0; i < q.size() - 1; i++) q.add(q.poll());
    }
    
    int pop() {
        return q.poll();
    }
    
    int top() {
        return q.peek();
    }
}