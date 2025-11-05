#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// Bad Character Heuristic
void badCharHeuristic(const string &pat, vector<int> &badChar)
{
    int m = pat.size();
    const int CHARSET_SIZE = 256; // ASCII characters
    badChar.assign(CHARSET_SIZE, -1);
    for (int i = 0; i < m; i++)
        badChar[(int)pat[i]] = i;
}
vector<int> patterMatching1(string &txt, string &pat)
{
    int txtLen = txt.size(), patLen = pat.size();
    vector<int> badChar;
    badCharHeuristic(pat, badChar);
    vector<int> ans;
    int i = 0;
    while (i <= txtLen - patLen)
    {
        int j = patLen - 1;
        while (j >= 0 && pat[j] == txt[i + j])
        {
            --j;
        }
        if (j < 0)
        {
            ans.push_back(i);
            i += (i + patLen < txtLen) ? patLen - badChar[(int)txt[i + patLen]] : 1;
        }
        else
        {
            i += max(1, j - badChar[(int)txt[i + j]]);
        }
    }

    return ans;
}
int main()
{
    string txt = "AABAACAADAABAABA", pat = "AABA";
    vector<int> ans = patterMatching1(txt, pat);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    txt = "THIS IS A TEST TEXT", pat = "TEST";
    ans = patterMatching1(txt, pat);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
