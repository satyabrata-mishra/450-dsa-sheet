import java.util.HashMap;

class Solution {
    public boolean isSubset(int a[], int b[]) {
        if (b.length > a.length)
            return false;
        HashMap<Integer, Integer> aMap = new HashMap<>();
        HashMap<Integer, Integer> bMap = new HashMap<>();
        for (int i : a)
            aMap.put(i, aMap.getOrDefault(i, 0) + 1);
        for (int i : b)
            bMap.put(i, bMap.getOrDefault(i, 0) + 1);
        for (int i : bMap.keySet())
            if (!aMap.containsKey(i) || aMap.get(i) < bMap.get(i))
                return false;
        return true;
    }
}

public class TwentySix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.isSubset(new int[] { 11, 7, 1, 13, 21, 3, 7, 3 }, new int[] { 11, 3, 7, 1, 7 }));
        System.out.println(sol.isSubset(new int[] { 1, 2, 3, 4, 4, 5, 6 }, new int[] { 1, 2, 4 }));
        System.out.println(sol.isSubset(new int[] { 10, 5, 2, 23, 19 }, new int[] { 19, 5, 3 }));
        System.out.println(sol.isSubset(new int[] { 1, 2, 2 }, new int[] { 1, 1 }));
    }
}
