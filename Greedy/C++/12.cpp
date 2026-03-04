#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        if (M > N)
        {
            return -1;
        }
        if (S > 6 && (6 * N) - (7 * M) < 0)
        {
            return -1;
        }
        return (int)ceil(((double)S * M) / (double)N);
    }
};
int main()
{
    Solution sol;
    cout << sol.minimumDays(10, 16, 2) << "\n";  // 2
    cout << sol.minimumDays(10, 20, 30) << "\n"; // -1
    cout << sol.minimumDays(10, 9, 8) << "\n";   // -1
    return 0;
}
