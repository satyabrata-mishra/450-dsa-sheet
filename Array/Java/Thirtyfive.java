class Solution {
    private int medianOfTwo(int[] nums1, int[] nums2, boolean toggle) {
        int size1 = nums1.length, size2 = nums2.length;
        int low = Math.min(nums1[0], nums2[0]);
        int high = Math.max(nums1[size1 - 1], nums2[size2 - 1]);
        int target = (size1 + size2) / 2;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i : nums1) {
                if (i <= mid) {
                    count++;
                } else {
                    break;
                }
            }

            for (int i : nums2) {
                if (i <= mid) {
                    count++;
                } else {
                    break;
                }
            }

            if (toggle && count < target) {
                low = mid + 1;
            } else if (!toggle && count <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    private double median(int[] nums) {
        int n = nums.length;
        if (n % 2 == 0) {
            return ((double) nums[n / 2] + (double) nums[n / 2 - 1]) / 2.0;
        }
        return nums[n / 2];
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int size1 = nums1.length, size2 = nums2.length;
        if (size1 == 0) {
            return median(nums2);
        }
        if (size2 == 0) {
            return median(nums1);
        }
        if ((size1 + size2) % 2 != 0) {
            return (double) medianOfTwo(nums1, nums2, false);
        }
        return ((double) medianOfTwo(nums1, nums2, true) + (double) medianOfTwo(nums1, nums2, false)) / 2.0;
    }
}

public class Thirtyfive {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findMedianSortedArrays(new int[] { 1, 3 }, new int[] { 2 }));
        System.out.println(sol.findMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4 }));
        System.out.println(sol.findMedianSortedArrays(new int[] { 1, 2, 3, 4 }, new int[] {}));
        System.out.println(sol.findMedianSortedArrays(new int[] { 1, 2, 3, 4 }, new int[] {}));
    }
}
