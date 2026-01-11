#include <vector>
#include <iostream>
#include <stack>
using namespace std;
vector<vector<int>> createAdjacencyList(int v, vector<vector<int>> &astronaut)
{
    vector<vector<int>> adjacencyList(v, vector<int>());
    for (vector<int> i : astronaut)
    {
        adjacencyList[i[0]].push_back(i[1]);
        adjacencyList[i[1]].push_back(i[0]);
    }
    return adjacencyList;
}
int dfs(int src, vector<bool> &visited, vector<vector<int>> &adjacencyList)
{
    visited[src] = true;
    int size = 1;
    for (int neighbour : adjacencyList[src])
    {
        if (visited[neighbour] == false)
        {
            size += dfs(neighbour, visited, adjacencyList);
        }
    }
    return size;
}
int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<vector<int>> adj = createAdjacencyList(n, astronaut);
    vector<bool> visited(n, false);

    vector<int> componentSizes;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            componentSizes.push_back(dfs(i, visited, adj));
        }
    }
    long long result = 0;
    long long remaining = n;

    for (int size : componentSizes)
    {
        remaining -= size;
        result += (long long)size * remaining;
    }
    return result;
}
int main()
{
    cout << journeyToMoon(4, {{1, 2}, {2, 3}}) << "\n";         // 3
    cout << journeyToMoon(5, {{0, 1}, {2, 3}, {0, 4}}) << "\n"; // 6
    cout << journeyToMoon(4, {{0, 2}}) << "\n";                 // 5
    return 0;
}
