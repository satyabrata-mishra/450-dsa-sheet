#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
private:
    void dfsWithStack(int src, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
    {
        visited[src] = true;
        for (int neighbour : adj[src])
        {
            if (!visited[neighbour])
            {
                dfsWithStack(neighbour, adj, visited, st);
            }
        }
        st.push(src);
    }
    void dfs(int src, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[src] = true;
        for (int neighbour : adj[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adj, visited);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<bool> visited(v, false);
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfsWithStack(i, adj, visited, st);
            }
        }
        // Reverse the graph
        vector<vector<int>> revAdjList(v, vector<int>());
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            for (int j : adj[i])
            {
                revAdjList[j].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                ++scc;
                dfs(node, revAdjList, visited);
            }
        }
        return scc;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};
    cout << sol.kosaraju(adj) << "\n";
    adj = {{1}, {2}, {0}};
    cout << sol.kosaraju(adj) << "\n";
    return 0;
};
