#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<vector<int>> createAdjacencyList(vector<vector<int>> &edges, int v)
    {
        vector<vector<int>> adjacencyList(v, vector<int>());
        for (vector<int> i : edges)
        {
            adjacencyList[i[0]].push_back(i[1]);
        }
        return adjacencyList;
    }
    bool dfsCheck(int src, vector<vector<int>> &adjacencyList, vector<bool> &visited, vector<bool> &pathVisited)
    {
        visited[src] = true;
        pathVisited[src] = true;
        for (int neighbour : adjacencyList[src])
        {
            if (!visited[neighbour])
            {
                if (dfsCheck(neighbour, adjacencyList, visited, pathVisited))
                {
                    return true;
                }
            }
            else if (pathVisited[neighbour])
            {
                return true;
            }
        }
        pathVisited[src] = false;
        return false;
    }
    bool checkCycleUsingDFS(vector<vector<int>> &edges, int v)
    {
        vector<bool> visited(v, false), pathVisited(v, false);
        vector<vector<int>> adjacencyList = createAdjacencyList(edges, v);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfsCheck(i, adjacencyList, visited, pathVisited))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        return checkCycleUsingDFS(edges, V);
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    cout << sol.isCyclic(4, edges) << "\n"; // 1
    edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    cout << sol.isCyclic(4, edges) << "\n"; // 0
    return 0;
}
