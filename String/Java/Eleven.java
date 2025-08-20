// User function Template for Java

class Solution {
    public static int maxSubStr(String str) {
        int count = 0, ans = 0;
        for (char i : str.toCharArray()) {
            if (i == '0')
                ++count;
            else
                --count;
            if (count == 0)
                ++ans;
        }
        return count == 0 ? ans : -1;
    }
}

public class Eleven {
    public static void main(String[] args) {
        System.out.println(Solution.maxSubStr("0100110101"));
        System.out.println(Solution.maxSubStr("0111100010"));
    }
}
