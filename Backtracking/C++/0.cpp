#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution
{
private:
    vector<vector<int>> movement = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // D L R U
    void dfs(int cRow, int cCol, int dRow, int dCol, vector<string> &ans, vector<vector<int>> &maze, string &direction)
    {
        if (cRow == dRow && cCol == dCol)
        {
            ans.push_back(direction);
            return;
        }
        int temp = maze[cRow][cCol];
        maze[cRow][cCol] = -1;
        for (int i = 0; i < 4; i++)
        {
            int nRow = movement[i][0] + cRow;
            int nCol = movement[i][1] + cCol;
            if (nRow >= 0 && nRow <= dRow && nCol >= 0 && nCol <= dCol && maze[nRow][nCol] == 1)
            {
                if (i == 0)
                {
                    direction.push_back('D');
                }
                else if (i == 1)
                {
                    direction.push_back('L');
                }
                else if (i == 2)
                {
                    direction.push_back('R');
                }
                else
                {
                    direction.push_back('U');
                }
                dfs(nRow, nCol, dRow, dCol, ans, maze, direction);
                direction.pop_back();
            }
        }
        maze[cRow][cCol] = temp;
    };

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        if (maze[0][0] == 0)
        {
            return {};
        }
        int n = maze.size();
        vector<string> ans;
        string direction = "";
        dfs(0, 0, n - 1, n - 1, ans, maze, direction);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = sol.ratInMaze(maze);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    maze = {{1, 0}, {0, 1}};
    ans = sol.ratInMaze(maze);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    maze = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    ans = sol.ratInMaze(maze);
    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
