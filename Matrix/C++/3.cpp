#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int maxOnes = 0, index = -1, row = arr.size(), col = arr[0].size();
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < col; j++)
            {
                sum += arr[i][j];
            }
            if (sum > maxOnes)
            {
                maxOnes = sum;
                index = i;
            }
        }
        return index;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << sol.rowWithMax1s(arr) << "\n";
    arr = {{0, 0}, {0, 0}};
    cout << sol.rowWithMax1s(arr) << "\n";
    return 0;
}
