import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<Integer> search(String pat, String txt) {
        final int d = 256; // Number of characters in ASCII
        final int q = 101; // A large prime number for modulus

        int m = pat.length(); // Pattern length
        int n = txt.length(); // Text length
        List<Integer> ans = new ArrayList<>();

        if (m > n)
            return ans;

        int p = 0, t = 0, h = 1;

        // Calculate h = pow(d, m-1) % q
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Initial hash values for pattern and first window
        for (int i = 0; i < m; i++) {
            p = (d * p + pat.charAt(i)) % q;
            t = (d * t + txt.charAt(i)) % q;
        }

        // Slide the pattern over text
        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                if (txt.substring(i, i + m).equals(pat)) {
                    ans.add(i + 1); // 1-based index
                }
            }

            // Rolling hash update
            if (i < n - m) {
                t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + m)) % q;
                if (t < 0)
                    t += q;
            }
        }

        return ans;
    }
}

public class Seventeen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String txt = "kalhonahohoho";
        String pat = "ho";
        List<Integer> ans = sol.search(pat, txt);
        for (int i : ans) {
            System.out.print(i + " ");
        }
    }
}
