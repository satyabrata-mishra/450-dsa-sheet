import java.util.Stack;

class GfG {
    public void sortStack(Stack<Integer> s, int x) {
        if (s.isEmpty() || s.peek() <= x) {
            s.push(x);
        } else {
            int temp = s.pop();
            sortStack(s, x);
            s.push(temp);
        }
    }

    public Stack<Integer> sort(Stack<Integer> s) {
        if (!s.isEmpty()) {
            int temp = s.pop();
            sort(s);
            sortStack(s, temp);
        }
        return s;
    }
}

public class Fourteen {
    public static void main(String[] args) {
        GfG obj = new GfG();
        Stack<Integer> st = new Stack<>();
        st.push(11);
        st.push(2);
        st.push(32);
        st.push(3);
        st.push(41);
        st = obj.sort(st);
        while (!st.empty()) {
            System.out.print(st.pop() + " ");
        }
    }
}
