class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0], fast = nums[0], n = nums.length;
        while (fast <= n + 1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        int slow1 = nums[0];
        while (slow != slow1) {
            slow = nums[slow];
            slow1 = nums[slow1];
        }
        return slow;
    }
}

public class Ten {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findDuplicate(new int[] { 1, 3, 4, 2, 2 }));
        System.out.println(sol.findDuplicate(new int[] { 3, 1, 3, 4, 2 }));
        System.out.println(sol.findDuplicate(new int[] { 3, 3, 3, 3, 3 }));
    }
}
