class Solution {
    static int countSquares(int n) {
        int ans = 0, ind = 1;
        long mult = 1;
        while (mult < n) {
            mult = ind * ind;
            ++ans;
            ++ind;
        }
        return ans - 1;
    }
}

public class Three {
    public static void main(String[] args) {
        System.out.println(Solution.countSquares(9));
        System.out.println(Solution.countSquares(3));
    }
}
