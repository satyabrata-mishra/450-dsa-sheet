class Solution {
    private static int highestPowerOfTwo(int n) {
        return (int) (Math.log((double) n) / Math.log(2));
    }

    public static int countSetBits(int n) {
        if (n <= 0) {
            return 0;
        }
        int x = highestPowerOfTwo(n);
        int pow1 = (int) Math.pow((double) 2, x - 1);
        int pow2 = (int) Math.pow((double) 2, x);
        return (pow1 * x) + (n - pow2 + 1) + countSetBits(n - pow2);
    }
}

public class Three {
    public static void main(String[] args) {
        System.out.println(Solution.countSetBits(4));
        System.out.println(Solution.countSetBits(17));
    }
}
