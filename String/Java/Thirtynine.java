import java.util.HashSet;

class Solution {
    public static int solve(int n, String s) {
        HashSet<Character> gotComputer = new HashSet<>();
        HashSet<Character> alreadyVisitedButNegative = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (gotComputer.contains(ch)) {
                gotComputer.remove(ch);
            } else if (gotComputer.size() < n && !gotComputer.contains(ch) && !alreadyVisitedButNegative.contains(ch)) {
                gotComputer.add(ch);
            } else {
                alreadyVisitedButNegative.add(ch);
            }
        }
        return alreadyVisitedButNegative.size();
    }
}

public class Thirtynine {
    public static void main(String[] args) {
        System.out.println(Solution.solve(3, "GACCBDDBAGEE")); // 1
        System.out.println(Solution.solve(1, "ABCBAC")); // 2
    }
}
