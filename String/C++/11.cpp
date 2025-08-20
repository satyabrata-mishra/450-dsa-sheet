#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int maxSubStr(string str)
    {
        int count = 0, ans = 0;
        for (char i : str)
        {
            if (i == '0')
                ++count;
            else
                --count;
            if (count == 0)
                ++ans;
        }
        return (count == 0) ? ans : -1;
    }
};

int main()
{
    Solution sol;
    string str = "0100110101";
    cout << sol.maxSubStr(str) << "\n";
    str = "001110010";
    cout << sol.maxSubStr(str) << "\n";
    return 0;
}
