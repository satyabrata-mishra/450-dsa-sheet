import java.util.PriorityQueue;

class Pair {
    char character;
    int freq;

    public Pair(char character, int freq) {
        this.character = character;
        this.freq = freq;
    }
}

class Solution {
    public static String rearrangeString(String s) {
        int freq[] = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.freq - a.freq);
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                Pair p = new Pair((char) (i + 'a'), freq[i]);
                pq.add(p);
            }
        }
        String ans = "";
        while (pq.size() > 1) {
            Pair p1 = pq.poll(), p2 = pq.poll();
            p1.freq--;
            p2.freq--;
            ans += "" + p1.character + p2.character;
            if (p1.freq > 0) {
                pq.add(p1);
            }
            if (p2.freq > 0) {
                pq.add(p2);
            }
        }
        if (pq.isEmpty()) {
            return ans;
        }
        if (pq.peek().freq > 1) {
            return "";
        }
        return ans + pq.peek().character;
    }
}

public class Sixteen {
    public static void main(String[] args) {
        System.out.println(Solution.rearrangeString("aaabc"));
        System.out.println(Solution.rearrangeString("aaabb"));
        System.out.println(Solution.rearrangeString("aaaabc"));
    }
}
