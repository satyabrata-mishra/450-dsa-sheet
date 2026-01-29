class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length, ans = Integer.MAX_VALUE, left = 0, right = 0;
        long sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                ans = Math.min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return (ans == Integer.MAX_VALUE ? 0 : ans);
    }
}

public class Thirty {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minSubArrayLen(7, new int[] { 2, 3, 1, 2, 4, 3 })); // 2
        System.out.println(sol.minSubArrayLen(4, new int[] { 1, 4, 4 }));// 1
        System.out.println(sol.minSubArrayLen(11, new int[] { 1, 1, 1, 1, 1, 1, 1, 1 }));// 0
    }
}
