#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    vector<vector<pair<int, int>>> createAdjacencyList(vector<vector<int>> &edges, int v)
    {
        vector<vector<pair<int, int>>> adjacencyList(v);
        for (vector<int> i : edges)
        {
            adjacencyList[i[0]].push_back({i[1], i[2]});
            adjacencyList[i[1]].push_back({i[0], i[2]});
        }
        return adjacencyList;
    }

public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adjacencyList = createAdjacencyList(edges, v);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist(v, INT32_MAX);
        dist[src] = 0;
        minHeap.push({0, src});
        while (!minHeap.empty())
        {
            pair<int, int> minEle = minHeap.top();
            minHeap.pop();
            for (pair<int, int> neighbour : adjacencyList[minEle.second])
            {
                if (minEle.first + neighbour.second < dist[neighbour.first])
                {
                    dist[neighbour.first] = minEle.first + neighbour.second;
                    minHeap.push({dist[neighbour.first], neighbour.first});
                }
            }
        }
        return dist;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    int src = 2, v = 3;
    vector<int> ans = sol.dijkstra(v, edges, src);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    src = 0, v = 5;
    ans = sol.dijkstra(v, edges, src);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
