#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    bool dfs(int src, vector<vector<int>> &adjacencyList, vector<int> &visited)
    {
        visited[src] = 1;
        for (int neighbour : adjacencyList[src])
        {
            if (visited[neighbour] == 1)
            {
                return false;
            }
            if (visited[neighbour] == 0)
            {
                if (dfs(neighbour, adjacencyList, visited) == false)
                {
                    return false;
                }
            }
        }
        visited[src] = 2;
        return true;
    }

public:
    bool canFinish(int n, vector<vector<int>> prerequisites)
    {
        vector<vector<int>> adjacencyList(n);
        for (vector<int> i : prerequisites)
        {
            adjacencyList[i[0]].push_back(i[1]);
        }
        vector<int> visited(n);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (dfs(i, adjacencyList, visited) == false)
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
    cout << sol.canFinish(4, {{2, 0}, {2, 1}, {3, 2}}) << "\n"; // 1
    cout << sol.canFinish(3, {{0, 1}, {1, 2}, {2, 0}}) << "\n"; // 0
    return 0;
}
