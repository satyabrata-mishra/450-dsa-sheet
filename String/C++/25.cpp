#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    int romanToDecimal(string &s)
    {
        map<char, int> track;
        track['I'] = 1;
        track['V'] = 5;
        track['X'] = 10;
        track['L'] = 50;
        track['C'] = 100;
        track['D'] = 500;
        track['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (track[s[i]] < track[s[i + 1]])
            {
                ans += track[s[i + 1]] - track[s[i]];
                ++i;
            }
            else
            {
                ans += track[s[i]];
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string str = "IX";
    cout << sol.romanToDecimal(str) << "\n";
    str = "XL";
    cout << sol.romanToDecimal(str) << "\n";
    str = "MCMIV";
    cout << sol.romanToDecimal(str) << "\n";
    return 0;
}
