import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int target) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        int n = arr.length;
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long sum = (long) arr[i] + arr[j] + arr[left] + arr[right];
                    if (sum == target) {
                        ans.add(new ArrayList<>(Arrays.asList(arr[i], arr[j], arr[left], arr[right])));
                        while (left < right && arr[left] == arr[left + 1])
                            left++;
                        while (left < right && arr[right] == arr[right - 1])
                            right--;
                        left++;
                        right--;
                    } else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
}

public class Ten {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.fourSum(new int[] { 0, 0, 2, 1, 1 }, 3));
        System.out.println(sol.fourSum(new int[] { 10, 2, 3, 4, 5, 7, 8 }, 23));
        System.out.println(sol.fourSum(new int[] { 0, 0, 2, 1, 1 }, 2));
    }
}
