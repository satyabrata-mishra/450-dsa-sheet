import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution {
    public Queue<Integer> reverseFirstK(Queue<Integer> q, int k) {
        if (q.size() < k)
            return q;
        Stack<Integer> st = new Stack<>();
        while (k-- != 0)
            st.push(q.poll());
        Queue<Integer> tempQ = new LinkedList<>();
        while (!q.isEmpty())
            tempQ.add(q.poll());
        while (!st.isEmpty())
            q.add(st.pop());
        while (!tempQ.isEmpty())
            q.add(tempQ.poll());
        return q;
    }
}

public class Twentyseven {
    public static void main(String[] args) {

    }
}
