class Solution {
    public static boolean isPowerofTwo(int n) {
        return (n & n - 1) == 0;
    }
}

public class Four {
    public static void main(String[] args) {
        System.out.println(Solution.isPowerofTwo(8));
        System.out.println(Solution.isPowerofTwo(98));
        System.out.println(Solution.isPowerofTwo(1));
    }
}
