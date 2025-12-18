#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size(), m = grid[0].size();
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = p.first + delrow, ncol = p.second + delcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 'L' && visited[nrow][ncol] == 0)
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int countIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 'L')
                {
                    ++count;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> grid = {{'L', 'L', 'W', 'W', 'W'},
                                 {'W', 'L', 'W', 'W', 'L'},
                                 {'L', 'W', 'W', 'L', 'L'},
                                 {'W', 'W', 'W', 'W', 'W'},
                                 {'L', 'W', 'L', 'L', 'W'}};
    cout << sol.countIslands(grid) << "\n";
    return 0;
}
