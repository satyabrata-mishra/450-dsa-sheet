#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
private:
    vector<vector<pair<int, int>>> createAdjacencyList(vector<vector<int>> edges, int v)
    {
        vector<vector<pair<int, int>>> adjacencyList(v, vector<pair<int, int>>());
        for (vector<int> i : edges)
        {
            adjacencyList[i[0]].push_back({i[1], i[2]});
        }
        return adjacencyList;
    }
    void topologicalSort(int src, vector<vector<pair<int, int>>> &adjacencyList, vector<int> &visited, stack<int> &st)
    {
        visited[src] = 1;
        for (pair<int, int> neighbour : adjacencyList[src])
        {
            if (visited[neighbour.first] == 0)
            {
                topologicalSort(neighbour.first, adjacencyList, visited, st);
            }
        }
        st.push(src);
    }

public:
    vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
    {
        vector<vector<pair<int, int>>> adjacencyList = createAdjacencyList(edges, v);
        vector<int> visited(v, 0);
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                topologicalSort(i, adjacencyList, visited, st);
            }
        }
        vector<int> dist(v, INT32_MIN);
        dist[src] = 0;
        while (st.empty() == false)
        {
            int curr = st.top();
            st.pop();
            if (dist[curr] != INT32_MIN)
            {
                for (pair<int, int> neighbour : adjacencyList[curr])
                {
                    if (dist[curr] + neighbour.second > dist[neighbour.first])
                    {
                        dist[neighbour.first] = dist[curr] + neighbour.second;
                    }
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {3, 5, 1}, {3, 4, -1}, {4, 5, -2}};
    vector<int> ans = sol.maximumDistance(edges, 6, edges.size(), 1);
    for (int i : ans)
    {
        cout << i << " "; // INF,0,2,9,8,10
    }
    return 0;
}
