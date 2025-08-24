import java.util.Stack;

class StackQueue {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();

    public void push(int B) {
        s1.push(B);
    }

    public int pop() {
        if (s1.isEmpty())
            return -1;
        while (s1.size() > 1)
            s2.add(s1.pop());
        int ans = s1.pop();
        while (!s2.isEmpty())
            s1.add(s2.pop());
        return ans;
    }
}

public class Twentytwo {

}
