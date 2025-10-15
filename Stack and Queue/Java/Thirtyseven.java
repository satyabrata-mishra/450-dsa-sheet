import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

class Solution {
    static ArrayList<Integer> nextSmallerEle(int[] arr) {
        int n = arr.length;
        Stack<Integer> stack = new Stack<>();
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() >= arr[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                ans.add(-1);
            } else {
                ans.add(stack.peek());
            }
            stack.add(arr[i]);
        }
        Collections.reverse(ans);
        return ans;

    }
}

public class Thirtyseven {
    public static void main(String[] args) {
        System.out.println(Solution.nextSmallerEle(new int[] { 4, 8, 5, 2, 25 }));
        System.out.println(Solution.nextSmallerEle(new int[] { 13, 7, 6, 12 }));
        System.out.println(Solution.nextSmallerEle(new int[] { 4, 1 }));
    }
}
