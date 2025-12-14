#include <vector>
#include <iostream>
#include <tuple>
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
    int spanningTree(int v, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adjacencyList = createAdjacencyList(edges, v);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        vector<int> visited(v, 0), mst;
        minHeap.push({0, 0, -1});
        int sum = 0;
        while (!minHeap.empty())
        {
            int weight = get<0>(minHeap.top()), node = get<1>(minHeap.top()), parent = get<2>(minHeap.top());
            minHeap.pop();
            if (visited[node] == 1)
            {
                continue;
            }
            visited[node] = 1;
            sum += weight;
            mst.push_back(node);
            for (pair<int, int> neighbour : adjacencyList[node])
            {
                if (visited[neighbour.first] != 1)
                {
                    minHeap.push({neighbour.second, neighbour.first, node});
                }
            }
        }
        for (int i : mst)
        {
            cout << i << " ";
        }
        cout << "\n";
        return sum;
    }
};
int main()
{
    Solution sol;
    int v = 3;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    cout << sol.spanningTree(v, edges) << "\n";
    v = 2;
    edges = {{0, 1, 5}};
    cout << sol.spanningTree(v, edges) << "\n";
    return 0;
}
