import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;

class Solution {
    public static ArrayList<ArrayList<Integer>> getPairs(int[] arr) {
        Arrays.sort(arr);
        HashSet<ArrayList<Integer>> set = new HashSet<>();
        int i = 0, j = arr.length - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == 0) {
                set.add(new ArrayList<>(Arrays.asList(arr[i], arr[j])));
                ++i;
                --j;
            } else if (sum < 0) {
                ++i;
            } else {
                --j;
            }
        }
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (ArrayList<Integer> k : set) {
            ans.add(k);
        }
        Collections.sort(ans, (ArrayList<Integer> a, ArrayList<Integer> b) -> a.get(0) - b.get(0));
        return ans;
    }
}

public class Seventeen {
    public static void main(String[] args) {
        System.out.println(Solution.getPairs(new int[] { -1, 0, 1, 2, -1, -4 }));
        System.out.println(Solution.getPairs(new int[] { 6, 1, 8, 0, 4, -9, -1, -10, -6, -5 }));
    }
}
