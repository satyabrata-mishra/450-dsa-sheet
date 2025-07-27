import java.util.ArrayList;

public class Twentyfour {
    private static ArrayList<Integer> boyerMooreAlgo(String str, String pattern) {
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0, j = pattern.length();
        while (j <= str.length()) {
            String temp = str.substring(i, j);
            if (temp.equals(pattern)) {
                ans.add(i);
            }
            ++i;
            ++j;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(boyerMooreAlgo("AABAACAADAABAABA", "AABA"));
    }
}
