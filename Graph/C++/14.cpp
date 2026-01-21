#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> minimumTime(int v, vector<vector<int>> edges, int e)
    {
        vector<int> indegree(v + 1, 0);
        unordered_map<int, vector<int>> adjacencyList(v + 1);
        for (vector<int> i : edges)
        {
            ++indegree[i[1]];
            adjacencyList[i[0]].push_back(i[1]);
        }
        queue<int> q;
        vector<int> ans(v, 0);
        for (int i = 1; i <= v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans[i - 1] = 1;
            }
        }
        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();
            for (int neighbour : adjacencyList[currNode])
            {
                if (indegree[neighbour] > 0)
                {
                    --indegree[neighbour];
                    if (indegree[neighbour] == 0)
                    {
                        q.push(neighbour);
                        ans[neighbour - 1] = ans[currNode - 1] + 1;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.minimumTime(10, {{1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 8}, {2, 9}, {3, 6}, {4, 6}, {4, 8}, {5, 8}, {6, 7}, {7, 8}, {8, 10}}, 13);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n"; //{1,1,2,2,2,3,4,5,2,6}
    ans = sol.minimumTime(7, {{1, 2}, {2, 3}, {2, 4}, {2, 5}, {3, 6}, {4, 6}, {5, 7}}, 7);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n"; //{1,2,3,3,3,4,4}
    return 0;
}
