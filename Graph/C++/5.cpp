#include <iostream>
#include <vector>
#include <queue>
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
            adjacencyList[i[1]].push_back(i[0]);
        }
        return adjacencyList;
    }
    bool BFSHelper(int src, vector<vector<int>> &adjacencyList, vector<bool> &visited, int v)
    {
        vector<int> parent(v, -1);
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (int neighbour : adjacencyList[temp])
            {
                if (!visited[neighbour])
                {
                    parent[neighbour] = temp;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
                else if (neighbour != parent[temp])
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool detectCycleUsingBFS(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjacencyList = createAdjacencyList(v, edges);
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (BFSHelper(i, adjacencyList, visited, v))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool DFSHelper(int src, int parent, vector<vector<int>> &adjacencyList, vector<bool> &visited, int v)
    {
        visited[src] = true;
        for (int neighbour : adjacencyList[src])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                if (DFSHelper(neighbour, src, adjacencyList, visited, v))
                {
                    return true;
                }
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool detectCycleUsingDFS(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjacencyList = createAdjacencyList(v, edges);
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (DFSHelper(i, -1, adjacencyList, visited, v))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        return detectCycleUsingBFS(V, edges);
        // return detectCycleUsingDFS(V, edges);
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << sol.isCycle(4, edges) << "\n";
    return 0;
}
