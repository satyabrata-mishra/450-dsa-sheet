
class Solution {

    public void rotateByK(int nums[], int k) {
        int n = nums.length;
        int ans[] = new int[n];
        k %= n;
        if (k == 0) {
            return;
        }
        int index = 0;
        for (int i = n - k; i < n; i++) {
            ans[index++] = nums[i];
        }
        for (int i = 0; i < n - k; i++) {
            ans[index++] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }

    public void rotate(int[] arr) {
        rotateByK(arr, 1);
    }
}

public class Six {

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5};
        Solution sol = new Solution();
        sol.rotate(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
