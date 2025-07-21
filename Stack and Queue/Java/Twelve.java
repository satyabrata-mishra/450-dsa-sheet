import java.util.Stack;

class Solution {
    public Stack<Integer> insertAtBottom(Stack<Integer> st, int x) {
        Stack<Integer> q = new Stack<>();
        while (!st.empty()) {
            q.push(st.pop());
        }
        st.push(x);
        while (!q.empty()) {
            st.push(q.pop());
        }
        return st;
    }
}

public class Twelve {
    public static void main(String[] args) {

    }
}
