#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{

public:
    int countBitsFlip(int a, int b)
    {
        int x = a ^ b;
        int ans = 0;
        while (x > 0)
        {
            ans += (x & 1);
            x >>= 1;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.countBitsFlip(10, 20) << "\n"; // 4
    cout << sol.countBitsFlip(20, 25) << "\n"; // 3
    cout << sol.countBitsFlip(34, 7) << "\n";  // 3
    return 0;
}
