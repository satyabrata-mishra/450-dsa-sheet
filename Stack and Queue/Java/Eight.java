import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        int n = arr.length;
        int ans[] = new int[n];
        Arrays.fill(ans, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && stack.peek() <= arr[i])
                stack.pop();
            if (!stack.empty())
                ans[i] = stack.peek();
            stack.push(arr[i]);
        }
        ArrayList<Integer> ans1 = new ArrayList<>();
        for (int i : ans)
            ans1.add(i);
        return ans1;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.nextLargerElement(new int[] { 1, 3, 2, 4 }));
        System.out.println(sol.nextLargerElement(new int[] { 6, 8, 0, 1, 3 }));
        System.out.println(sol.nextLargerElement(new int[] { 10, 20, 30, 50 }));
        System.out.println(sol.nextLargerElement(new int[] { 50, 40, 30, 10 }));
    }
}
