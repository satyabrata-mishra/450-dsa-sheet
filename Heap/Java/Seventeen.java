import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    String minSum(int[] arr) {
        StringBuilder ans = new StringBuilder();
        int carry = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i : arr) {
            pq.add(i);
        }
        while (!pq.isEmpty()) {
            int d1 = pq.poll(), d2 = 0;
            if (!pq.isEmpty()) {
                d2 = pq.poll();
            }
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            ans.append(sum % 10);
        }
        if (carry != 0) {
            ans.append(carry);
        }
        ans.reverse();
        int pos = 0;
        while (pos < ans.length() && ans.charAt(pos) == '0') {
            pos++;
        }
        if (pos == ans.length()) {
            return "0";
        }
        return ans.substring(pos);
    }
}

public class Seventeen {
    public static void main(String[] args) {

    }
}
