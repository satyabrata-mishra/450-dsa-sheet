class Solution {

    private static void merge(int[] arr, int left, int mid, int right, long[] ans) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] arr1 = new int[n1];
        int[] arr2 = new int[n2];

        for (int i = 0; i < n1; i++) {
            arr1[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            arr2[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                arr[k++] = arr1[i++];
            } else {
                ans[0] += (n1 - i); // count inversions
                arr[k++] = arr2[j++];
            }
        }

        while (i < n1) {
            arr[k++] = arr1[i++];
        }

        while (j < n2) {
            arr[k++] = arr2[j++];
        }
    }

    private static void mergeSort(int[] arr, int left, int right, long[] ans) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, ans);
        mergeSort(arr, mid + 1, right, ans);
        merge(arr, left, mid, right, ans);
    }

    // i < j and arr[i] > arr[j]
    static int inversionCount(int arr[]) {
        if (arr == null || arr.length == 0)
            return 0;

        long[] ans = new long[1]; // acts like pass-by-reference
        mergeSort(arr, 0, arr.length - 1, ans);

        return (int) ans[0];
    }
}

public class Fiveteen {
    public static void main(String[] args) {
        int[] a1 = { 2, 4, 1, 3, 5 };
        int[] a2 = { 2, 3, 4, 5, 6 };
        int[] a3 = { 10, 10, 10 };

        System.out.println(Solution.inversionCount(a1)); // 3
        System.out.println(Solution.inversionCount(a2)); // 0
        System.out.println(Solution.inversionCount(a3)); // 0
    }
}
