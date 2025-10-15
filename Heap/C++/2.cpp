#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> maxOfSubarrays(vector<int> &arr, int k)
    {
        priority_queue<pair<int, int>> maxHeap;
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            maxHeap.push({arr[i], i});
            while (!maxHeap.empty() && maxHeap.top().second <= i - k)
            {
                maxHeap.pop();
            }
            if (i >= k - 1)
            {
                ans.push_back(maxHeap.top().first);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    arr = sol.maxOfSubarrays(arr, 3);
    arr = {5, 1, 3, 4, 2};
    arr = sol.maxOfSubarrays(arr, 1);
    return 0;
}
