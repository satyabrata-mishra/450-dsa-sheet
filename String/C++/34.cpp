#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<int> lpsCalculation(string &s)
    {
        int n = s.size();
        vector<int> lps(n, 0);
        int pre = 0, suf = 1;
        while (suf < n)
        {
            if (s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                ++pre;
                ++suf;
            }
            else
            {
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

public:
    int minChar(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + "$" + rev;
        vector<int> lps = lpsCalculation(str);
        return s.size() - lps[str.size() - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.minChar("abc") << "\n";
    cout << sol.minChar("aacecaaaa") << "\n";
    return 0;
}
