import java.util.Stack;

class Solution {
    static void insertInButtom(Stack<Integer> st, int x) {
        if (st.isEmpty()) {
            st.push(x);
            return;
        }
        int temp = st.pop();
        insertInButtom(st, x);
        st.push(temp);
    }

    static void reverse(Stack<Integer> st) {
        if (st.isEmpty())
            return;
        int temp = st.pop();
        reverse(st);
        insertInButtom(st, temp);
    }
}

public class Thirteen {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(3);
        st.push(2);
        st.push(1);
        st.push(6);
        st.push(7);
        Solution.reverse(st);
        System.out.println(st);
    }
}
