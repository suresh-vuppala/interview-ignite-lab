class Solution {
    public int minPlatforms(int[] arr, int[] dep) {
        Arrays.sort(arr); Arrays.sort(dep);
        int plat=0, max=0, i=0, j=0;
        while (i < arr.length) {
            if (arr[i] <= dep[j]) { plat++; i++; } else { plat--; j++; }
            max = Math.max(max, plat);
        }
        return max;
    }
}