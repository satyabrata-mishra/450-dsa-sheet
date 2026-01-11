import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public ArrayList<Integer> getMinMax(int[] arr) {
        int n = arr.length;
        int mini, maxi, i;
        if (n % 2 == 0) {
            if (arr[0] < arr[1]) {
                mini = arr[0];
                maxi = arr[1];
            } else {
                mini = arr[1];
                maxi = arr[0];
            }
            i = 2;
        } else {
            mini = maxi = arr[0];
            i = 1;
        }
        while (i < n - 1) {
            if (arr[i] < arr[i + 1]) {
                mini = Math.min(mini, arr[i]);
                maxi = Math.max(maxi, arr[i + 1]);
            } else {
                mini = Math.min(mini, arr[i + 1]);
                maxi = Math.max(maxi, arr[i]);
            }
            i += 2;
        }
        return new ArrayList<>(Arrays.asList(mini, maxi));
    }
}

public class Four {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.getMinMax(new int[] { 1, 4, 3, -5, -4, 8, 6 }));
        System.out.println(sol.getMinMax(new int[] { 12, 3, 15, 7, 9 }));
    }
}
