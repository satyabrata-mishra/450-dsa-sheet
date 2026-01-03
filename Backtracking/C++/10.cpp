#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
private:
    vector<vector<int>> movement = {
        {-1, 0}, // U
        {0, +1}, // R
        {+1, 0}, // D
        {0, -1}  // L
    };
    void markUnsafe(vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> temp = mat;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (temp[i][j] == 0)
                {
                    mat[i][j] = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + movement[k][0];
                        int nj = j + movement[k][1];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                            mat[ni][nj] = 0;
                    }
                }
            }
        }
    }

public:
    int findShortestPath(vector<vector<int>> mat)
    {

        int r = mat.size(), c = mat[0].size();
        markUnsafe(mat);
        queue<pair<int, int>> q;
        vector<vector<int>> dist(r, vector<int>(c, -1));
        for (int i = 0; i < r; i++)
        {
            if (mat[i][0] == 1)
            {
                q.push({i, 0});
                dist[i][0] = 0;
            }
        }
        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            if (temp.second == c - 1)
            {
                return dist[temp.first][temp.second] + 1;
            }
            for (int i = 0; i < movement.size(); i++)
            {
                int nRow = movement[i][0] + temp.first;
                int nCol = movement[i][1] + temp.second;
                if (nRow >= 0 && nRow < r && nCol >= 0 && nCol < c && mat[nRow][nCol] == 1 && dist[nRow][nCol] == -1)
                {
                    dist[nRow][nCol] = dist[temp.first][temp.second] + 1;
                    q.push({nRow, nCol});
                }
            }
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    cout << sol.findShortestPath({{1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 0, 1}, {1, 1, 1, 1, 0}}) << "\n"; // 6
    cout << sol.findShortestPath({{1, 1, 1, 1, 1}, {1, 1, 0, 1, 1}, {1, 1, 1, 1, 1}}) << "\n";                                   // -1
    return 0;
}
