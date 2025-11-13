#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string smallestNumber(int s, int d)
    {
        if (s > 9 * d)
        {
            return "-1";
        }
        vector<int> digits(d, 0);
        --s;
        for (int i = d - 1; i > 0; i--)
        {
            if (s > 9)
            {
                digits[i] = 9;
                s -= 9;
            }
            else
            {
                digits[i] = s;
                s = 0;
            }
        }
        digits[0] = 1 + s;
        string ans = "";
        for (int i : digits)
        {
            ans += to_string(i);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.smallestNumber(9, 2) << "\n";
    cout << sol.smallestNumber(20, 3) << "\n";
    return 0;
}
