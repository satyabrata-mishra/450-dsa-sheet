#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        int startRow = 0, endRow = mat.size() - 1, startCol = 0, endCol = mat[0].size() - 1;
        vector<int> ans;
        while (startRow <= endRow && startCol <= endCol)
        {
            for (int i = startCol; i <= endCol; i++)
            {
                ans.push_back(mat[startRow][i]);
            }
            for (int i = startRow + 1; i <= endRow; i++)
            {
                ans.push_back(mat[i][endCol]);
            }
            for (int i = endCol - 1; i >= startCol; i--)
            {
                if (startRow == endRow)
                {
                    break;
                }
                ans.push_back(mat[endRow][i]);
            }
            for (int i = endRow - 1; i >= startRow + 1; i--)
            {
                if (startCol == endCol)
                {
                    break;
                }
                ans.push_back(mat[i][startCol]);
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Solution sol;
    vector<int> ans = sol.spirallyTraverse(arr);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10