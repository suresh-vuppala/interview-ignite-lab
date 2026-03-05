class Solution {
    public int[] nextGreaterElement(int[] arr) {
        int n = arr.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements smaller than or equal to current
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }
            // Top of stack is next greater element
            result[i] = stack.isEmpty() ? -1 : stack.peek();
            // Push current element
            stack.push(arr[i]);
        }
        return result;
    }
}
