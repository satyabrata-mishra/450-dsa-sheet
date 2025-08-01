#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    void helper(string &str, string &ans, int ind)
    {
        if (ind >= str.size())
            return;
        ans += str[ind];
        while (ind + 1 < str.size() && str[ind] == str[ind + 1])
            ind++;
        helper(str, ans, ind + 1);
    }
    string removeConsecutiveCharacter(string &s)
    {
        string ans = "";
        helper(s, ans, 0);
        return ans;
    }
};
int main()
{
    Solution sol;
    string str = "aabb";
    cout << sol.removeConsecutiveCharacter(str) << "\n";
    str = "aabaa";
    cout << sol.removeConsecutiveCharacter(str) << "\n";
    str = "dorbsaszgmutcmmm";
    cout << sol.removeConsecutiveCharacter(str) << "\n";
    return 0;
}
