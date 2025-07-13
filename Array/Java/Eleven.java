
import java.util.Arrays;

class Solution {

    // Function to merge the arrays.
    public void mergeArrays(int a[], int b[]) {
        int aInd = a.length - 1, bInd = 0, bLen = b.length;
        while (aInd >= 0 && bInd < bLen) {
            if (a[aInd] > b[bInd]) {
                int temp = a[aInd];
                a[aInd] = b[bInd];
                b[bInd] = temp;
                --aInd;
                ++bInd;
            } else {
                break;
            }
        }
        Arrays.sort(a);
        Arrays.sort(b);
    }
}

public class Eleven {

    public static void main(String[] args) {
        Solution sol = new Solution();
        int a[] = {2, 4, 7, 10};
        int b[] = {2, 3};
        sol.mergeArrays(a, b);
        for (int i : a) {
            System.out.print(i + " ");
        }
        for (int i : b) {
            System.out.print(i + " ");
        }
    }
}
