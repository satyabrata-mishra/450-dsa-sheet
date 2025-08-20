#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int minVal = INT32_MAX, maxVal = INT32_MIN, rSize = mat.size(), cSize = mat[0].size();
        for (vector<int> i : mat)
        {
            minVal = min(minVal, i[0]);
            maxVal = max(maxVal, i[cSize - 1]);
        }
        while (minVal < maxVal)
        {
            int mid = minVal + (maxVal - minVal) / 2;
            int nosLessThanMid = 0;
            for (vector<int> i : mat)
            {
                for (int j : i)
                {
                    if (j <= mid)
                        nosLessThanMid++;
                    else
                        break;
                }
            }
            if (nosLessThanMid <= k - 1)
                minVal = mid + 1;
            else
                maxVal = mid;
        }
        return minVal;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> mat = {{16, 28, 60, 64},
                               {22, 41, 63, 91},
                               {27, 50, 87, 93},
                               {36, 78, 87, 94}};
    cout << sol.kthSmallest(mat, 3) << "\n"; // 27
    mat = {{10, 20, 30, 40},
           {15, 25, 35, 45},
           {24, 29, 37, 48},
           {32, 33, 39, 50}};
    cout << sol.kthSmallest(mat, 7) << "\n"; // 30
    return 0;
}
