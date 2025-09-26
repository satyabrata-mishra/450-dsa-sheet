#include <iostream>
using namespace std;
class Solution
{
public:
    int inSequence(int a, int b, int c)
    {
        if (c == 0)
            return a == b ? 1 : 0;
        return ((b - a) % c == 0) && ((b - a) / c >= 0) ? 1 : 0;
    }
};
int main()
{
    Solution sol;
    cout << sol.inSequence(1, 3, 2) << "\n";
    cout << sol.inSequence(1, 2, 3) << "\n";
    cout << sol.inSequence(1, 2, 4) << "\n";
    return 0;
}
