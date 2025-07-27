#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPowerofTwo(int n)
    {
        return (n & n - 1) == 0;
    }
};
int main()
{
    Solution sol;
    cout << sol.isPowerofTwo(8) << "\n";
    cout << sol.isPowerofTwo(98) << "\n";
    cout << sol.isPowerofTwo(1) << "\n";
    return 0;
}
