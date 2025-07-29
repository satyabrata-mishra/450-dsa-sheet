import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.TreeSet;

class Solution {
    // Function to find common elements in three arrays.
    public List<Integer> commonElements(List<Integer> arr1, List<Integer> arr2,
            List<Integer> arr3) {
        HashSet<Integer> set1 = new HashSet<>(arr1);
        HashSet<Integer> set2 = new HashSet<>(arr2);
        HashSet<Integer> set3 = new HashSet<>(arr3);
        TreeSet<Integer> ans = new TreeSet<>();
        for (int i : set1) {
            if (set2.contains(i) && set3.contains(i)) {
                ans.add(i);
            }
        }
        if (ans.isEmpty()) {
            ans.add(-1);
        }
        return new ArrayList<>(ans);
    }
}

public class Eighteen {
    public static void main(String[] args) {
        List<Integer> arr1 = new ArrayList<>(Arrays.asList(1, 5, 10, 20, 40, 80));
        List<Integer> arr2 = new ArrayList<>(Arrays.asList(6, 7, 20, 80, 100));
        List<Integer> arr3 = new ArrayList<>(Arrays.asList(3, 4, 15, 20, 30, 70, 80, 120));
        Solution sol = new Solution();
        System.out.println(sol.commonElements(arr1, arr2, arr3));
    }
}
