#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> stack;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack.empty() && stack.top() >= arr[i])
            {
                stack.pop();
            }
            if (stack.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(stack.top());
            }
            stack.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {4, 8, 5, 2, 25};
    arr = sol.nextSmallerEle(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {13, 7, 6, 12};
    arr = sol.nextSmallerEle(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {4, 1};
    arr = sol.nextSmallerEle(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
