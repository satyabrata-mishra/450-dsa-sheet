#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        vector<int> ans;
        queue<int> q;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] < 0)
                q.push(i);
            if (i >= k - 1)
            {
                while (!q.empty() && q.front() < i - k + 1)
                    q.pop();
                if (!q.empty())
                    ans.push_back(arr[q.front()]);
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    arr = sol.firstNegInt(arr, k);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {12, -1, -7, 8, -15, 30, 16, 28};
    k = 3;
    arr = sol.firstNegInt(arr, k);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    arr = {12, 1, 3, 5};
    k = 3;
    arr = sol.firstNegInt(arr, k);
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}
