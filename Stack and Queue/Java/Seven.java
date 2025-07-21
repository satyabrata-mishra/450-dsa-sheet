import java.util.Stack;

class GfG {
    int min = Integer.MAX_VALUE;

    public void push(int a, Stack<Integer> s) {
        min = Math.min(min, a);
        s.add(a);
    }

    public int pop(Stack<Integer> s) {
        return s.pop();
    }

    public int min(Stack<Integer> s) {
        return min;
    }

    public boolean isFull(Stack<Integer> s, int n) {
        return s.size() == n;
    }

    public boolean isEmpty(Stack<Integer> s) {
        return s.isEmpty();
    }
}

public class Seven {
    public static void main(String[] args) {

    }
}
