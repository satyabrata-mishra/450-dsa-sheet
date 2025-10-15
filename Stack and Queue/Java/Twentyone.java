import java.util.Stack;

class Solution {
    public boolean validateOp(int[] a, int[] b) {
        if (a.length != b.length) {
            return false;
        }
        Stack<Integer> st = new Stack<>();
        int n = a.length, j = 0;
        for (int i = 0; i < n; i++) {
            st.add(a[i]);
            while (!st.empty() && st.peek() == b[j]) {
                ++j;
                st.pop();
            }
        }
        return st.isEmpty();
    }
}

public class Twentyone {
    public static void main(String[] args) {

    }
}
