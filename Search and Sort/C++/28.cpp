#include <iostream>
using namespace std;
class Solution
{
private:
    // Count no of trailing zeros in x!
    int countZeros(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n /= 5;
            count += n;
        }
        return count;
    }

public:
    int findNum(int n)
    {
        int low = 0, high = 5 * n, ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int noOfZeros = countZeros(mid);
            if (noOfZeros >= n)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.findNum(6) << "\n";
    cout << sol.findNum(1) << "\n";
    return 0;
}
