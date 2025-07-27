#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> &Mat)
    {
        vector<int> arr;
        for (vector<int> i : Mat)
        {
            for (int j : i)
            {
                arr.push_back(j);
            }
        }
        sort(arr.begin(), arr.end());
        int r = Mat.size(), c = Mat[0].size(), index = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                Mat[i][j] = arr[index++];
            }
        }
        return Mat;
    }
};
int main()
{
    vector<vector<int>> arr = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}};
    Solution sol;
    arr = sol.sortedMatrix(arr.size(), arr);
    for (vector<int> i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
