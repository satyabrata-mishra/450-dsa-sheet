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
    bool isBipartiteHelper(int start, vector<vector<int>> &adjList, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adjList[node])
            {
                if (color[neighbor] == -1)
                {
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList = createAdjacencyList(edges, v);
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!isBipartiteHelper(i, adjList, color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};