import java.util.HashMap;
import java.util.PriorityQueue;

class Pair {
    char c;
    int num;

    Pair(char c, int num) {
        this.c = c;
        this.num = num;
    }
}

class Solution {
    public String reorganizeString(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char i : s.toCharArray()) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        PriorityQueue<Pair> heap = new PriorityQueue<>((Pair a, Pair b) -> b.num - a.num);
        for (char i : map.keySet()) {
            heap.add(new Pair(i, map.get(i)));
        }
        StringBuilder ans = new StringBuilder();
        while (heap.size() > 1) {
            Pair p1 = heap.poll();
            Pair p2 = heap.poll();
            ans.append(p1.c);
            ans.append(p2.c);
            p1.num--;
            p2.num--;
            if (p1.num > 0) {
                heap.add(p1);
            }
            if (p2.num > 0) {
                heap.add(p2);
            }
        }
        if (heap.size() == 0) {
            return ans.toString();
        }
        if (heap.peek().num > 1) {
            return "";
        }
        return ans.toString() + heap.poll().c;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.reorganizeString("aab"));
        System.out.println(sol.reorganizeString("aaab"));
    }
}
