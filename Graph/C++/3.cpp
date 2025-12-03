#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    void dfsHelper(int node, vector<vector<int>> &adj, vector<bool> &visted, vector<int> &ans)
    {
        ans.push_back(node);
        visted[node] = true;
        for (int neighbour : adj[node])
        {
            if (!visted[neighbour])
            {
                dfsHelper(neighbour, adj, visted, ans);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        int noOfVertices = adj.size();
        vector<bool> visited(noOfVertices, false);
        for (int i = 0; i < noOfVertices; i++)
        {
            if (!visited[i])
            {
                dfsHelper(i, adj, visited, ans);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = sol.dfs(adj);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
