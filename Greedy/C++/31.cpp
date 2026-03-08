#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> arr)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
        int ans = 0;
        while (minHeap.size() > 1)
        {
            int rope1 = minHeap.top();
            minHeap.pop();
            int rope2 = minHeap.top();
            minHeap.pop();
            ans += rope1 + rope2;
            minHeap.push(rope1 + rope2);
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.minCost({4, 3, 2, 6}) << "\n";    // 29
    cout << sol.minCost({4, 2, 7, 6, 9}) << "\n"; // 62
    cout << sol.minCost({10}) << "\n";            // 0
    return 0;
}
