// User function Template for Java

class Solution {

    String printSequence(String s) {
        String[] arr = {
            "2", "22", "222",
            "3", "33", "333",
            "4", "44", "444",
            "5", "55", "555",
            "6", "66", "666",
            "7", "77", "777", "7777",
            "8", "88", "888",
            "9", "99", "999", "9999"
        };
        int n = s.length();
        String res = "";
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == ' ') {
                res += "0"; 
            }else {
                int idx = s.charAt(i) - 'A';
                res += arr[idx];
            }
        }
        return res;

    }
}

public class Nineteen {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.printSequence("GFG"));//43334
        System.out.println(sol.printSequence("HEY U"));//4433999088
    }
}
