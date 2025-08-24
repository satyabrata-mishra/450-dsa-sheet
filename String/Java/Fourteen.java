class Solution {
    void reverse(int[] arr, int i, int j) {
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++i;
            --j;
        }
    }

    void nextPermutation(int[] arr) {
        int breakpoint = -1, n = arr.length;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                breakpoint = i;
                break;
            }
        }
        if (breakpoint == -1) {
            reverse(arr, 0, n - 1);
            return;
        }
        for (int i = n - 1; i > breakpoint; i--) {
            if (arr[i] > arr[breakpoint]) {
                int temp = arr[i];
                arr[i] = arr[breakpoint];
                arr[breakpoint] = temp;
                break;
            }
        }
        reverse(arr, breakpoint + 1, n - 1);
    }
}

public class Fourteen {

}
