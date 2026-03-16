import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        Collections.sort(arr);

        int n = arr.size();
        int left = 0;
        int right = m - 1;
        int ans = Integer.MAX_VALUE;

        while (right < n) {
            ans = Math.min(ans, arr.get(right) - arr.get(left));
            left++;
            right++;
        }

        return ans;
    }
}

public class Twentythree {
    public static void main(String[] args) {
        Solution sol = new Solution();

        ArrayList<Integer> arr1 = new ArrayList<>(Arrays.asList(3, 4, 1, 9, 56, 7, 9, 12));
        System.out.println(sol.findMinDiff(arr1, 5)); // 6

        ArrayList<Integer> arr2 = new ArrayList<>(Arrays.asList(7, 3, 2, 4, 9, 12, 56));
        System.out.println(sol.findMinDiff(arr2, 3)); // 2

        ArrayList<Integer> arr3 = new ArrayList<>(Arrays.asList(3, 4, 1, 9, 56));
        System.out.println(sol.findMinDiff(arr3, 5)); // 55
    }
}
