#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool areIsomorphic(string &s1, string &s2)
    {
        if (s1.size() != s2.size())
            return false;
        int mapS[26] = {0}, mapT[26] = {0};
        for (int i = 0; i < s1.size(); i++)
        {
            if (mapS[s1[i] - 'a'] != mapT[s2[i] - 'a'])
                return false;
            mapS[s1[i] - 'a'] = i + 1;
            mapT[s2[i] - 'a'] = i + 1;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    string s1 = "aab", s2 = "xxy";
    // cout << sol.areIsomorphic(s1, s2) << "\n";
    s1 = "jmpdwrd", s2 = "tglkqyk";
    cout << sol.areIsomorphic(s1, s2) << "\n";
    return 0;
}
