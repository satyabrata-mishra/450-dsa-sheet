import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    void rightRotate(ArrayList<Integer> arr, int start, int end) {
        int temp = arr.get(end);
        for (int i = end; i > start; i--) {
            arr.set(i, arr.get(i - 1));
        }
        arr.set(start, temp);
    }

    void rearrange(ArrayList<Integer> arr) {
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            if ((i % 2 == 0 && arr.get(i) < 0) || (i % 2 != 0 && arr.get(i) >= 0)) {
                int j = i + 1;
                while (j < n) {
                    if ((i % 2 == 0 && arr.get(j) >= 0) || (i % 2 != 0 && arr.get(j) < 0)) {
                        break;
                    }
                    j++;
                }
                if (j == n) {
                    break;
                }
                rightRotate(arr, i, j);
            }
        }

    }
}

public class Nineteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(9, 4, -2, -1, 5, 0, -5, -3, 2));
        sol.rearrange(arr);
        System.out.println(arr);
    }
}
