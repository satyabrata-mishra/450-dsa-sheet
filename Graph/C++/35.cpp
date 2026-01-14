#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findPath(vector<vector<pair<int, int>>> &adj,
                  int src, int k, vector<bool> &visited)
    {

        if (k <= 0)
            return true;

        for (auto &p : adj[src])
        {
            int node = p.first;
            int weight = p.second;

            if (visited[node])
                continue;

            visited[node] = true;
            if (findPath(adj, node, k - weight, visited))
                return true;

            visited[node] = false; // backtrack
        }
        return false;
    }

    bool pathMoreThanK(int v, int e, int k, int *a)
    {
        vector<vector<pair<int, int>>> adj(v);

        // Build undirected graph
        for (int i = 0; i < e * 3; i += 3)
        {
            int u = a[i];
            int vtx = a[i + 1];
            int wt = a[i + 2];

            adj[u].push_back({vtx, wt});
            adj[vtx].push_back({u, wt});
        }

        vector<bool> visited(v, false);
        visited[0] = true;

        return findPath(adj, 0, k, visited);
    }
};
int main()
{
    Solution sol;

    int a1[] = {0, 1, 5, 1, 2, 1, 2, 3, 1};
    cout << sol.pathMoreThanK(4, 3, 8, a1) << endl; // 0

    int a2[] = {
        0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 11,
        2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9,
        3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1,
        6, 8, 6, 7, 8, 7};
    cout << sol.pathMoreThanK(9, 14, 60, a2) << endl; // 0
    return 0;
}
