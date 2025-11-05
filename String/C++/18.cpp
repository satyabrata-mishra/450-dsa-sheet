#include <string>
#include <iostream>
#include <vector>
using namespace std;
// KMP ALGORITHM
class Solution
{
public:
    vector<int> getLPSLength(string &s)
    {
        int n = s.length();
        vector<int> lps(n, 0);
        int pre = 0, suf = 1;
        while (suf < n)
        {
            if (s[pre] == s[suf])
            {
                lps[suf++] = ++pre;
            }
            else
            {
                lps[suf] = 0;
                if (pre != 0)
                {
                    pre = lps[pre - 1];
                }
                else
                {
                    ++suf;
                }
            }
        }
        return lps;
    }
    vector<int> search(string &pat, string &txt)
    {
        int patL = pat.size(), txtL = txt.size();
        int iP = 0, iT = 0;
        vector<int> lpsT = getLPSLength(pat);
        vector<int> ans;
        while (iT < txtL)
        {
            if (pat[iP] == txt[iT])
            {
                ++iP;
                ++iT;
            }
            if (iP == patL)
            {
                ans.push_back(iT - iP);
                iP = lpsT[iP - 1];
            }
            else if (iT < txtL && pat[iP] != txt[iT])
            {
                if (iP != 0)
                {
                    iP = lpsT[iP - 1];
                }
                else
                {
                    ++iT;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string txt = "abcab", pat = "ab";
    vector<int> ans = sol.search(pat, txt); // 0 3
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    txt = "aabaacaadaabaaba";
    pat = "aaba";
    ans = sol.search(pat, txt); // 0 9 12
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    txt = "abesdu";
    pat = "edu";
    ans = sol.search(pat, txt); // []
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
