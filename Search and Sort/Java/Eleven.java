class Solution {
    public int findMaxSum(int arr[]) {
        int n = arr.length, a = arr[0], b = Math.max(arr[0], arr[1]);
        for (int i = 2; i < n; i++) {
            int pick = arr[i] + a;
            int notPick = b;
            a = b;
            b = Math.max(pick, notPick);
        }
        return b;
    }
}

public class Eleven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findMaxSum(new int[] { 5, 3, 4, 11, 2 }));// 16
        System.out.println(sol.findMaxSum(new int[] { 6, 7, 1, 3, 8, 2, 4 }));// 19
    }
}
