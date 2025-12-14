#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][via] == 100000000 || dist[via][j] == 100000000)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> dist = {{0, 4, 100000000, 5, 100000000}, {100000000, 0, 1, 100000000, 6}, {2, 100000000, 0, 3, 100000000}, {100000000, 100000000, 1, 0, 2}, {1, 100000000, 100000000, 4, 0}};
    sol.floydWarshall(dist);
    for (vector<int> i : dist)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
