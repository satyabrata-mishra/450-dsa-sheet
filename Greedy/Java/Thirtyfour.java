class Solution {
    public static int maxEqualSum(int N1, int N2, int N3, int[] S1, int[] S2,
            int[] S3) {

        int i = 0, j = 0, k = 0;
        int sum1 = 0, sum2 = 0, sum3 = 0;

        // Calculate initial sums
        for (int num : S1) {
            sum1 += num;
        }
        for (int num : S2) {
            sum2 += num;
        }
        for (int num : S3) {
            sum3 += num;
        }

        // Remove elements from the top until sums are equal
        while (i < N1 && j < N2 && k < N3) {

            if (sum1 == sum2 && sum2 == sum3) {
                return sum1;
            }

            // Remove from the stack with the largest sum
            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= S1[i++];
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= S2[j++];
            } else {
                sum3 -= S3[k++];
            }
        }

        return 0;
    }
}

public class Thirtyfour {
    public static void main(String[] args) {

        System.out.println(
                Solution.maxEqualSum(3, 4, 2,
                        new int[] { 4, 2, 3 },
                        new int[] { 1, 1, 2, 3 },
                        new int[] { 1, 4 }));

        System.out.println(
                Solution.maxEqualSum(2, 1, 3,
                        new int[] { 4, 7 },
                        new int[] { 10 },
                        new int[] { 1, 2, 3 }));
    }
}
