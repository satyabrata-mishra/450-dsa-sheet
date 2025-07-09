#include <iostream>
using namespace std;
class Solution
{
public:
    int countSquares(int n)
    {
        int ans = 0, ind = 1;
        long mult = 1;
        while (mult < n)
        {
            mult = ind * ind;
            ++ans;
            ++ind;
        }
        return ans - 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.countSquares(9) << "\n";
    cout << sol.countSquares(3) << "\n";
    return 0;
}
