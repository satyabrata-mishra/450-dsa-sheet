class Solution {
    static int setBits(int n) {
        return Integer.bitCount(n);
    }
}

public class Zero {
    public static void main(String[] args) {
        System.out.println(Solution.setBits(6));
        System.out.println(Solution.setBits(8));
        System.out.println(Solution.setBits(3));
    }
}
