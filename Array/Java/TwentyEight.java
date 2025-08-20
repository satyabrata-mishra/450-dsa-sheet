class Solution {
    public int maxWater(int arr[]) {
        int n = arr.length;
        int left[] = new int[n];
        int right[] = new int[n];
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = Math.max(left[i - 1], arr[i]);
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = Math.max(right[i + 1], arr[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int temp = Math.min(left[i - 1], right[i + 1]);
            if (temp > arr[i])
                ans += temp - arr[i];
        }
        return ans;
    }
}

public class TwentyEight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxWater(new int[] { 3, 0, 1, 0, 4, 0, 2 }));
        System.out.println(sol.maxWater(new int[] { 3, 0, 2, 0, 4 }));
        System.out.println(sol.maxWater(new int[] { 1, 2, 3, 4 }));
        System.out.println(sol.maxWater(new int[] { 2, 1, 5, 3, 1, 0, 4 }));
    }
}
