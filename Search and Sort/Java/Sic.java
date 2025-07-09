// User function Template for Java

import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    // Function to find two elements in array
    ArrayList<Integer> findTwoElement(int arr[]) {
        ArrayList<Integer> ans = new ArrayList<>();
        int n = arr.length;
        long sum = 0, naturalNos = ((long) n * (n + 1)) / 2;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
            sum += (long) i;
        }
        ;
        for (int i : map.keySet()) {
            if (map.get(i) > 1) {
                ans.add(i);
                break;
            }
        }
        ans.add((int) (naturalNos - sum + ans.get(0)));
        return ans;
    }
}

public class Sic {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findTwoElement(new int[] { 4, 3, 6, 2, 1, 1 }));
        System.out.println(sol.findTwoElement(new int[] { 1, 3, 3 }));
    }
}
