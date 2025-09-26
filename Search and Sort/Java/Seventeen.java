import java.util.Arrays;

class Solution {
    public int minSwaps(int arr[]) {
        int n = arr.length, swaps = 0;
        int arr1[][] = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr1[i][0] = arr[i];
            arr1[i][1] = i;
        }
        Arrays.sort(arr1, (a, b) -> a[0] - b[0]);
        int i = 0;
        while (i < n) {
            if (arr1[i][1] != i) {
                ++swaps;
                int idx = arr1[i][1];
                int temp[] = arr1[i];
                arr1[i] = arr1[idx];
                arr1[idx] = temp;
            } else {
                ++i;
            }
        }
        return swaps;
    }
}

public class Seventeen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(
                sol.minSwaps(new int[] { 32524, 30965, 30657, 18612, 29956, 15628, 16059, 10826, 23546, 22340 }));
    }
}
