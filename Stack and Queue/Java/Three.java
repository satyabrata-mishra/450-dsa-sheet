
// User function Template for Java

import java.util.Stack;

class Solution {
    public void recursion(Stack<Integer> s, int curIndex, int middleIndex) {
        if (curIndex == middleIndex) {
            s.pop();
            return;
        }
        int temp = s.pop();
        recursion(s, curIndex + 1, middleIndex);
        s.push(temp);

    }

    public void deleteMid(Stack<Integer> s) {
        int mid = (int) Math.floor((s.size()) / 2);
        recursion(s, 0, mid);
    }
}

public class Three {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        Solution sol = new Solution();
        sol.deleteMid(st);
        while (!st.isEmpty()) {
            System.out.print(st.pop() + " ");
        }
    }
}
