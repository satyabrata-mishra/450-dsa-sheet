class Solution {

    int maxSubarraySum(int[] arr) {
        int ans = Integer.MIN_VALUE, sum = 0;
        for (int i : arr) {
            sum += i;
            ans = Math.max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
}

public class Seven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = { 2, 3, -8, 7, -1, 2, 3 };
        System.out.println(sol.maxSubarraySum(arr));
        arr = new int[] { -2, -4 };
        System.out.println(sol.maxSubarraySum(arr));
        arr = new int[] { 5, 4, 1, 7, 8 };
        System.out.println(sol.maxSubarraySum(arr));
    }
}
