import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public Queue<Integer> rearrangeQueue(Queue<Integer> q) {
        Queue<Integer> q1 = new LinkedList<>();
        int n = q.size();
        for (int i = 0; i < n / 2; i++)
            q1.add(q.poll());
        Queue<Integer> ans = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                ans.add(q1.poll());
            else
                ans.add(q.poll());
        }
        return ans;
    }
}

public class Twentyeight {
    public static void main(String[] args) {
    }
}
