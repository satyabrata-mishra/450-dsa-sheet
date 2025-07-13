
class Solution {

    public void segregateElements(int[] arr) {
        int n = arr.length, index = 0;
        int ans[] = new int[n];
        for (int i : arr) {
            if (i >= 0) {
                ans[index++] = i;
            }
        }
        for (int i : arr) {
            if (i < 0) {
                ans[index++] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            arr[i] = ans[i];
        }
    }
}

public class Four {

    public static void main(String[] args) {
        int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
        Solution sol = new Solution();
        sol.segregateElements(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
