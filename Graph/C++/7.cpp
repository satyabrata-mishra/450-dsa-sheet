#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n)
    {
        int tx = targetPos[0] - 1, ty = targetPos[1] - 1;
        if (tx == knightPos[0] - 1 && ty == knightPos[1] - 1)
        {
            return 0;
        }
        vector<int> dRow = {-1, 1, 2, 2, 1, -1, -2, -2};
        vector<int> dCol = {2, 2, 1, -1, -2, -2, -1, 1};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({knightPos[0] - 1, knightPos[1] - 1});
        visited[knightPos[0] - 1][knightPos[1] - 1] = true;
        int ans = 0;
        while (!q.empty())
        {
            ++ans;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> index = q.front();
                q.pop();
                for (int i = 0; i < 8; i++)
                {
                    int nx = index.first + dRow[i];
                    int ny = index.second + dCol[i];
                    if (nx == tx && ny == ty)
                    {
                        return ans;
                    }
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    int n = 3;
    vector<int> knightPos = {3, 3}, targetPos = {1, 2};
    cout << sol.minStepToReachTarget(knightPos, targetPos, n) << "\n";
    n = 6;
    knightPos = {4, 5};
    targetPos = {1, 1};
    cout << sol.minStepToReachTarget(knightPos, targetPos, n) << "\n";
    return 0;
}
