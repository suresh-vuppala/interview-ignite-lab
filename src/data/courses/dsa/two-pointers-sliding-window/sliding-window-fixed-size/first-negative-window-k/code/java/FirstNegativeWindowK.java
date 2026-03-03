class FirstNegativeWindowK {
    public List<Integer> firstNegative(int[] arr, int k) {
        List<Integer> res = new ArrayList<>();
        Deque<Integer> dq = new LinkedList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) dq.add(i);
            if (i >= k - 1) {
                while (!dq.isEmpty() && dq.peek() < i - k + 1) dq.poll();
                res.add(dq.isEmpty() ? 0 : arr[dq.peek()]);
            }
        }
        return res;
    }
}