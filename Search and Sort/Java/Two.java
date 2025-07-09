import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Integer> valueEqualToIndex(List<Integer> nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.size(); i++) {
            if (nums.get(i) == i + 1) {
                ans.add(i + 1);
            }
        }
        return ans;

    }
}

public class Two {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.valueEqualToIndex(new ArrayList<>(Arrays.asList(15, 2, 45, 4, 7))));
    }
}
