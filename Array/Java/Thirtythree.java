import java.util.*;

class Solution {
    public int minMovesToMakePalindrome(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        int left = 0, right = n - 1, ans = 0;

        while (left < right) {

            int l = left, r = right;

            // find matching character from the right
            while (arr[l] != arr[r]) {
                r--;
            }

            // unique middle character case
            if (l == r) {
                char temp = arr[r];
                arr[r] = arr[r + 1];
                arr[r + 1] = temp;
                ans++;
                continue;
            } else {
                // bring matching character to the right position
                while (r < right) {
                    char temp = arr[r];
                    arr[r] = arr[r + 1];
                    arr[r + 1] = temp;
                    r++;
                    ans++;
                }
            }

            left++;
            right--;
        }
        return ans;
    }
}

public class Thirtythree {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minMovesToMakePalindrome("aabb")); // 2
        System.out.println(sol.minMovesToMakePalindrome("letelt")); // 2
    }
}
