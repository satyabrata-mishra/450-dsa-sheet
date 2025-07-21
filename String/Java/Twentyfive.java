import java.util.HashMap;

class Solution {
    public int romanToDecimal(String s) {
        HashMap<Character, Integer> track = new HashMap<>();
        track.put('I', 1);
        track.put('V', 5);
        track.put('X', 10);
        track.put('L', 50);
        track.put('C', 100);
        track.put('D', 500);
        track.put('M', 1000);
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (track.get(s.charAt(i)) < track.get(s.charAt(i + 1))) {
                ans += track.get(s.charAt(i + 1)) - track.get(s.charAt(i));
                ++i;
            } else {
                ans += track.get(s.charAt(i));
            }
        }
        return ans;
    }
}

public class Twentyfive {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.romanToDecimal("IX"));
        System.out.println(sol.romanToDecimal("XL"));
        System.out.println(sol.romanToDecimal("MCMIV"));
    }
}
