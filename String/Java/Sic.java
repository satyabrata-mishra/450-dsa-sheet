class Solution {
    String count(String n) {
        String ans = "";
        char curCh = n.charAt(0);
        int count = 1;
        for (int i = 1; i < n.length(); i++) {
            if (n.charAt(i) == curCh) {
                count++;
            } else {
                ans += "" + count + curCh;
                curCh = n.charAt(i);
                count = 1;
            }
        }
        ans += "" + count + curCh;
        return ans;
    }

    public String countAndSay(int n) {
        String ans = "1";
        while (--n != 0) {
            ans = count(ans);
        }
        return ans;
    }
}

public class Sic {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countAndSay(1));
        System.out.println(sol.countAndSay(4));
    }
}
