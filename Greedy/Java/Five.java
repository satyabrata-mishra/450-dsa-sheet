import java.util.*;

class Solution {

    public String chooseandswap(String str) {
        int n = str.length();

        int[] last = new int[26];
        boolean[] visited = new boolean[26];

        // Initialize last occurrence
        Arrays.fill(last, -1);

        for (int i = 0; i < n; i++) {
            last[str.charAt(i) - 'a'] = i;
        }

        char[] arr = str.toCharArray();

        for (int i = 0; i < n; i++) {
            visited[arr[i] - 'a'] = true;

            for (char ch = 'a'; ch < arr[i]; ch++) {
                if (!visited[ch - 'a'] && last[ch - 'a'] > i) {

                    char c1 = arr[i];
                    char c2 = ch;

                    // Perform global swap
                    for (int j = 0; j < n; j++) {
                        if (arr[j] == c1)
                            arr[j] = c2;
                        else if (arr[j] == c2)
                            arr[j] = c1;
                    }
                    return new String(arr);
                }
            }
        }
        return str;
    }
}

public class Five {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.chooseandswap("ccad")); // aacd
        System.out.println(sol.chooseandswap("abba")); // abba
    }
}
