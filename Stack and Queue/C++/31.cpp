#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        while (q.empty() == false)
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int currX = curr.first + dx[j], currY = curr.second + dy[j];
                if (currX >= 0 && currX < row && currY >= 0 && currY < col && ans[currX][currY] == -1)
                {
                    ans[currX][currY] = ans[curr.first][curr.second] + 1;
                    q.push({currX, currY});
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0},
                                {1, 1, 0, 0},
                                {0, 0, 1, 1}};
    Solution sol;
    grid = sol.nearest(grid);
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
