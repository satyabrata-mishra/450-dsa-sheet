#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> adjacencyList(V, vector<int>());
        for (pair<int, int> i : edges)
        {
            adjacencyList[i.first].push_back(i.second);
            adjacencyList[i.second].push_back(i.first);
        }
        return adjacencyList;
    }
};
int main()
{
    Solution sol;
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 4});
    edges.push_back({4, 1});
    edges.push_back({4, 3});
    edges.push_back({1, 3});
    edges.push_back({1, 2});
    edges.push_back({3, 2});
    vector<vector<int>> adjacencyList = sol.printGraph(5, edges);
    for (vector<int> i : adjacencyList)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
