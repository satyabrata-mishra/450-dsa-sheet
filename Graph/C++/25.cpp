#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> board)
    {
        int n = board.size();
        vector<int> arr(n * n + 1, -1);
        int idx = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (leftToRight)
            {
                for (int j = 0; j < n; j++)
                    arr[idx++] = board[i][j];
            }
            else
            {
                for (int j = n - 1; j >= 0; j--)
                    arr[idx++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }

        queue<pair<int, int>> q; // {position, steps}
        vector<bool> visited(n * n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty())
        {
            int curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (curr == n * n)
                return steps;
            for (int dice = 1; dice <= 6; dice++)
            {
                int next = curr + dice;
                if (next > n * n)
                    break;

                if (arr[next] != -1)
                    next = arr[next];

                if (!visited[next])
                {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1}, {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    cout << sol.snakesAndLadders(board) << "\n"; // 4
    board = {{-1, -1}, {-1, 3}};
    cout << sol.snakesAndLadders(board) << "\n"; // 1
    return 0;
}
