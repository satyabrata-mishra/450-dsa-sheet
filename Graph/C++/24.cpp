#include <vector>
#include <iostream>
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
            adjacencyList[i[1]].push_back(i[0]);
        }
        return adjacencyList;
    }
    bool dfs(int src, vector<vector<int>> &adjacencyList, vector<int> &color, int maxColor)
    {
        for (int clr = 0; clr < maxColor; clr++)
        {
            bool canUse = true;
            for (int neighbour : adjacencyList[src])
            {
                if (color[neighbour] == clr)
                {
                    canUse = false;
                    break;
                }
            }
            if (canUse)
            {
                color[src] = clr;
                for (int neighbour : adjacencyList[src])
                {
                    if (color[neighbour] == -1)
                    {
                        if (dfs(neighbour, adjacencyList, color, maxColor) == false)
                        {
                            color[src] = -1;
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }

public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adjacencyList = createAdjacencyList(edges, v);
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, adjacencyList, color, m) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};
    cout << sol.graphColoring(4, edges, 3) << "\n"; // true
    edges = {{0, 1}, {1, 2}, {0, 2}};
    cout << sol.graphColoring(3, edges, 2) << "\n"; // false
    return 0;
}
