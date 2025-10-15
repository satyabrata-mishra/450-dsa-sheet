#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        vector<double> ans;
        for (int x : arr)
        {
            maxHeap.push(x);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            if (minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if (minHeap.size() == maxHeap.size())
            {
                ans.push_back(((double)minHeap.top() + maxHeap.top()) / 2);
            }
            else
            {
                ans.push_back(maxHeap.top());
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> ans = sol.getMedian(arr);
    for (double i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {2, 2, 2, 2};
    ans = sol.getMedian(arr);
    for (double i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
