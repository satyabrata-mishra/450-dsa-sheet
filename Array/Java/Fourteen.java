class Solution {
    public void reverse(int nums[], int i, int j) {
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            ++i;
            --j;
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length, breakPoint = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1) {
            reverse(nums, 0, n - 1);
            return;
        }
        for (int i = n - 1; i > breakPoint; i--) {
            if (nums[i] > nums[breakPoint]) {
                int temp = nums[i];
                nums[i] = nums[breakPoint];
                nums[breakPoint] = temp;
                break;
            }
        }
        reverse(nums, breakPoint + 1, n - 1);
    }
}

public class Fourteen {
    public static void main(String[] args) {
        int nums[] = { 1, 2, 3 };
        Solution sol = new Solution();
        sol.nextPermutation(nums);
        for (int i : nums)
            System.out.print(i + " ");
    }
}
