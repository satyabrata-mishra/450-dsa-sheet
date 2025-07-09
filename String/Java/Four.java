class Solution {
    public static boolean areRotations(String s1, String s2) {
        return (s1 + s1).contains(s2);
    }
}

public class Four {
    public static void main(String[] args) {
        System.out.println(Solution.areRotations("abcd", "cdab"));
        System.out.println(Solution.areRotations("aab", "aba"));
        System.out.println(Solution.areRotations("abcd", "acbd"));
    }
}
