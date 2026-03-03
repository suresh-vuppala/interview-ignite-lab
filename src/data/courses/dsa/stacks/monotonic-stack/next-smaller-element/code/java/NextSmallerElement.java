int[] nextSmaller(int[] arr) {
    int n = arr.length;
    int[] res = new int[n];
    Stack<Integer> st = new Stack<>();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.isEmpty() && st.peek() >= arr[i]) st.pop();
        res[i] = st.isEmpty() ? -1 : st.peek();
        st.push(arr[i]);
    }
    return res;
}