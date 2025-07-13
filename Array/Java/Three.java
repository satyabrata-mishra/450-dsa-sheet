class Solution {
    public void sort012(int[] arr) {
        int zero = 0, one = 0, two = 0;
        for (int i : arr) {
            switch (i) {
                case 0 -> zero++;
                case 1 -> one++;
                case 2 -> two++;
            }
        }
        int index = 0;
        while (zero-- != 0) {
            arr[index++] = 0;
        }
        while (one-- != 0) {
            arr[index++] = 1;
        }
        while (two-- != 0) {
            arr[index++] = 2;
        }
    }
}

public class Three {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
        sol.sort012(arr);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
