#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int helperMediam(vector<int> &a, vector<int> &b, bool toogle)
    {
        int n = a.size();
        int low = min(a[0], b[0]), high = max(a[n - 1], b[n - 1]);
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i : a)
            {
                if (i <= mid)
                    count++;
                else
                    break;
            }
            for (int i : b)
            {
                if (i <= mid)
                    count++;
                else
                    break;
            }
            if (toogle && count < n)
            {
                low = mid + 1;
            }
            else if (!toogle && count <= n)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

public:
    double medianOf2(vector<int> &a, vector<int> &b)
    {
        return ((double)helperMediam(a, b, true) + helperMediam(a, b, false)) / 2;
    }
};
int main()
{
    Solution sol;
    vector<int> a = {-5, 3, 6, 12, 15}, b = {-12, -10, -6, -3, 4};
    cout << sol.medianOf2(a, b) << "\n"; // 0
    a = {2, 3, 5, 7}, b = {10, 12, 14, 16};
    cout << sol.medianOf2(a, b) << "\n"; // 8.5
    a = {-5}, b = {-6};
    cout << sol.medianOf2(a, b) << "\n"; //-5.5
    return 0;
}
