class Solution {
    int minSwap(int[] arr, int k) {
        int count = 0, n = arr.length;
        for (int i : arr) {
            if (i <= k) {
                ++count;
            }
        }
        int ans = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i] > k) {
                ++ans;
            }
        }
        int right = 0, left = count;
        while (left < n) {
            int temp = ans;
            if (arr[right] > k) {
                --temp;
            }
            if (arr[left] > k) {
                ++temp;
            }
            ++right;
            ++left;
            ans = Math.min(ans, temp);
        }
        return ans;
    }
}

public class Thirtytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minSwap(new int[] { 2, 4, 5, 3, 6, 1, 8 }, 6)); // 0
        System.out.println(sol.minSwap(new int[] { 2, 7, 9, 5, 8, 7, 4 }, 6)); // 2
        System.out.println(sol.minSwap(new int[] { 2, 1, 5, 6, 3 }, 3)); // 1
    }
}
