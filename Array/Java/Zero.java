class Solution {
    public void reverseArray(int arr[]) {
        int i = 0, j = arr.length - 1;
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++i;
            --j;
        }
    }
}

public class Zero {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = { 1, 4, 3, 2, 6, 5, 7 };
        sol.reverseArray(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
