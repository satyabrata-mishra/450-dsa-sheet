#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
private:
    int highestPowerOfTwo(int n)
    {
        return log(n) / log(2);
    };

public:
    int countSetBits(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        int x = highestPowerOfTwo(n);
        return (pow(2, x - 1) * x) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x));
    }
};
int main()
{
    Solution sol;
    cout << sol.countSetBits(4) << "\n";
    cout << sol.countSetBits(17) << "\n";
    return 0;
}
