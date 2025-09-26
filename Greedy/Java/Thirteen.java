import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public static ArrayList<Integer> maxMeetings(int n, int[] s, int[] f) {
        int list[][] = new int[n][3];
        for (int i = 0; i < n; i++) {
            list[i][0] = i + 1;
            list[i][1] = s[i];
            list[i][2] = f[i];
        }
        Arrays.sort(list, (a, b) -> a[2] - b[2]);
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(list[0][0]);
        int temp[] = list[0];
        for (int i = 1; i < n; i++) {
            if (temp[2] < list[i][1]) {
                temp = list[i];
                ans.add(list[i][0]);
            }
        }
        Collections.sort(ans);
        return ans;
    }
}

public class Thirteen {
    public static void main(String[] args) {
        System.out.println(Solution.maxMeetings(6, new int[] { 1, 3, 0, 5, 8, 5 }, new int[] { 2, 4, 6, 7, 9, 9 }));
    }
}
