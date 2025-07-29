import java.util.Arrays;

class Solution {
    int getMinDiff(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int ans = arr[n - 1] - arr[0], min = arr[0] + k, max = arr[n - 1] - k;
        for (int i = 0; i < n - 1; i++) {
            int mini = Math.min(min, arr[i + 1] - k);
            int maxi = Math.max(max, arr[i] + k);
            if (mini < 0) {
                continue;
            }
            ans = Math.min(ans, maxi - mini);
        }
        return ans;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.getMinDiff(new int[] { 1, 5, 8, 10 }, 2));
        System.out.println(sol.getMinDiff(new int[] { 3, 9, 12, 16, 20 }, 3));
    }
}
