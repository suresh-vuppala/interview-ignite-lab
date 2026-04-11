class Solution {
    public int primMST(int V, List<List<int[]>> adj) {
        boolean[] inMST = new boolean[V];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.offer(new int[]{0, 0});
        int total = 0;
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            if (inMST[top[1]]) continue;
            inMST[top[1]] = true; total += top[0];
            for (int[] nb : adj.get(top[1]))
                if (!inMST[nb[0]]) pq.offer(new int[]{nb[1], nb[0]});
        }
        return total;
    }
}