
import java.util.ArrayList;
import java.util.Arrays;

class GFG {

    int helper(int arr[], int x, boolean toogle) {
        int low = 0, high = arr.length - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                ans = mid;
                if (toogle) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    ArrayList<Integer> find(int arr[], int x) {
        return new ArrayList<>(Arrays.asList(helper(arr, x, true), helper(arr, x, false)));
    }
}

public class Zero {

    public static void main(String[] args) {
        int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
        GFG sol = new GFG();
        System.out.println(sol.find(arr, 5));
    }
}
