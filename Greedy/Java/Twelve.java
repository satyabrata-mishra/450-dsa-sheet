// User function Template for Java

class Solution {
    static int minimumDays(int S, int N, int M) {
        if (M > N) {
            return -1;
        }
        if (S > 6 && (6 * N) - (7 * M) < 0) {
            return -1;
        }
        return (int) Math.ceil(((double) S * M) / (double) N);
    }
}

public class Twelve {
    public static void main(String[] args) {
        System.out.println(Solution.minimumDays(10, 16, 2)); // 2
        System.out.println(Solution.minimumDays(10, 20, 30)); // -1
        System.out.println(Solution.minimumDays(10, 9, 8)); // -1
    }
}
