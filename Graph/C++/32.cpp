#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (vector<int> i : flights)
        {
            adjacencyList[i[0]].push_back({i[1], i[2]});
        }
        queue<tuple<int, int, int>> q; // stops,node, distance
        vector<int> distance(n, INT32_MAX);
        q.push({0, src, 0});
        distance[src] = 0;
        while (q.empty() == false)
        {
            int stops = get<0>(q.front()), curNode = get<1>(q.front()), curDistance = get<2>(q.front());
            q.pop();
            if (stops > k)
            {
                break;
            }
            for (pair<int, int> neighbour : adjacencyList[curNode])
            {
                if (neighbour.second + curDistance < distance[neighbour.first])
                {
                    distance[neighbour.first] = neighbour.second + curDistance;
                    q.push({stops + 1, neighbour.first, distance[neighbour.first]});
                }
            }
        }
        return distance[dst] == INT32_MAX ? -1 : distance[dst];
    }
};
int main()
{
    Solution sol;
    cout << sol.findCheapestPrice(4, {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}}, 0, 3, 1) << "\n"; // 700
    cout << sol.findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 1) << "\n";                           // 200
    cout << sol.findCheapestPrice(3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 0) << "\n";                           // 500
    return 0;
}
