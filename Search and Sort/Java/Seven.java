import java.util.HashMap;

class Solution {
    int majorityElement(int arr[]) {
        int n = arr.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        int ans = -1;
        for (int i : map.keySet()) {
            if (map.get(i) > n / 2) {
                ans = i;
            }
        }
        return ans;
    }
}

public class Seven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.majorityElement(new int[] { 1, 1, 2, 1, 3, 5, 1 }));
        System.out.println(sol.majorityElement(new int[] { 2, 13 }));
        System.out.println(sol.majorityElement(new int[] { 7 }));
    }
}
