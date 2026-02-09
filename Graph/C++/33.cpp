#include <iostream>
#include <vector>
#include <string>
using namespace std;
void dfs(int src, int &timer, vector<vector<int>> &adjacencyList, vector<int> &visited, vector<int> &intime, vector<int> &outtime)
{
    intime[src] = timer++;
    visited[src] = 1;
    for (int neighbour : adjacencyList[src])
    {
        if (visited[neighbour] == false)
        {
            dfs(neighbour, timer, adjacencyList, visited, intime, outtime);
        }
    }
    outtime[src] = timer++;
}
void oliverTheGame(int n, vector<vector<int>> edges, vector<vector<int>> queryList)
{
    vector<vector<int>> adjacencyList(n);
    for (vector<int> e : edges)
    {
        e[0]--;
        e[1]--;
        adjacencyList[e[0]].push_back(e[1]);
        adjacencyList[e[1]].push_back(e[0]);
    }
    vector<int> visited(n, 0), intime(n), outtime(n);
    int timer = 0;
    dfs(0, timer, adjacencyList, visited, intime, outtime);
    for (vector<int> query : queryList)
    {
        if (query[0] == 0)
        {
            intime[query[1] - 1] <= intime[query[2] - 1] && outtime[query[1] - 1] >= outtime[query[2] - 1] ? cout << "YES\n" : cout << "NO\n";
        }
        else
        {
            intime[query[1] - 1] >= intime[query[2] - 1] && outtime[query[1] - 1] <= outtime[query[2] - 1] ? cout << "YES\n" : cout << "NO\n";
        }
    }
}
int main()
{
    int n = 9;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 6}, {2, 7}, {6, 9}, {7, 8}, {3, 4}, {3, 5}};
    int noOfQueries = 5;
    vector<vector<int>> query = {{0, 2, 8}, {1, 2, 8}, {1, 6, 5}, {0, 6, 5}, {1, 9, 1}};
    oliverTheGame(n, edges, query);
    return 0;
}
