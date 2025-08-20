#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int median(vector<vector<int>> &mat)
    {
        int minVal = INT32_MAX, maxVal = INT32_MIN, rSize = mat.size(), cSize = mat[0].size();
        for (vector<int> i : mat)
        {
            minVal = min(minVal, i[0]);
            maxVal = max(maxVal, i[cSize - 1]);
        }
        int median = (rSize * cSize + 1) / 2;
        while (minVal < maxVal)
        {
            int mid = minVal + (maxVal - minVal) / 2;
            int nosLessThanMid = 0;
            for (const auto &row : mat)
            {
                for (int val : row)
                {
                    if (val <= mid)
                        nosLessThanMid++;
                    else
                        break; // since rows are sorted, we can stop early
                }
            }
            if (nosLessThanMid < median)
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
    vector<vector<int>> arr = {{1, 3, 5},
                               {2, 6, 9},
                               {3, 6, 9}};
    cout << sol.median(arr) << "\n";
    arr = {{2, 4, 9},
           {3, 6, 7},
           {4, 7, 10}};
    cout << sol.median(arr) << "\n";
    arr = {{3},
           {4},
           {8}};
    cout << sol.median(arr) << "\n";
    return 0;
}
