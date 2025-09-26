#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minFlips(string &s)
    {
        int ans1 = 0, ans2 = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 && s[i] == '0')
                ++ans1;
            else if (i % 2 != 0 && s[i] == '1')
                ++ans1;
            else if (i % 2 == 0 && s[i] == '1')
                ++ans2;
            else if (i % 2 != 0 && s[i] == '0')
                ++ans2;
        }
        return min(ans1, ans2);
    }
};
int main()
{
    Solution sol;
    string s = "001";
    cout << sol.minFlips(s) << "\n";
    s = "0001010111";
    cout << sol.minFlips(s) << "\n";
    return 0;
}
