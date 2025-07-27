#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void helper(string &s, string temp, int index, vector<string> &ans)
    {
        if (s.length() == index)
        {
            if (temp.length() != 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        helper(s, temp, index + 1, ans);
        helper(s, temp + s[index], index + 1, ans);
    }

public:
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> ans;
        helper(s, "", 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> ans = sol.AllPossibleStrings("abc");
    for (string i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
