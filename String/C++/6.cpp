#include <iostream>
using namespace std;
class Solution
{
public:
    string count(string n)
    {
        string ans = "";
        char curCh = n[0];
        int count = 1;
        for (int i = 1; i < n.size(); i++)
        {
            if (n[i] == curCh)
            {
                count++;
            }
            else
            {
                ans += to_string(count) + curCh;
                curCh = n[i];
                count = 1;
            }
        }
        ans += to_string(count) + curCh;
        return ans;
    }

public:
    string countAndSay(int n)
    {
        string ans = "1";
        while (--n)
        {
            ans = count(ans);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.countAndSay(4) << "\n";
    cout << sol.countAndSay(1) << "\n";
    return 0;
}
