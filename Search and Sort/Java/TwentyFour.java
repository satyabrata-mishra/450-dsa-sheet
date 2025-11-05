class Solution {
    private boolean helper(int[] arr, int n, int k, int maxPages) {
        int sum = 0, studentsRequired = 1;
        for (int i : arr) {
            if (sum + i > maxPages) {
                ++studentsRequired;
                sum = i;
                if (studentsRequired > k) {
                    return false;
                }
            } else {
                sum += i;
            }
        }
        return true;
    }

    public int findPages(int[] arr, int k) {
        int n = arr.length;
        if (k > n) {
            return -1;
        }
        int low = Integer.MIN_VALUE, high = 0, result = -1;
        for (int i : arr) {
            low = Math.max(low, i);
            high += i;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(arr, n, k, mid) == true) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
}

public class TwentyFour {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findPages(new int[] { 12, 34, 67, 90 }, 2));
        System.out.println(sol.findPages(new int[] { 15, 17, 20 }, 5));
    }
}
