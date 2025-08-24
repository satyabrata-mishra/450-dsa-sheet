class Solution {
    public int findStepKeyIndex(int[] arr, int k, int x) {
        int n = arr.length, i = 0;
        while (i < n) {
            if (arr[i] == x)
                return i;
            int jump = Math.max(1, (int) Math.abs(arr[i] - x) / k);
            i += jump;
        }
        return -1;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findStepKeyIndex(new int[] { 4, 5, 6, 7, 6 }, 1, 6));
        System.out.println(sol.findStepKeyIndex(new int[] { 20, 40, 50 }, 20, 70));
    }
}
