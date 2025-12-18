#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    void helper(int currRow, int currCol, int destRow, int destCol, vector<vector<bool>> &visited, string &route, vector<vector<int>> &maze, vector<string> &ans, vector<int> &dRow, vector<int> &dCol)
    {
        visited[currRow][currCol] = true;
        if (currRow == destRow && currCol == destCol)
        {
            ans.push_back(route);
        }
        for (int i = 0; i < 4; i++)
        {
            int newRow = currRow + dRow[i], newCol = currCol + dCol[i];
            if (newRow >= 0 && newCol >= 0 && newRow <= destRow && newCol <= destCol && maze[newRow][newCol] == 1 && visited[newRow][newCol] == false)
            {
                if (i == 0)
                {
                    route.push_back('D');
                }
                else if (i == 1)
                {
                    route.push_back('L');
                }
                else if (i == 2)
                {
                    route.push_back('R');
                }
                else if (i == 3)
                {
                    route.push_back('U');
                }
                helper(newRow, newCol, destRow, destCol, visited, route, maze, ans, dRow, dCol);
                route.pop_back();
            }
        }
        visited[currRow][currCol] = false;
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> ans;
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        {
            return ans;
        }
        vector<int> dRow = {1, 0, 0, -1}, dCol = {0, -1, 1, 0};
        string route = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        helper(0, 0, n - 1, n - 1, visited, route, maze, ans, dRow, dCol);
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
    maze = {{1, 0}, {1, 0}};
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
