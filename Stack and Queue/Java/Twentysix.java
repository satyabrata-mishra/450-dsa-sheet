import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public Queue<Integer> reverseQueue(Queue<Integer> queue) {
        if (queue.isEmpty())
            return queue;
        int front = queue.poll();
        reverseQueue(queue);
        queue.add(front);
        return queue;
    }
}

public class Twentysix {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        q.add(4);
        q.add(3);
        q.add(1);
        q.add(10);
        q.add(2);
        q.add(6);
        Solution sol = new Solution();
        System.out.println(sol.reverseQueue(q));
    }
}
