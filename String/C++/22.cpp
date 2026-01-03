#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
private:
    vector<int> delRow = {-1, 0, 1, 0}, delCol = {0, 1, 0, -1};
    void dfs(vector<vector<char>> &mat, string &target, int targetSize, int cRow, int cCol, int rSize, int cSize, int index, int &ans)
    {
        if (index == targetSize)
        {
            ++ans;
        }
        int temp = mat[cRow][cCol];
        mat[cRow][cCol] = '#';
        for (int i = 0; i < 4; i++)
        {
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];
            if (nRow >= 0 && nRow < rSize && nCol >= 0 && nCol < cSize && mat[nRow][nCol] == target[index])
            {
                dfs(mat, target, targetSize, nRow, nCol, rSize, cSize, index + 1, ans);
            }
        }
        mat[cRow][cCol] = temp;
    }

public:
    int findOccurrence(vector<vector<char>> mat, string target)
    {
        int rSize = mat.size(), cSize = mat[0].size(), targetSize = target.size(), ans = 0;
        for (int i = 0; i < rSize; i++)
        {
            for (int j = 0; j < cSize; j++)
            {
                if (mat[i][j] == target[0])
                {
                    dfs(mat, target, targetSize, i, j, rSize, cSize, 1, ans);
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.findOccurrence({{'S', 'N', 'B', 'S', 'N'}, {'B', 'A', 'K', 'E', 'A'}, {'B', 'K', 'B', 'B', 'K'}, {'S', 'E', 'B', 'S', 'E'}}, "SNAKES") << "\n"; // 3
    cout << sol.findOccurrence({{'c', 'a', 't'}, {'a', 't', 'c'}, {'c', 't', 'a'}}, "cat") << "\n";                                                             // 5
    return 0;
}
