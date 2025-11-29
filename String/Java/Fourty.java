class Solution {
    private boolean isAnagram(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }
        int freq[] = new int[256];
        for (char i : a.toCharArray()) {
            freq[i]++;
        }
        for (char i : b.toCharArray()) {
            freq[i]--;
        }
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }

    int transform(String a, String b) {
        if (!isAnagram(a, b)) {
            return -1;
        }
        int aLen = a.length(), bLen = b.length();
        int ans = 0, i = aLen - 1, j = bLen - 1;
        while (i >= 0 && j >= 0) {
            if (a.charAt(i) == b.charAt(j)) {
                --i;
                --j;
            } else {
                ++ans;
                --i;
            }
        }
        return ans;
    }
}

public class Fourty {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.transform("abd", "bad"));// 1
        System.out.println(sol.transform("GeeksForGeeks", "ForGeeksGeeks"));// 3
        System.out.println(sol.transform("abcd", "efgh"));// -1
        System.out.println(sol.transform("YUZKxQReJATCsD", "seCJQKZRTADUxY"));// 13
    }
}
