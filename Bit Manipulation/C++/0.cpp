#include <iostream>
using namespace std;
class Solution
{
public:
    int setBits(int n)
    {
        int ans = 0;
        while (n > 1)
        {
            if (n % 2 == 1)
                ++ans;
            n /= 2;
        }
        if (n == 1)
            ++ans;
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.setBits(6) << "\n";
    cout << sol.setBits(8) << "\n";
    cout << sol.setBits(3) << "\n";
    return 0;
}
