#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{

public:
    vector<int> search(string &pat, string &txt)
    {
        const int d = 256;    // Number of characters in input alphabet (ASCII)
        const int q = 101;    // A large prime number used as modulus to minimize hash collisions
        int m = pat.length(); // Pattern length
        int n = txt.length(); // Text length
        vector<int> ans;      // To store the 1-based positions of matches
        int p = 0, t = 0, h = 1;
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;
        for (int i = 0; i < m; i++)
        {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }
        // Slide the pattern over text
        for (int i = 0; i <= n - m; i++)
        {
            if (p == t)
            {
                // Confirm match character by character
                if (txt.substr(i, m) == pat)
                    ans.push_back(i + 1); // 1-based index
            }

            // Calculate hash for next window
            if (i < n - m)
            {
                t = (d * (t - txt[i] * h) + txt[i + m]) % q;

                if (t < 0)
                    t += q;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string txt = "kalhonahohoho", pat = "ho";
    vector<int> ans = sol.search(pat, txt);
    for (int i : ans)
        cout << i << " ";
    return 0;
}
