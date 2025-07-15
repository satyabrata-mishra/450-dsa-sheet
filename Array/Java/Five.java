
import java.util.ArrayList;
import java.util.HashSet;

class Solution {

    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        HashSet<Integer> setA = new HashSet<>();
        HashSet<Integer> setB = new HashSet<>();
        for (int i : a) {
            setA.add(i);
        }
        for (int i : b) {
            setB.add(i);
        }
        setA.addAll(setB);
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i : setA) {
            ans.add(i);
        }
        return ans;
    }
}

public class Five {

    public static void main(String[] args) {
        System.out.println(Solution.findUnion(new int[]{1, 2, 3, 2, 1}, new int[]{3, 2, 2, 3, 3, 2}));
        System.out.println(Solution.findUnion(new int[]{1, 2, 3}, new int[]{4, 5, 6}));
        System.out.println(Solution.findUnion(new int[]{1, 2, 1, 1, 2}, new int[]{2, 2, 1, 2, 1}));
    }
}
