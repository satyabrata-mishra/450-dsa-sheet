#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> ans;
        int noOfVertices = adj.size();
        vector<bool> visited(noOfVertices, false);
        queue<int> q;
        q.push(0);
        ans.push_back(0);
        visited[0] = true;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (int neighbour : adj[temp])
            {
                if (!visited[neighbour])
                {
                    ans.push_back(neighbour);
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = sol.bfs(adj);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
