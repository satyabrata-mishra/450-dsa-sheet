import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public static void inorderTraversal(int arr[], ArrayList<Integer> inorder, int i, int n) {
        if (i >= n) {
            return;
        }
        inorderTraversal(arr, inorder, 2 * i + 1, n);
        inorder.add(arr[i]);
        inorderTraversal(arr, inorder, 2 * i + 2, n);
    }

    public static int minSwaps(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> inorder = new ArrayList<>();
        inorderTraversal(arr, inorder, 0, n);
        ArrayList<int[]> sortedList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sortedList.add(new int[] { inorder.get(i), i });
        }
        Collections.sort(sortedList, (a, b) -> a[0] - b[0]);
        int noOfSwaps = 0;
        for (int i = 0; i < n; i++) {
            if (sortedList.get(i)[1] != i) {
                int oldIndex = sortedList.get(i)[1];
                int[] temp = sortedList.get(i);
                sortedList.set(i, sortedList.get(temp[1]));
                sortedList.set(oldIndex, temp);
                noOfSwaps++;
                --i;
            }
        }
        return noOfSwaps;
    }
}

public class Twenty {
    public static void main(String[] args) {
        System.out.println(Solution.minSwaps(new int[] { 5, 6, 7, 8, 9, 10, 11 }));// 3
        System.out.println(Solution.minSwaps(new int[] { 1, 2, 3 }));// 1
    }
}
