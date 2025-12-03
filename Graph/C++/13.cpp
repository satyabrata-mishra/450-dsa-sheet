#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<vector<int>> createAdjacencyList(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjacencyList(v, vector<int>());
        for (vector<int> i : edges)
        {
            adjacencyList[i[0]].push_back(i[1]);
        }
        return adjacencyList;
    }
    void dfs(int src, vector<vector<int>> &adjacencyList, vector<bool> &visited, stack<int> &st)
    {
        visited[src] = true;
        for (int neighbour : adjacencyList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adjacencyList, visited, st);
            }
        }
        st.push(src);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjacencyList = createAdjacencyList(V, edges);
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjacencyList, visited, st);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    vector<int> ans = sol.topoSort(4, edges);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
