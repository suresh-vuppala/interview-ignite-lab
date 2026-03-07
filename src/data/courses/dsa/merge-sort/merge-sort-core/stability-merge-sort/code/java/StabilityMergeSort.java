// Time: O(N log N), Space: O(N)

class Pair {
    int key;
    char value;
    Pair(int k, char v) { key = k; value = v; }
}

public class StabilityMergeSort {
    public static void mergeSort(Pair[] arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    private static void merge(Pair[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Pair[] L = new Pair[n1];
        Pair[] R = new Pair[n2];
        
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].key <= R[j].key) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
    
    public static void main(String[] args) {
        Pair[] arr = {new Pair(3, 'a'), new Pair(1, 'b'), new Pair(3, 'c'), new Pair(2, 'd')};
        mergeSort(arr, 0, arr.length - 1);
        for (Pair p : arr) System.out.print("(" + p.key + "," + p.value + ") ");
    }
}
