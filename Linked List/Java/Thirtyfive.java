import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public String firstNonRepeating(String s) {
        Queue<Character> q = new LinkedList<>();
        int freq[] = new int[26];
        StringBuilder sb = new StringBuilder();
        for (char i : s.toCharArray()) {
            ++freq[i - 'a'];
            if (freq[i - 'a'] == 1) {
                q.add(i);
            }
            while (!q.isEmpty() && freq[q.peek() - 'a'] != 1) {
                q.poll();
            }
            if (q.isEmpty()) {
                sb.append('#');
            } else {
                sb.append(q.peek());
            }
        }
        return sb.toString();
    }
}

public class Thirtyfive {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.firstNonRepeating("aabc"));
        System.out.println(sol.firstNonRepeating("bb"));
    }
}
