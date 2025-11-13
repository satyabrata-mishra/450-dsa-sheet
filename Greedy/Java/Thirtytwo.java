
class Solution {
    public String smallestNumber(int s, int d) {
        if (s > d * 9) {
            return -1;
        }
        --s;
        StringBuilder sb = new StringBuilder();
        while (d-- != 1) {
            if (sum > 9) {
                sb.append(9);
                sum -= 9;
            } else {
                sb.append(s);
                s = 0;
            }
        }
        sb.append(s + 1);
        return sb.reverse().toString();
    }
}

public class Thirtytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.smallestNumber(9, 2));
        System.out.println(sol.smallestNumber(20, 3));
    }
}
