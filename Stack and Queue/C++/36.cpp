#include <string>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    string FirstNonRepeating(string &s)
    {
        int freq[26] = {0};
        string ans = "";
        queue<char> q;
        for (char i : s)
        {
            freq[i - 'a']++;
            if (freq[i - 'a'] == 1)
                q.push(i);
            while (!q.empty() && freq[q.front() - 'a'] != 1)
            {
                q.pop();
            }
            if (q.empty())
                ans += "#";
            else
                ans += q.front();
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "aabc";
    cout << sol.FirstNonRepeating(s) << "\n";
    s = "zz";
    cout << sol.FirstNonRepeating(s) << "\n";
    s = "bb";
    cout << sol.FirstNonRepeating(s) << "\n";
    return 0;
}
