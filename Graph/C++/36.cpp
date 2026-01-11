#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool dfs(int src, vector<int> &color, vector<vector<int>> &adjacencyList, int maxColor)
    {
        for (int clr = 0; clr < maxColor; clr++)
        {
            bool isSafe = true;
            for (int neighbour : adjacencyList[src])
            {
                if (color[neighbour] == clr)
                {
                    isSafe = false;
                    break;
                }
            }
            if (isSafe)
            {
                color[src] = clr;
                for (int neighbour : adjacencyList[src])
                {
                    if (color[neighbour] == -1)
                    {
                        if (dfs(neighbour, color, adjacencyList, maxColor) == false)
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
    bool graphColoring(int v, vector<vector<int>> edges, int m)
    {
        vector<int> color(v, -1);
        vector<vector<int>> adjacencyList(v);
        for (vector<int> i : edges)
        {
            adjacencyList[i[0]].push_back(i[1]);
            adjacencyList[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, color, adjacencyList, m) == false)
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
    cout << sol.graphColoring(4, {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}}, 3) << "\n"; // 1
    cout << sol.graphColoring(3, {{0, 1}, {1, 2}, {0, 2}}, 2) << "\n";                 // 0
    return 0;
}
