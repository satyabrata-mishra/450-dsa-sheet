import java.util.Arrays;

class Solution {
    public boolean hasTripletSum(int arr[], int target) {
        Arrays.sort(arr);
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == target)
                    return true;
                else if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return false;
    }
}

public class Twentyseven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.hasTripletSum(new int[] { 1, 4, 45, 6, 10, 8 }, 13));
        System.out.println(sol.hasTripletSum(new int[] { 1, 2, 4, 3, 6, 7 }, 10));
        System.out.println(sol.hasTripletSum(new int[] { 40, 20, 10, 3, 6, 7 }, 24));
    }
}
