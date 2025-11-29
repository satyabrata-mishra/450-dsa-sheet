class Solution {
    public static int countBitsFlip(int a, int b) {
        int xor = a ^ b;
        int ans = 0;
        while (xor > 0) {
            ans += (xor & 1);
            xor >>= 1;
        }
        return ans;
    }
}

public class Two {
    public static void main(String[] args) {
        System.out.println(Solution.countBitsFlip(10, 20));// 4
        System.out.println(Solution.countBitsFlip(20, 25));// 4
        System.out.println(Solution.countBitsFlip(34, 7));// 3
    }
}
