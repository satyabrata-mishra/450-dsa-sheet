#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dist(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            for (vector<int> i : edges)
            {
                int u = i[0], v = i[1], w = i[2];
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (vector<int> i : edges)
        {
            int u = i[0], v = i[1], w = i[2];
            if (dist[u] + w < dist[v])
            {
                return 1;
            }
        }
        return 0;
    }
};
int main()
{
    Solution sol;
    int n = 3;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
    cout << sol.isNegativeWeightCycle(n, edges) << "\n"; // 1
    n = 3;
    edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, 3}};
    cout << sol.isNegativeWeightCycle(n, edges) << "\n"; // 0
    return 0;
}
