#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i : arr)
        {
            q.push(i);
            if (q.size() > k)
            {
                q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    arr = sol.kLargest(arr, 3);
    for (int i : arr)
        cout << i << " ";
    return 0;
}
