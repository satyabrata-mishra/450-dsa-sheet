#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    bool found = false;
    void dfs(int src, int parent, int &timer, vector<vector<int>> &adjacencyList, vector<int> &visited, vector<int> &intime, vector<int> &lowtime, int c, int d)
    {
        visited[src] = 1;
        intime[src] = lowtime[src] = timer++;
        for (int neighbour : adjacencyList[src])
        {
            if (neighbour == parent)
            {
                continue;
            }
            if (visited[neighbour] == 0)
            {
                dfs(neighbour, src, timer, adjacencyList, visited, intime, lowtime, c, d);
                lowtime[src] = min(lowtime[src], lowtime[neighbour]);
                if (lowtime[neighbour] > intime[src])
                {
                    if ((src == c && neighbour == d) || (src == d && neighbour == c))
                    {
                        found = true;
                    }
                }
            }
            else
            {
                lowtime[src] = min(lowtime[src], intime[neighbour]);
            }
        }
    };

public:
    bool isBridge(int v, vector<vector<int>> &edges, int c, int d)
    {
        vector<vector<int>> adjacencyList(v, vector<int>());
        vector<int> visited(v, 0), time(v, 0), low(v, 0);
        int timer = 0;
        for (vector<int> i : edges)
        {
            adjacencyList[i[0]].push_back(i[1]);
            adjacencyList[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, -1, timer, adjacencyList, visited, time, low, c, d);
            }
        }
        return found;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    cout << sol.isBridge(4, edges, 1, 2) << "\n"; // 1
    edges = {{0, 1}, {0, 3}, {1, 2}, {2, 0}, {3, 4}};
    cout << sol.isBridge(5, edges, 0, 2) << "\n"; // 0
    return 0;
}
