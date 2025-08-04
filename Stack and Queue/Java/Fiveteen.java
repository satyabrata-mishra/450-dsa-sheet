import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public ArrayList<int[]> mergeOverlap(int[][] arr) {
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        ArrayList<int[]> ans = new ArrayList<>();
        int startTime = arr[0][0], finishTime = arr[0][1], n = arr.length;
        for (int i = 1; i < n; i++) {
            if (arr[i][0] <= finishTime)
                finishTime = Math.max(finishTime, arr[i][1]);
            else {
                ans.add(new int[] { startTime, finishTime });
                startTime = arr[i][0];
                finishTime = arr[i][1];
            }
        }
        ans.add(new int[] { startTime, finishTime });
        return ans;
    }
}

public class Fiveteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[][] = { { 1, 2 }, { 2, 13 } };
        for (int[] i : sol.mergeOverlap(arr))
            System.out.println(i[0] + " " + i[1]);
    }
}
