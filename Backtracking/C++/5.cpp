#include <iostream>
#include <vector>
#include <queue>
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
    bool graphColoringHelper(int start, vector<int> &color, vector<vector<int>> &adjacencyList, int maxColors)
    {
        for (int c = 0; c < maxColors; c++)
        {
            bool canUse = true;
            for (int neighbors : adjacencyList[start])
            {
                if (color[neighbors] == c)
                {
                    canUse = false;
                    break;
                }
            }
            if (canUse == true)
            {
                color[start] = c;
                for (int neighbor : adjacencyList[start])
                {
                    if (color[neighbor] == -1)
                    {
                        if (graphColoringHelper(neighbor, color, adjacencyList, maxColors) == false)
                        {
                            color[start] = -1;
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
    bool
    graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adjacencyList = createAdjacencyList(edges, v);
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (graphColoringHelper(i, color, adjacencyList, m) == false)
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
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    int m = 2, v = 3;
    cout << sol.graphColoring(v, edges, m) << "\n"; // 0
    edges = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};
    m = 3, v = 4;
    cout << sol.graphColoring(v, edges, m) << "\n"; // 1
    return 0;
}
