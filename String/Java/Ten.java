
import java.util.ArrayList;
import java.util.HashSet;

class Solution {

    private String swap(String s, int i, int j) {
        char ch[] = s.toCharArray();
        char temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
        return new String(ch);
    }

    private void helper(String s, HashSet<String> set, int size) {
        if (s.length() == size) {
            set.add(s);
            return;
        }
        for (int i = size; i < s.length(); i++) {
            s = swap(s, i, size);
            helper(s, set, size + 1);
            s = swap(s, i, size);
        }
    }

    public ArrayList<String> findPermutation(String s) {
        ArrayList<String> ans = new ArrayList<>();
        HashSet<String> set = new HashSet<>();
        helper(s, set, 0);
        for (String i : set) {
            ans.add(i);
        }
        return ans;
    }
}

public class Ten {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findPermutation("abc"));
    }
}
