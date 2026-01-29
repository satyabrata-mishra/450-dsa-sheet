import java.util.ArrayList;

class Solution {
    public static ArrayList<Integer> factorial(int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(1);
        for (int i = 2; i <= n; i++) {
            int carry = 0;
            for (int j = ans.size() - 1; j >= 0; j--) {
                int temp = ans.get(j) * i + carry;
                ans.set(j, temp % 10);
                carry = temp / 10;
            }
            while (carry != 0) {
                ans.add(0, carry % 10); // insert at beginning
                carry /= 10;
            }
        }
        return ans;
    }
}

public class Twentyone {
    public static void main(String[] args) {
        System.out.println(Solution.factorial(10));
    }
}
