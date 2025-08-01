class Solution {
    static int findPosition(int n) {
        int count_of_1 = 0;
        int position = -1, cnt = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                count_of_1++;
                position = cnt;
            }
            if (count_of_1 == 2)
                return -1;

            n = n >> 1;
            cnt++;
        }
        return position;

    }
};

public class Five {
    public static void main(String[] args) {
        System.out.println(Solution.findPosition(2));
        System.out.println(Solution.findPosition(5));
    }
}
