#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adj, visited);
            }
        }
    }

public:
    int isTree(int n, int m, vector<vector<int>> &edges)
    {
        // Condition 1: Tree must have exactly n-1 edges
        if (m != n - 1)
            return 0;
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        dfs(0, adj, visited);
        // Condition 2: Graph must be connected
        for (bool v : visited)
        {
            if (!v)
                return 0;
        }
        return 1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> adj = {{0, 1}, {1, 2}, {1, 3}};
    cout << sol.isTree(4, 3, adj) << "\n";
    adj = {{0, 1}, {1, 2}, {2, 0}};
    cout << sol.isTree(4, 3, adj) << "\n";
    return 0;
}
