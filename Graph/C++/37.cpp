#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        src--; // convert to 0-based
        dst--;

        vector<vector<pair<int, int>>> adjacencyList(n);
        for (auto &i : edges)
        {
            adjacencyList[i[0] - 1].push_back({i[1] - 1, 0});
            adjacencyList[i[1] - 1].push_back({i[0] - 1, 1});
        }

        vector<int> dist(n, INT32_MAX);
        dist[src] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            minHeap;

        minHeap.push({0, src});

        while (!minHeap.empty())
        {
            auto currNode = minHeap.top();
            minHeap.pop();

            int currDist = currNode.first;
            int u = currNode.second;

            for (auto &neighbour : adjacencyList[u])
            {
                int v = neighbour.first;
                int wt = neighbour.second;

                if (dist[v] > currDist + wt)
                {
                    dist[v] = currDist + wt;
                    minHeap.push({dist[v], v});
                }
            }
        }
        return (dist[dst] == INT32_MAX ? -1 : dist[dst]);
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {3, 2}};
    cout << sol.minimumEdgeReversal(edges, 3, 1, 3) << "\n"; // 1
    edges = {{1, 2}, {2, 3}, {3, 4}};
    cout << sol.minimumEdgeReversal(edges, 4, 1, 4) << "\n"; // 0
    return 0;
}
