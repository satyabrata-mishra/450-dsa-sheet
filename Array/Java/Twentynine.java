import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        Collections.sort(arr);
        int n = arr.size();
        int ans = Integer.MAX_VALUE;

        int left = 0;
        int right = m - 1;

        while (right < n) {
            ans = Math.min(ans, arr.get(right) - arr.get(left));
            left++;
            right++;
        }

        return ans;
    }
}

public class Twentynine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findMinDiff(new ArrayList<>(Arrays.asList(3, 4, 1, 9, 56, 7, 9, 12)), 5)); // 6
        System.out.println(sol.findMinDiff(new ArrayList<>(Arrays.asList(7, 3, 2, 4, 9, 12, 56)), 3)); // 2
        System.out.println(sol.findMinDiff(new ArrayList<>(Arrays.asList(3, 4, 1, 9, 56)), 5)); // 55
    }
}
