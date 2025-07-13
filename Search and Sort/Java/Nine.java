
import java.util.Arrays;

class Solution {

    public boolean findPair(int[] arr, int x) {
        Arrays.sort(arr);
        int i = 0;
        int j = 1;
        while (j < arr.length) {
            int diff = Math.abs(arr[i] - arr[j]);

            if (diff == x) {
                return true;
            } else if (diff > x) {
                i++;
            } else {
                j++;
            }
            if (i == j) {
                j++;
            }
        }
        return false;

    }
}

public class Nine {

    public static void main(String[] args) {
        int arr[] = {5, 20, 3, 2, 5, 80};
        Solution sol = new Solution();
        System.out.println(sol.findPair(arr, 78));
    }
}
