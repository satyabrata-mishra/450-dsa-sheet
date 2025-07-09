// User function Template for Java

import java.util.ArrayList;
import java.util.Arrays;

class GFG {
    int binarySearch(int arr[], int k, boolean toogle) {
        int ans = -1, left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == k) {
                ans = mid;
                if (toogle) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (arr[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    ArrayList<Integer> find(int arr[], int x) {
        return new ArrayList<>(Arrays.asList(binarySearch(arr, x, true), binarySearch(arr, x, false)));
    }
}

public class One {
    public static void main(String args[]) {
        GFG sol = new GFG();
        System.out.println(sol.find(new int[] { 1, 3, 5, 5, 5, 5, 67, 123, 125 }, 5));
        System.out.println(sol.find(new int[] { 1, 3, 5, 5, 5, 5, 7, 123, 125 }, 7));
        System.out.println(sol.find(new int[] { 1, 2, 3 }, 4));
    }
}
