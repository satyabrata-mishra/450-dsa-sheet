import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        Integer candidate1 = null, candidate2 = null;
        int count1 = 0, count2 = 0;
        for (int i : nums) {
            if (candidate1 != null && i == candidate1) {
                count1++;
            } else if (candidate2 != null && i == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = i;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = i;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        int target = (int) Math.floor(nums.length / 3.0);
        for (int i : nums)
            if (candidate1 != null && i == candidate1)
                ++count1;
        for (int i : nums)
            if (candidate2 != null && i == candidate2)
                ++count2;
        ArrayList<Integer> arr = new ArrayList<>();
        if (count1 > target)
            arr.add(candidate1);
        if (count2 > target)
            arr.add(candidate2);
        return arr;
    }
}

public class Twentyfour {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.majorityElement(new int[] { 3, 2, 3 }));
        System.out.println(sol.majorityElement(new int[] { 1 }));
        System.out.println(sol.majorityElement(new int[] { 1, 2 }));
        System.out.println(sol.majorityElement(new int[] { 2, 2 }));
        System.out.println(sol.majorityElement(new int[] { 4, 2, 1, 1 }));
        System.out.println(sol.majorityElement(new int[] { -1, -1, -1 }));
    }
}
