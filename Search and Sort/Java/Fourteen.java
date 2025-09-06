import java.util.HashMap;

class Solution {
    public int findSubarray(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        int ans = 0, sum = 0;
        for (int i : arr) {
            sum += i;
            if (map.containsKey(sum))
                ans += map.get(sum);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}

public class Fourteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findSubarray(new int[] { 0, 0, 5, 5, 0, 0 }));
        System.out.println(sol.findSubarray(new int[] { 6, -1, -3, 4, -2, 2, 4, 6, -12, -7 }));
        System.out.println(sol.findSubarray(new int[] { 0 }));
    }
}
