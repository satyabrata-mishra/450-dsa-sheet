class Solution {
    public boolean areIsomorphic(String s1, String s2) {
        if (s1.length() != s2.length())
            return false;
        int mapS[] = new int[26];
        int mapT[] = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            char s1C = s1.charAt(i), s2C = s2.charAt(i);
            if (mapS[s1C - 'a'] != mapT[s2C - 'a'])
                return false;
            mapS[s1C - 'a'] = i + 1;
            mapT[s2C - 'a'] = i + 1;
        }
        return true;
    }
}

public class Fourtyone {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.areIsomorphic("aab", "xxy"));
        System.out.println(sol.areIsomorphic("aab", "xyx"));
    }
}
