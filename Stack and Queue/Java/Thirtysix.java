import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public String FirstNonRepeating(String s) {
        int freq[] = new int[26];
        StringBuilder sb = new StringBuilder();
        Queue<Character> q = new LinkedList<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq[c - 'a']++;
            if (freq[c - 'a'] == 1)
                q.add(c);
            while (!q.isEmpty() && freq[q.peek() - 'a'] != 1) {
                q.poll();
            }
            if (q.isEmpty())
                sb.append("#");
            else
                sb.append(q.peek());

        }
        return sb.toString();
    }
}

public class Thirtysix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.FirstNonRepeating("aabc"));
        System.out.println(sol.FirstNonRepeating("zz"));
        System.out.println(sol.FirstNonRepeating("bb"));
    }
}
