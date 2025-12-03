#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> distance(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            for (vector<int> j : edges)
            {
                int u = j[0], v = j[1], wt = j[2];
                if (distance[u] + wt < distance[v])
                {
                    distance[v] = distance[u] + wt;
                }
            }
        }
        for (vector<int> j : edges)
        {
            int u = j[0], v = j[1], wt = j[2];
            if (distance[u] + wt < distance[v])
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
