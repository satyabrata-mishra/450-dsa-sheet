#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> movement = {
        {1, 0}, // D
        {0, 1}, // R
    };
    void dfs(int cRow, int cCol, int dRow, int dCol, vector<vector<int>> &ans, vector<int> &travelled, vector<vector<int>> &grid)
    {
        if (cRow == dRow && cCol == dCol)
        {
            ans.push_back(travelled);
            return;
        }
        int temp = grid[cRow][cCol];
        grid[cRow][cCol] = -1;
        for (int i = 0; i < movement.size(); i++)
        {
            int nRow = cRow + movement[i][0];
            int nCol = cCol + movement[i][1];
            if (nRow >= 0 && nRow <= dRow && nCol >= 0 && nCol <= dCol && grid[nRow][nCol] != -1)
            {
                travelled.push_back(grid[nRow][nCol]);
                dfs(nRow, nCol, dRow, dCol, ans, travelled, grid);
                travelled.pop_back();
            }
        }
        grid[cRow][cCol] = temp;
    }

public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> travelled;
        travelled.push_back(grid[0][0]);
        dfs(0, 0, n - 1, m - 1, ans, travelled, grid);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    grid = sol.findAllPossiblePaths(grid.size(), grid[0].size(), grid);
    for (vector<int> i : grid)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    grid = {{1, 2}, {3, 4}};
    grid = sol.findAllPossiblePaths(grid.size(), grid[0].size(), grid);
    for (vector<int> i : grid)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
