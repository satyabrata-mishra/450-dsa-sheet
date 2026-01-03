// User function Template for Java

class Solution {
    public long countFriendsPairings(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = b + ((i - 1) * a);
            a = b;
            b = temp;
        }
        return b;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countFriendsPairings(1));// 1
        System.out.println(sol.countFriendsPairings(2));// 2
        System.out.println(sol.countFriendsPairings(3));// 4
        System.out.println(sol.countFriendsPairings(4));// 10
    }
}
