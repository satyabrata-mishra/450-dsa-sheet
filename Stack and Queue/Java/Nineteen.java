import java.util.LinkedList;
import java.util.Queue;

class Queues {
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();

    void push(int a) {
        q1.add(a);
    }

    int pop() {
        if (q1.isEmpty())
            return -1;
        while (q1.size() > 1)
            q2.add(q1.poll());
        int ans = q1.poll();
        while (!q2.isEmpty())
            q1.add(q2.poll());
        return ans;
    }
}

public class Nineteen {

}
